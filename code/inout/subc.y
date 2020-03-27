%{
/*
 * File Name   : subc.y
 * Description : a skeleton bison input
 */
#include <string.h>
#include "subc.h"
#include "subc.tab.h"

#define Int 0
#define Char 1
#define Array 2
#define Ptr 3
#define Struct 4
#define Null 5
#define Void 6


int    yylex ();
int    yyerror (char* s);

%}

/* yylval types */
%union {
	int				intVal;
	double			floatval;
	char			*stringVal;
	struct id		*idptr;
	struct decl		*declptr;
	struct ste		*steptr;
}

%type		<declptr>	TYPE type_specifier struct_specifier unary binary expr or_expr or_list and_expr and_list args expr_e const_expr
%type		<intVal>	pointers def_list local_defs if_mid
%type		<idptr>		func_decl

%nonassoc	<idptr>		ID 
%nonassoc	<intVal>	INTEGER_CONST
%nonassoc	<stringVal>	CHAR_CONST STRING_CONST STRING

/* Precedences and Associativities */

%nonassoc WRITE_STRING WRITE_INT
%left	','  
%right	'='    
%left	LOGICAL_OR
%left	LOGICAL_AND
%left	'&' '*'
%left	EQUOP           
%left	RELOP
%left	'+' '-' 
%right	'!' INCOP DECOP 
%left '[' '(' ']' ')' '.' STRUCTOP
%right THEN ELSE



/* Token and Types */
%token INT CHAR STRUCT RETURN IF ELSE WHILE FOR BREAK CONTINUE LOGICAL_OR LOGICAL_AND INCOP DECOP STRUCTOP VOID CHAR_CONST ID INTEGER_CONST Nu




%%

    /*fill in here*/

program
		: {     
			printf("\tshift_sp 1\n");
			printf("\tpush_const EXIT\n");
			printf("\tpush_reg fp\n");
		   	printf("\tpush_reg sp\n");
		   	printf("\tpop_reg fp\n");
			printf("\tjump main\n");
			printf("EXIT:\n");
			printf("\texit\n");
		} ext_def_list {
			printf("Lglob.	data %d\n", Global_offset());
		}
		;

ext_def_list
		: ext_def_list ext_def
		| /* empty */
		;

ext_def
		: type_specifier pointers ID ';' { 
			if($2) 
				declare($3, makevardecl(makeptrdecl($1)));
			else 
				declare($3, makevardecl($1)); 
			//Lglob_inc(1);
		}
		| type_specifier pointers ID '[' INTEGER_CONST ']' ';' {

			if($2) 
				declare($3, makeconstdecl(makearraydecl(yylval.intVal,makevardecl(makeptrdecl($1)))));
			else 
				declare($3, makeconstdecl(makearraydecl(yylval.intVal,makevardecl($1))));
			//Lglob_inc(yylval.intVal);
		}
		| func_decl ';' /* forward func */
		| type_specifier ';' { }  /* only for struct */
		| func_decl compound_stmt { 
			pop_scope(); 
			printf("%s_final:\n", $1->name);
			printf("\tpush_reg fp\n");
			printf("\tpop_reg sp\n");
			printf("\tpop_reg fp\n");
			printf("\tpop_reg pc\n");
			printf("%s_end:\n", $1->name);
		}; /* DEFINE func */

type_specifier
		: TYPE {$$=$1;}
		| VOID {$$=find("void", 4);}
		| struct_specifier { $$=$1;};
TYPE 
		: INT  {$$=find("int", 3);}
		| CHAR {$$=find("char",4);};

struct_specifier
		: STRUCT ID {
			$<declptr>$=find($2->name, strlen($2->name));

			push_scope();
		} 
		'{' def_list '}' {
			///????/////
			ste *fields = pop_scope();

			cascade_struct(fields);

			declare($2, makestructdecl(fields));
			$$ = find($2->name, strlen($2->name));
		}
		| STRUCT ID {
			$$ = find($2->name, strlen($2->name));
		};

