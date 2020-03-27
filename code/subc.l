%{
/*
 * File Name   : subc.l
 * Description : a skeleton flex input
 */
//#define INT 0
//#define CHAR 1
//#define ID 5
#include "subc.h"
#include "subc.tab.h"
#include <string.h>

static int comment_depth = 0;
static int lineno = 1;
static int error_flag = 1;
char *filename;

%}

/* regular definitions */
letter		[A-Za-z_]
digit		[0-9]
id		{letter}({letter}|{digit})*
integer_const	([1-9]{digit}*)|"0"
white-space		[ \t]+
special-char	\\[nt]

op "("|")"|"["|"]"|"{"|"}"|"->"|"."|"!"|"~"|"*"|"/"|"%"|"+"|"-"|"<<"|">>"|"&"|"^"|"|"|"?"|":"|"="|"&="|"^="|"|="|"<<="|">>="

%x COMMENT
%%
"int" 	{ return INT; }
"char"	{ return CHAR; }
"void"	{ return VOID; }
"NULL"	{ return Nu; }
"struct" 	{ return STRUCT;}
"return" { return RETURN; }
"if"     { return IF; }
"else"   { return ELSE; }
"while" { return WHILE; }
"for" { return FOR; }
"break" { return BREAK; }
"continue" { return CONTINUE; }
"||" { return LOGICAL_OR; }
"&&" { return LOGICAL_AND; }
"<"|"<="|">"|">=" { 
	yylval.stringVal = yytext;
	return RELOP; }
"=="|"!=" { 
	yylval.stringVal = yytext;
	return EQUOP; }
"++" { return INCOP; }
"--" { return DECOP; }
"->" { return STRUCTOP; }

"write_int" { return WRITE_INT; }
"write_string" { return WRITE_STRING; }

{id}	{
		   //struct id *entered  = enter(ID, yytext, yyleng);
		   //yylval.stringVal = entered->name;
		   //return entered->tokenType;
			yylval.idptr = enter(ID, yytext, yyleng);
			return yylval.idptr -> lextype;
		}
{integer_const}	{
		   yylval.intVal = atoi(yytext);
		   return INTEGER_CONST;
		}
\"({special-char}|[^\\\"\n])*\"	{
			/* String Variable */
		   yylval.stringVal = yytext;
		   return STRING;
		}
'({special-char}|[^\\'\n])'	{
			/* Character Variable */
		   yylval.intVal = yytext[1];
		   return CHAR_CONST;
		}
","		{ return ','; }
";"		{ return yytext[0]; }

"("|")"|"["|"]"|"{"|"}"|"->"|"."|"!"|"~"|"*"|"/"|"%"|"+"|"-"|"<<"|">>"|"&"|"^"|"|"|"?"|":"|"="|"&="|"^="|"|="|"<<="|">>=" { return yytext[0];}

{white-space}
(\/\/)(.*)(\n)	{ ++lineno; set_flag(1); }
<*>\n		    { ++lineno; set_flag(1); }
<INITIAL,COMMENT>"/*"	{
		   ++comment_depth;
		   BEGIN (COMMENT);
		}
<COMMENT>"*/"	   if(--comment_depth == 0) BEGIN (INITIAL);
<COMMENT>.		 {}


%%

int read_line()
{
   return lineno;
}
char *read_file() {
	return filename;
}
int read_flag() {
	return error_flag;
}
void set_flag(int setting) {
	error_flag = setting;
	return;
}

void init_type() {
	decl *inttype, *chartype, *nulltype, *voidtype;
	inttype = maketypedecl(0); //Int
	chartype = maketypedecl(1); //Char
	nulltype = maketypedecl(5); //Null
	voidtype = maketypedecl(6);
	declare(enter(ID, "int", 3), inttype);
	declare(enter(ID, "char", 4), chartype);
	declare(enter(ID, "null", 4), nulltype);
	declare(enter(ID, "void", 4), voidtype);
}

int main(int argc, char* argv[])
{
//   static char *keyword[] = { "int", "char", NULL };
//   static int tokentype[] = { TYPE, TYPE, 0 };
//   int i;
//   for(i = 0; keyword[i] != NULL; i++)
//      enter(tokentype[i], keyword[i], strlen(keyword[i]));

	init_type();

	if(argc >= 2) yyin = fopen(argv[1], "r");
	else yyin = stdin;
	
	if(!yyin) {
		printf("Can't open input stream!\n");
		exit(1);
	}
	
	filename = (char*) malloc(sizeof(char)*strlen(argv[1]));
	char *ptr = strtok(argv[1], "/");     

	while (ptr != NULL)          
	{
		memcpy(filename, ptr, sizeof(char)*strlen(ptr));
		ptr = strtok(NULL, "/");      
	}


	yyparse();
	fclose(yyin);
	return 0;
}
