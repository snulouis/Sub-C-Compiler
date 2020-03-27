/***************************************************************
 * File Name    : hash.c
 * Description
 *      This is an implementation file for the open hash table.
 *
 ****************************************************************/
#define VAR 0
#define CONST 1
#define FUNC 2
#define TYPE 3


#define Int 0
#define Char 1
#define Array 2
#define Ptr 3
#define Struct 4
#define Null 5
#define Void 6

#include "subc.h"
#include <stdlib.h>
#include <string.h>


#define  HASH_TABLE_SIZE   101

typedef struct nlist {
	struct nlist *next;
	id *data;
} nlist;

//static ste *symbol_table = NULL;
//static scope *scope_pointer = NULL;
//static int scope_level = 0;
//static Lglob = 0;

void Lglob_inc(int inc) {
	Lglob+=inc;
}
int get_Lglob() {
	return Lglob;
}

void push_scope() {
	scope *new_scope;
	new_scope = (scope*) malloc(sizeof(scope));
	new_scope->prev = scope_pointer;
	new_scope->level = ++scope_level;
	scope_pointer = new_scope;
}


ste *pop_scope() {
	--scope_level;
	scope_pointer = scope_pointer->prev;

	ste *result = symbol_table;
	ste *pivot = symbol_table;
	while(pivot!=NULL) {
		if((pivot->prev->decl->scope) != pivot->decl->scope) {
			symbol_table = pivot->prev;
			pivot->prev = NULL;
			return result; 
		}
		pivot = pivot->prev;
	}
	return NULL;
}

decl *maketypedecl(int type) {
	decl *type_decl;
	type_decl = (decl*) malloc(sizeof(decl));
	type_decl->declclass = TYPE;
	type_decl->typeclass = type;
	type_decl->size = 1;
	return type_decl;
}
decl *makevardecl(decl *type_obj) { //for int,char find TYPE and return  // 
	decl *var_decl;
	var_decl = (decl*) malloc(sizeof(decl));
	var_decl->declclass = VAR;
	var_decl->type = type_obj;
	var_decl->size = type_obj->size;
	return var_decl;
}
decl *makearraydecl(int num_index, decl *var) {
	decl *array_decl;
	array_decl = (decl*) malloc(sizeof(decl));

	array_decl->declclass = TYPE;
	array_decl->typeclass = Array;
	array_decl->num_index = num_index;
	array_decl->elementvar = var;
	array_decl->size = num_index * var->size;
	return array_decl;
}
decl *makeconstdecl(decl *type/*int value*/) {
	decl *const_decl;
	const_decl = (decl*) malloc(sizeof(decl));
	const_decl->declclass = CONST;
	//const_decl->value = value;
	const_decl->type = type;
	const_decl->size = type->size;
	return const_decl;
}
decl *makeptrdecl(decl *type_obj) {
	decl *ptr_decl;
	ptr_decl = (decl*) malloc(sizeof(decl));
	ptr_decl->declclass = TYPE;
	ptr_decl->typeclass = Ptr;
	ptr_decl->ptrto = type_obj;
	ptr_decl->size = 1;

	return ptr_decl;
}


ste *reverse_field(ste *fields) {
	ste *pivot = fields;
	ste *result = NULL;
	ste *temp = NULL;
	while(pivot!=NULL) { //find last
		temp = pivot->prev;

		pivot->prev = result;
		result = pivot;

		pivot = temp;
	}
	return result;
}

decl *makestructdecl(ste *fields) {
	decl *struct_decl;
	struct_decl = (decl*) malloc(sizeof(decl));
	struct_decl->declclass = TYPE;
	struct_decl->typeclass = Struct;


	struct_decl->size = 0;
	ste *pivot = fields;
	while(pivot!=NULL) {
		if(pivot->decl->declclass!=TYPE)
			struct_decl->size += pivot->decl->size;
		pivot = pivot->prev;
	}

	struct_decl->fieldlist = reverse_field(fields);
	//struct_decl->fieldlist = fields;


	return struct_decl;
}