func_decl
		: type_specifier pointers ID '(' ')' 
		{
			struct decl *proc_decl = makeprocdecl();
			declare($3, proc_decl);
			push_scope();

			struct id *returnid = enter(0, "returnid", 8);
			if($2==1)	 declare(returnid, makevardecl(makeptrdecl($1)));
			else		 declare(returnid, makevardecl($1));

			struct ste *formals;
			formals = pop_scope();
			proc_decl->returntype = formals->decl;
			proc_decl->formals = NULL;
			push_scope();
			push_declare(formals);  
			printf("%s:\n", $3->name);
			$$ = $3;
		}
		| type_specifier pointers ID '(' VOID ')'
		{
			struct decl *proc_decl = makeprocdecl();
			declare($3, proc_decl);
			push_scope();

			struct id *returnid = enter(0, "returnid", 8);
			if($2==1)	 declare(returnid, makevardecl(makeptrdecl($1)));
			else		 declare(returnid, makevardecl($1));

			struct ste *formals;
			formals = pop_scope();
			proc_decl->returntype = formals->decl;
			proc_decl->formals = NULL;
			push_scope();
			push_declare(formals);  
			printf("%s:\n", $3->name);
			$$ = $3;
		}
		| type_specifier pointers ID '(' 
		{
			struct decl *proc_decl = makeprocdecl();
			declare($3, proc_decl);
			push_scope();

			struct id *returnid = enter(0, "returnid", 8);
			if($2==1)	 declare(returnid, makevardecl(makeptrdecl($1)));
			else		 declare(returnid, makevardecl($1));
			$<declptr>$ = proc_decl;
		}
		param_list ')' {
			struct ste *formals;
			struct decl *proc_decl = $<declptr>5;
			formals = pop_scope();
			
			proc_decl->returntype = get_returnid(formals);
			proc_decl->formals = formals;
			push_scope();
			push_declare(formals);  

			printf("%s:\n", $3->name);
			$$=$3;
		};

pointers
		: '*'		  {$$=1;}
		| /* empty */ {$$=0;}

param_list  /* list of formal parameter declaration */
		: param_decl
		| param_list ',' param_decl

param_decl  /* formal parameter declaration */

		: type_specifier pointers ID { 
			if($2) 
				declare($3, makevardecl(makeptrdecl($1)));
			else 
				declare($3, makevardecl($1)); 
		}
		| type_specifier pointers ID '[' INTEGER_CONST ']' {
			if($2) 
				declare($3, makeconstdecl(makearraydecl(yylval.intVal,makevardecl(makeptrdecl($1)))));
			else 
				declare($3, makeconstdecl(makearraydecl(yylval.intVal,makevardecl($1))));
		}

def_list    /* list of definitions, definition can be type(struct), variable, function */
		: def_list def	{$$=1;}
		| /* empty */	{$$=0;}

def
		: type_specifier pointers ID ';' { 
			if($2) 
				declare($3, makevardecl(makeptrdecl($1)));
			else 
				declare($3, makevardecl($1)); 
		}
		| type_specifier pointers ID '[' INTEGER_CONST ']' ';' {
			if($2) 
				declare($3, makeconstdecl(makearraydecl(yylval.intVal,makevardecl(makeptrdecl($1)))));
			else 
				declare($3, makeconstdecl(makearraydecl(yylval.intVal,makevardecl($1))));
		}
		| type_specifier ';'  /* only struct def */
		| func_decl ';'		 /* forward func not use */


compound_stmt
		: '{' local_defs { 
			if($2==1) {
				if(Local_offset()-Local_args() > 0)
					printf("\tshift_sp %d\n", Local_offset()-Local_args());
				func_start();
			}
		} stmt_list '}';

local_defs  /* local definitions, of which scope is only inside of compound statement */
		:	def_list {$$=$1;}

stmt_list
		: stmt_list stmt
		| /* empty */

if_mid	: IF '(' expr ')' { 
			$$ = if_cnt++;
			printf("\tbranch_false ELSE_%d\n", $$);
		};
