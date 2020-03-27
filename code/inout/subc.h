/******************************************************
 * File Name   : subc.h
 * Description
 *    This is a header file for the subc program.
 ******************************************************/

#ifndef __SUBC_H__
#define __SUBC_H__

#include <stdio.h>
#include <strings.h>



static int func_cnt = 0;
static int string_cnt = 0;
static int if_cnt = 0;
static int while_cnt = 0;
static int for_cnt = 0;




typedef struct w_s {
	int cnt;
	struct w_s *prev;
} w_s;

static w_s *while_stack = NULL;


typedef struct id {
//int tokenType;
	char *name;
	int lextype;
//int count;
} id;


typedef struct ste {
	struct id	*name;
	struct decl	*decl;
	struct ste	*prev;
} ste;

typedef struct decl {
	int				declclass;
	struct decl		*type;
	int				value;
	float			real_value;
	struct ste		*formals;
	struct decl		*returntype;
	int				typeclass;
	struct decl		*elementvar;
	int				num_index;
	struct ste		*fieldlist;
	struct decl		*ptrto;
	int				size;
	struct scope    *scope;
	struct decl		*next;
} decl;


typedef struct scope {
	//struct ste *point;
	int level;
	struct scope *prev;
} scope;

void push_scope();
ste *pop_scope();

/* For hash table */
decl *maketypedecl(int type);
decl *makevardecl(decl *type_obj);
decl *makearraydecl(int num_index, decl *var);
decl *makeconstdecl(decl *type/*int value*/);
decl *makeptrdecl(decl *type_obj);
decl *makestructdecl(ste *fields);
decl *makeprocdecl();
decl *makenumconstdecl(decl *type, int value);

decl *arrayaccess (struct decl *arrayptr);
decl *structaccess (decl *structptr, id *fieldid);
decl *structptraccess (decl *structptrptr, id *fieldid);


int check_redecl(id* id_ptr);
int check_int(decl* int_ptr);
int check_char(decl* char_ptr);
int check_ptr(decl* ptr_ptr);
int check_var(decl* var_ptr);
int check_isproc(decl *proc);

decl *check_functioncall(decl *procptr, decl *actuals);

void check_returntype(decl *re);
void cascade_struct(ste* fields);
decl *find(char *name, int length);

id *enter(int tokenType, char *name, int length);


//int check_isvar(decl *var);
int check_compatible(decl *var1, decl *var2);

void declare(id *id_obj, decl *decl_obj);
void push_declare(ste *formals);

int read_line();
//char *read_file();

void error (char* message);

void jump(decl *decl_ptr); 


static ste *symbol_table = NULL;
static scope *scope_pointer = NULL;
static scope *zero_scope = NULL;
static int scope_level = 0;
static int Lglob = 0;
/*
static int func_cnt = 0;
static int string_cnt = 0;
static int if_cnt = 0;
static int while_cnt = 0;
static int for_cnt = 0;
*/




#endif