decl *makeprocdecl() {
	decl *proc_decl;
	proc_decl = (decl*) malloc(sizeof(decl));
	proc_decl->declclass = FUNC;
	proc_decl->size = 0;

	return proc_decl;
}

decl *makenumconstdecl(decl *type, int value) {
	decl *const_decl;
	const_decl = (decl*) malloc(sizeof(decl));
	const_decl->declclass = CONST;
	const_decl->value = value;
	const_decl->type = type;
	const_decl->size = 0;
	return const_decl;
}




decl *arrayaccess (struct decl *arrayptr) { /* missed struct decl *indexptr*/
	if(arrayptr->declclass == CONST) {
		if(arrayptr->type->declclass == TYPE) {
			if(arrayptr->type->typeclass == Array) {
				return arrayptr->type->elementvar; //return VAR
			}
		}
	}
	return NULL; //not array type
}

decl *structaccess (decl *structptr, id *fieldid) {
	
	ste *pivot = structptr->type->fieldlist;
	int offset = 0;
	while(pivot!=NULL) {
		if(!strcmp(pivot->name->name, fieldid->name)) {
			//printf("\tpush_const %d\n", structptr->size - rev_offset - pivot->decl->size);
			printf("\tpush_const %d\n", offset);
			printf("\tadd\n");
			return pivot->decl; 
		}
		offset+=get_size(pivot->decl);
		pivot = pivot->prev;
	}
	return NULL;
}

decl *structptraccess (decl *structvar, id *fieldid) {

	ste *pivot = structvar->type->ptrto->fieldlist;
	int offset = 0;
	while(pivot!=NULL) {
		if(!strcmp(pivot->name->name, fieldid->name)) {
			printf("\tpush_const %d\n", offset);
			printf("\tadd\n");
			return pivot->decl; 
		}
		offset+=pivot->decl->size;
		pivot = pivot->prev;
	}
	return NULL;
}
/*
int check_isvar(decl *var) {
	if(var==NULL) error("LHS is not a variable");
	else if(var->declclass == VAR) {}
	else error("LHS is not a variable");
}
*/
int check_compatible(decl *var1, decl *var2) {
	if(var1 == NULL || var2==NULL) return 0;
	if(var1->type->typeclass == Ptr) {
		if(var2->typeclass==Null || (var2->type->typeclass == Ptr && var1->type->ptrto == var2->type->ptrto)) { return 1; }
		else return 0;//error("LHS and RHS are not same type");
	}
	else {
		if(var2->typeclass==Null) return 0;//error("RHS is not a const or variable");
		else { 
			if(var1->type->typeclass == var2->type->typeclass) { return 1; }
			else return 0; //error("LHS and RHS are not same type");
		}
	}
}


int check_redecl(id* id_ptr) {
	decl *find_decl = find(id_ptr->name, strlen(id_ptr->name));
	if(find_decl == NULL) { 
		return 0;
	}
	if(find_decl->scope->level != scope_level) {
		return 0;
	}
	error("redeclaration");
	return 1;
}

int check_int(decl* int_ptr) {
	if(int_ptr==NULL || int_ptr->type == NULL) return 0;
	if(int_ptr->type->typeclass==Int) return 1;
	else return 0;
}
int check_char(decl* char_ptr) {
	if(char_ptr==NULL || char_ptr->type == NULL) return 0;
	if(char_ptr->type->typeclass==Char) return 1;
	else return 0;
}
int check_ptr(decl* ptr_ptr) {
	if(ptr_ptr==NULL || ptr_ptr->type == NULL) return 0;
	if(ptr_ptr->type->typeclass==Ptr) return 1;
	else return 0;
}
int check_var(decl* var_ptr) {
	if(var_ptr==NULL) return 0;
	if(var_ptr->declclass==VAR) return 1;
	return 0;
}
int check_isproc(decl *proc) {
	if(proc->declclass!=FUNC) {
		error("not a function");
		return 0;
	}
	return 1;
}