stmt
		: expr ';'
		| compound_stmt
		| RETURN ';'
		| RETURN { 
			/*
			printf("\tpush_reg fp\n");
			printf("\tpush_const -1\n");
			printf("\tadd\n");
			printf("\tpush_const -1\n");
			printf("\tadd\n");
			*/
			func_return();
		} expr ';' {
			if($3->type->typeclass != 4) {
				if($3->declclass==0) printf("\tfetch\n");
				printf("\tassign\n");
			}
			else { //Struct
				printf("\tassign\n");
			}
		}
		| ';'

		| if_mid stmt %prec THEN {
			printf("ELSE_%d:\n", $1 );
		} 
		| if_mid stmt ELSE {
			printf("\tjump AFTER_%d\n", $1 );
			printf("ELSE_%d:\n", $1 );
		} stmt {
			printf("AFTER_%d:\n", $1 );
		}
		| WHILE { 
			$<intVal>$ = while_cnt;
			set_while_stack(while_cnt);
			while_cnt++;
			printf("WHILE_START_%d:\n", $<intVal>$);
		}
		'(' expr ')' {  
			printf("\tbranch_false WHILE_END_%d\n", $<intVal>2);
		} 
		stmt { 
			printf("\tjump WHILE_START_%d\n", $<intVal>2);
			printf("WHILE_END_%d:\n", $<intVal>2);
			free_while_stack();
		}
		| FOR '(' expr_e ';' {
			$<intVal>$ = while_cnt;
			set_while_stack(while_cnt);
			while_cnt++;
			printf("FOR_CHECK_%d:\n", $<intVal>$);

		} expr_e ';' {
			printf("\tbranch_false WHILE_END_%d\n", $<intVal>5);
			printf("\tjump FOR_STMT_%d\n", $<intVal>5);
			printf("WHILE_START_%d:\n", $<intVal>5);

		} expr_e ')' {
			printf("\tjump FOR_MID_%d\n", $<intVal>5);
			printf("FOR_STMT_%d:\n", $<intVal>5);

		}stmt {
			printf("\tjump WHILE_START_%d\n", $<intVal>5);
			printf("FOR_MID_%d:\n", $<intVal>5);
			printf("\tjump FOR_CHECK_%d\n", $<intVal>5);
			printf("WHILE_END_%d:\n", $<intVal>5);
			free_while_stack();
		}
		| BREAK ';' {
			printf("\tjump WHILE_END_%d\n", get_while_stack());
		}
		| CONTINUE ';' {
			printf("\tjump WHILE_START_%d\n", get_while_stack());
		}
		| WRITE_STRING '(' STRING {
			printf("str_%d. string ", string_cnt);
			printf("%s\n", $3);
			printf("\tpush_const str_%d\n", string_cnt++);
			printf("\twrite_string\n");

		} ');' {}
		| WRITE_INT '(' expr ');'  {
			if($3->declclass==0) printf("\tfetch\n"); //VAR
			printf("\twrite_int\n");
		}




expr_e
		: expr {$$=$1;}
		| /* empty */

const_expr
		: expr {$$=$1;}

expr
		: unary { /* ASSIGN */
			if($1->type->typeclass != 4) { // not struct
				printf("\tpush_reg sp\n");
				printf("\tfetch\n");
			}			

		} '=' expr { 
			if($1->type->typeclass != 4) {
				if($4->declclass==0) printf("\tfetch\n"); //VAR
				printf("\tassign\n");
				printf("\tfetch\n");
				printf("\tshift_sp -1\n");
			}
			else {
				for(int i=0; i < $1->size; i++) {
					printf("\tpush_reg sp\n"); //for VAR
					printf("\tpush_const -1\n");
					printf("\tadd\n");
					printf("\tfetch\n");
					printf("\tpush_const %d\n", i);
					printf("\tadd\n");

					printf("\tpush_reg sp\n"); //for VAL
					printf("\tpush_const -1\n");
					printf("\tadd\n");
					printf("\tfetch\n");
					printf("\tpush_const %d\n", i);
					printf("\tadd\n");

					printf("\tfetch\n");
					printf("\tassign\n");
				}
				printf("\tshift_sp -2\n");
			}
		}
		| or_expr {$$ = $1;}

or_expr
		: or_list {$$ = $1;}

or_list 
		: or_list LOGICAL_OR {
			if($1->declclass==0) printf("\tfetch\n");
		} and_expr  {
			if($4->declclass==0) printf("\tfetch\n");
			printf("\tor\n");
			$$=makenumconstdecl(find("int",3), 0);
		}
		| and_expr {$$ = $1;}

and_expr
		: and_list {$$ = $1;}

and_list
		: and_list LOGICAL_AND {
			if($1->declclass==0) printf("\tfetch\n");
		} binary {
			if($4->declclass==0) printf("\tfetch\n");
			printf("\tand\n");
			$$=makenumconstdecl(find("int",3), 0);
		}
		| binary {
			$$ = $1; 
		}

binary
		: binary RELOP { 
			if($1->declclass==0) printf("\tfetch\n");
			if(!strcmp(yylval.stringVal, ">"))
				$<intVal>$ = 0;
			if(!strcmp(yylval.stringVal, ">="))
				$<intVal>$ = 1;
			if(!strcmp(yylval.stringVal, "<"))
				$<intVal>$ = 2;
			if(!strcmp(yylval.stringVal, "<="))
				$<intVal>$ = 3;
		} binary { 
			if($4->declclass==0) printf("\tfetch\n");
			if($<intVal>3==0) printf("\tgreater\n");
			if($<intVal>3==1) printf("\tgreater_equal\n");
			if($<intVal>3==2) printf("\tless\n");
			if($<intVal>3==3) printf("\tless_equal\n");
			
			$$ = makenumconstdecl($1,0);
		}
		| binary EQUOP { 
			if($1->declclass==0) printf("\tfetch\n");
			if(!strcmp(yylval.stringVal, "=="))
				$<intVal>$ = 0;
			if(!strcmp(yylval.stringVal, "!="))
				$<intVal>$ = 1;
		} binary { 
			if($4->declclass==0) printf("\tfetch\n");
			if($<intVal>3==0) printf("\tequal\n");
			if($<intVal>3==1) printf("\tnot_equal\n");
			$$ = makenumconstdecl($1,0);
		}
		| binary '+' { 
			if($1->declclass==0) printf("\tfetch\n");
		} binary { 
			if($4->declclass==0) printf("\tfetch\n");
			printf("\tadd\n");
			$$ = makenumconstdecl($1,0);
		}
		| binary '-' { 
			if($1->declclass==0) printf("\tfetch\n");
		} binary { 
			if($4->declclass==0) printf("\tfetch\n");
			printf("\tsub\n");
			$$ = makenumconstdecl($1,0);
		}
		| unary %prec '=' { $$ = $1;}