decl *check_functioncall(decl *procptr, decl *actuals) {
	ste *formals = procptr->formals;

	while(formals != NULL && actuals != NULL) {

		if(check_compatible(formals->decl, actuals)) { }
		else break;
		
		formals = formals->prev;
		actuals = actuals->next;
	}
	if(formals == NULL && actuals == NULL) return procptr->returntype;
	else {
		error("actual args are not equal to formal args");
		return NULL;
	}

}


int arg_size(decl *procptr) {
	ste *formals = procptr->formals;
	int ans = 0;
	while(formals != NULL && strcmp(formals->name->name,"returnid")) {
		ans+=get_size(formals->decl);
		formals = formals->prev;
	}
	return ans; 
}



void check_returntype(decl *re) {
	ste *pivot = symbol_table;
	while(pivot!=NULL) {
		if(pivot->decl->declclass==FUNC) {
			if(re == NULL) {
				if(pivot->decl->returntype->type->typeclass == Void) { }//void func
				else error("incompatible return types");

			}
			else {
				if(check_compatible(pivot->decl->returntype, re)) { }
				else error("incompatible return types");
			}
			return;
		}
		pivot = pivot->prev;
	}
}


void cascade_struct(ste* fields) {
	ste *pivot = fields;
	while(pivot!=NULL) {
		if(pivot->decl->typeclass == Struct) {
			declare(pivot->name, pivot->decl);
		}
		pivot = pivot->prev;
	 }
}


decl* get_returnid(ste *ste_ptr) {
	ste *pivot = ste_ptr;
	ste *result;
	while(pivot->prev->prev!=NULL) {
		pivot = pivot->prev;
	}
	result = pivot->prev;
//	pivot->prev = NULL;
	return result->decl;
}

void jump(decl *decl_ptr) {
	ste *pivot = symbol_table;
	while(pivot!=NULL) {
		if(pivot->decl==decl_ptr) {
			printf("\tjump %s\n", pivot->name->name);
			printf("label_%d:\n", ++func_cnt);
			if(pivot->decl->returntype->type->typeclass==Void)
				printf("\tshift_sp -1\n");
			return;
		}
		pivot=pivot->prev;
	}
	return;
}

decl *find(char *name, int length) {
	ste *pivot = symbol_table;
	while(pivot!=NULL /*&& pivot->decl->scope == scope_pointer*/) { //all types are global
		if(!strcmp(name, pivot->name->name)) {
			return pivot->decl;
		}
		pivot = pivot->prev;
	}
	return NULL;
}

int get_size(decl* decl_ptr) {
	if(decl_ptr->declclass==TYPE) return 0; 
	else	return decl_ptr->size;
}

int offset(decl* decl_ptr, int Global) {
	if(Global) {
		ste *pivot = symbol_table;
		while(pivot!=NULL) { //all types are global
			if(pivot->decl == decl_ptr) {
				pivot = pivot->prev; //prev from itself
				int off = 0;
				while(pivot->prev!=NULL) { 
					off += get_size(pivot->decl);
					pivot = pivot->prev;
				}
				return off; 
			}
			pivot = pivot->prev;
		}
		return -999;
	}
	else { //LOCAL
		ste *pivot = symbol_table;
		while(pivot!=NULL) { 
			if(pivot->decl == decl_ptr) {
				pivot = pivot->prev; //exclude itself
				int off = 0; 
				while(pivot->prev->decl->scope==pivot->decl->scope) {  //except returnid
					off += get_size(pivot->decl);
					pivot = pivot->prev;
				}
				return off+1; //returnid is excluded by if statement
			}
			pivot = pivot->prev;
		}
		return -999;

	}
}

int Global_offset() {
	int off=0;
	ste *pivot = symbol_table;
	while(pivot!=NULL) { //all types are global
		if(pivot->decl->scope->level==0) {
			while(pivot!=NULL) { 
				off+=get_size(pivot->decl);
				pivot = pivot->prev;
			}
			return off;
		}
		pivot = pivot->prev;
	}
	return 0;
}

int Local_offset() {

	ste *pivot = symbol_table;
	int off = 0;
	while(pivot->prev->decl->scope==pivot->decl->scope) { 
		if(!strcmp(pivot->name->name, "returnid")) break;
		off+=get_size(pivot->decl);
		pivot = pivot->prev;
	}
	return off; 
}


int Local_args() {

	ste *pivot = symbol_table;
	int off = 0;
	while(pivot!=NULL) { 
		if(pivot->decl->declclass==FUNC) break;
		pivot = pivot->prev;
	}
	pivot = pivot->decl->formals;
	while(pivot!=NULL) {
		off+=get_size(pivot->decl);
		pivot=pivot->prev;
	}
	return off; 
}

void func_start() {
	ste *pivot = symbol_table;
	while(pivot!=NULL) { 
		if(pivot->decl->declclass==FUNC) {
			printf("%s_start:\n", pivot->name->name);
			return;
		}
		pivot = pivot->prev;
	}
}


void func_return() {
	ste *pivot = symbol_table;
	while(pivot!=NULL) { 
		if(pivot->decl->declclass==FUNC) {
			int off = pivot->decl->returntype->type->size;
			printf("\tpush_reg fp\n");
			printf("\tpush_const -%d\n", 2);
			printf("\tadd\n");
			return;
		}
		pivot = pivot->prev;
	}
}




int is_main() {
	ste *pivot = symbol_table;
	while(pivot!=NULL) { 
		if(pivot->decl->declclass==FUNC) {
			if(!(strcmp(pivot->name->name,"main"))) return 1;
			else return 0;
		}
		pivot = pivot->prev;
	}
}




id *enter(int tokenType, char *name, int length) { //just make id

	id *pivot = (id*) malloc(sizeof(id));
	pivot->name = (char*) malloc(sizeof(char)*length);
	memcpy(pivot->name, name, sizeof(char)*length); 
	pivot->lextype = tokenType;
	
	return pivot;

}

void declare(id *id_obj, decl *decl_obj) { // attach ID and DECL to STE

	ste *pivot;
	pivot = (ste*) malloc(sizeof(ste));
	pivot->prev = symbol_table;
	pivot->name = id_obj;

	if(scope_pointer==NULL) { //level 0 : scope
		scope_pointer = (scope*) malloc(sizeof(scope));
		scope_pointer->prev = NULL;
		scope_pointer->level = scope_level;
		//zero_scope = scope_pointer;
	}

	decl_obj->scope = scope_pointer;
	pivot->decl = decl_obj;
	
	symbol_table = pivot;
}


void push_declare(ste *formals) {
	if(formals->prev != NULL) 
		push_declare(formals->prev);
	declare(formals->name, formals->decl);
}


void set_while_stack(int count) {
	w_s *pivot;
	pivot = (w_s*) malloc(sizeof(w_s));
	pivot->cnt = count;
	pivot->prev = while_stack;
	while_stack = pivot;
}
void free_while_stack() {
	while_stack = while_stack->prev;
}
int get_while_stack() {
	return while_stack->cnt;
}





void print() {
	ste *pivot = symbol_table;
	printf("=======================\n");
	printf("scope level : %d\n", scope_level);
	
	while(pivot!=NULL) {
		printf("%s %d\n", pivot->name->name, ((pivot->decl->scope))->level);
		pivot = pivot->prev;
	}
	printf("=======================\n");
	
}

void error (char* message) {
	if(read_flag()) 
	{
		printf("%s:%d: error:%s\n", read_file(), read_line(), message);	
		set_flag(0);
	}
}