unary
		: '(' expr ')'  {$$ = $2;}
		| '(' unary ')' {$$ = $2;}
		| INTEGER_CONST {
			$$ = makenumconstdecl($$=find("int", 3), yylval.intVal);
			printf("\tpush_const %d\n", yylval.intVal);
		}
		| CHAR_CONST {
			$$ = makenumconstdecl($$=find("char", 4), (yylval.intVal));
			printf("\tpush_const %d\n", (yylval.intVal));
		}
		/*| STRING */
		| ID { 
			$$ = find($1->name,strlen($1->name)); 
			if($$->declclass==0 || $$->declclass==1) { //VAR or CONST
				if($$->scope->level==0)
					printf("\tpush_const Lglob+%d\n", offset($$,1));
				else {
					printf("\tpush_reg fp\n");
					printf("\tpush_const %d\n", offset($$,0));
					printf("\tadd\n");

				}
			}
		}
		| '-' unary	%prec '!'  { 
			if($2->declclass==0) printf("\tfetch\n"); //VAR 
			printf("\tpush_const -1\n");
			printf("\tmul\n");
			$$=makenumconstdecl($2->type, 0); 
		}
		| '!' unary   { 
			if($2->declclass==0) printf("\tfetch\n"); //VAR 
			printf("\tpush_const 0\n");
			printf("\tnot_equal\n");
			$$=makenumconstdecl($2->type, 0); 
		}
		| unary INCOP { 
			$$ = makenumconstdecl($1->type, 0);
			printf("\tpush_reg sp\n");
			printf("\tfetch\n");
			printf("\tpush_reg sp\n");
			printf("\tfetch\n");
			printf("\tfetch\n");
			printf("\tpush_const 1\n");
			printf("\tadd\n");
			printf("\tassign\n");
			printf("\tfetch\n");
			printf("\tpush_const 1\n");
			printf("\tsub\n");
		}
		| unary DECOP  { 
			$$ = makenumconstdecl($1->type, 0);
			printf("\tpush_reg sp\n");
			printf("\tfetch\n");
			printf("\tpush_reg sp\n");
			printf("\tfetch\n");
			printf("\tfetch\n");
			printf("\tpush_const 1\n");
			printf("\tsub\n");
			printf("\tassign\n");
			printf("\tfetch\n");
			printf("\tpush_const 1\n");
			printf("\tadd\n");
		}
		| INCOP unary { 
			$$ = makenumconstdecl($2->type, 0);
			printf("\tpush_reg sp\n");
			printf("\tfetch\n");
			printf("\tpush_reg sp\n");
			printf("\tfetch\n");
			printf("\tfetch\n");
			printf("\tpush_const 1\n");
			printf("\tadd\n");
			printf("\tassign\n");
			printf("\tfetch\n");
		}
		| DECOP unary { 
			$$ = makenumconstdecl($2->type, 0);
			printf("\tpush_reg sp\n");
			printf("\tfetch\n");
			printf("\tpush_reg sp\n");
			printf("\tfetch\n");
			printf("\tfetch\n");
			printf("\tpush_const 1\n");
			printf("\tsub\n");
			printf("\tassign\n");
			printf("\tfetch\n");
		} 
		| '&' unary	%prec '!'  { 
			$$ = makenumconstdecl($2->type, 0);
			//if VAR, then treat VAR as CONST makes addr
		}
		| '*' unary	%prec '!' { 
			$$=makevardecl($2->type->ptrto);
			printf("\tfetch\n");
		}
		| unary '[' expr ']' { 
			if($3->declclass==0) printf("\tfetch\n");
			$$ = arrayaccess($1); 
			printf("\tpush_const %d\n", $$->size);
			printf("\tmul\n");
			printf("\tadd\n");
		}  /* return VAR */
		| unary '.' ID	     { 
			$$ = structaccess($1,$3); 
		} /* return Field */
		| unary STRUCTOP ID  { 
			$$ = structptraccess($1,$3); 
		}
		| unary '(' {
			//printf("\tshift_sp %d\n", $1->returntype->type->size);
			printf("\tshift_sp 1\n");
			printf("\tpush_const label_%d\n", ++func_cnt);
			printf("\tpush_reg fp\n");
		} args ')' {
			printf("\tpush_reg sp\n");
			printf("\tpush_const -%d\n", arg_size($1));
			printf("\tadd\n");
			printf("\tpop_reg fp\n");
			jump($1);
			
			if(check_ptr($1->returntype)) $$ = $1->returntype;
			else $$ = makenumconstdecl($1->returntype->type, 0); 
		}			
		| unary '(' ')' { 
			printf("\tshift_sp 1\n");
			printf("\tpush_const label_%d\n", ++func_cnt);
			printf("\tpush_reg fp\n");

			printf("\tpush_reg sp\n");
			printf("\tpop_reg fp\n");
			jump($1);

			if(check_ptr($1->returntype)) $$ = $1->returntype;
			else $$ = makenumconstdecl($1->returntype->type, 0); 
		}
		| Nu {$$=find("null", 4); }
args    
		: expr { 
			if($1->declclass==0) { //VAR
				if($1->type->typeclass==4) { //Struct
					for(int i=1; i<$1->size; i++) {
						printf("\tpush_reg sp\n");
						printf("\tpush_const -%d\n", i-1);
						printf("\tadd\n");
						printf("\tfetch\n");

						printf("\tpush_const %d\n", i);
						printf("\tadd\n");
						printf("\tfetch\n");
					}
					printf("\tshift_sp -%d\n", $1->size-1);
					printf("\tfetch\n");
					printf("\tshift_sp %d\n", $1->size-1);
				}
				else printf("\tfetch\n");  //VAR only
			}
		}
		| args ',' expr { 
			if($3->declclass==0) { //VAR
				if($3->type->typeclass==4) { //Struct
					for(int i=1; i<$3->size; i++) {
						printf("\tpush_reg sp\n");
						printf("\tpush_const -%d\n", i-1);
						printf("\tadd\n");
						printf("\tfetch\n");

						printf("\tpush_const %d\n", i);
						printf("\tadd\n");
						printf("\tfetch\n");
					}
					printf("\tshift_sp -%d\n", $3->size-1);
					printf("\tfetch\n");
					printf("\tshift_sp %d\n", $3->size-1);

				}
				else printf("\tfetch\n");  //VAR only
			}
		} 



    
%%

/*  Additional C Codes here */


int    yyerror (char* s)
{
		fprintf(stderr, "%s\n", s);
}

