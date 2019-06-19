/*	Definition section */
%{
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define SCOPE 10
#define ENTRY 100
#define STACK_SIZE 50
#define FILE_NAME "compiler_hw3"

extern int yylineno;
extern int yylex();
extern void yyerror(char *s);
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex

FILE *file;

struct SYMBOL_TABLE{
	int index;
	char name[30];
	char kind[10];	// "function" or "parameter" or "variable"
	char type[10];	// "int" or float or bool or string or void
	int scope;
	int par_count;	// record how many parameters in par[]
	char par[10][10];
	int function_status;	//-1 for not a function, 0 for declared, 1 for defined, 2 for declared and defined
};

/*the current scope; the current max index of the current scope; where is the indexes(entry number)*/
int Scope, Index[SCOPE], order[SCOPE][ENTRY];

int Result,Par_count;
int Error;	//0 for no error, 1 for undeclared var, 2 for undeclared func, 3 for redeclared var, 4 for redeclaration func(, 5 for redefined func)
int Function_status;	//-1 for not a function, 0 for declare, 1 for define, 2 for function call
int dump_flag,function_par_flag;
char Variable[30],Type[10],Kind[10],Error_ID[30];
char Par[10][10],Par_id[10][30];
struct SYMBOL_TABLE sym_table[SCOPE][ENTRY];

int type_flag;	//-1 for no assign, 0 for int, 1 for float, 2 for bool, 3 for void, 4 for string
int Stack_type;	//0 for int, 1 for float, 2 for bool, 3 for void, 4 for string
int function_legal_flag;	//whether to generate code for function
int global_flag;	//0 for local, 1 for global; used to determine whether gen ldc code for const
int temp_int;
float temp_float;
bool temp_bool;
char Par_type_list[10],return_type[10];
char Return_type[4]="IFZV";
int Find_scope,Find_index;
char Find_type[10];
char stack_type[SCOPE][STACK_SIZE][10];
int stack_pointer[SCOPE];
int function_type[SCOPE];
int assignment_layer;	//determine whether generate load code after store code, e.g. a=b=1; only b need to load after store
int assignment_type[10];	//assignment_type[assignment_layer] to record what kind of assignment_operator; 0 for =, 1 for +=, ...

/* Symbol table function*/
void create_symbol();
int insert_symbol();
int lookup_symbol(char *id);
void dump_symbol(int index);

int hash(char *,int);

/* code generation function */
void create_par_type_list();
void get_return_type(char type[10]);
void find_index_and_scope_and_type();
void store_code_gen();
void load_code_gen();
void arith_code_gen(char operator[10]);
void return_code_gen();
void type_casting();

%}

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    double f_val;
    char* string;
    bool boolean;
}

/* Token without return */
%token ADD SUB MUL DIV MOD INC DEC
%token MT LT MTE LTE EQ NE
%token ASGN ADDASGN SUBASGN MULASGN DIVASGN MODASGN
%token AND OR NOT
%token LB RB LCB RCB LSB RSB COMMA
%token PRINT
%token IF ELSE FOR WHILE RET CONT BREAK
%token C_COMMENT
%token CPP_COMMENT
%token SEMICOLON

/* Token with return, which need to sepcify type */
%token <string> ID VOID INT FLOAT STRING BOOL STR_CONST
%token <i_val> I_CONST
%token <f_val> F_CONST
%token <boolean> TRUE FALSE

/* Nonterminal with return, which need to sepcify type */
%type <string> type

/* Yacc will start at this nonterminal */
%start program

/* Grammar section */
%%
program
	: external_declaration
	| program external_declaration
;

external_declaration
	: function	{/*Par_count, Par*/}
	| global_declaration
	| comment
;

global_declaration
	: type SEMICOLON
	| type global_declarator_list SEMICOLON
;

global_declarator_list
	: global_declarator {
		Function_status=-1;	//variable
		strcpy(Kind,"variable");
		Par_count=0;
		Result=insert_symbol();
		if(Result!=0){	//redeclared
			Error=Result;
			strcpy(Error_ID,Variable);
		}
		else if(Result==0){
			/*no void and string here*/
			if(strcmp(Type,"int")==0){
				if(type_flag!=-1)	//get type_flag from global_declarator
					fprintf(file, ".field public static %s I = %d\n",Variable,temp_int);
				else
					fprintf(file, ".field public static %s I\n",Variable);
			}
			else if(strcmp(Type,"float")==0){
				if(type_flag!=-1)
					fprintf(file, ".field public static %s F = %f\n",Variable,temp_float);
				else
					fprintf(file, ".field public static %s F\n",Variable);
			}
			else if(strcmp(Type,"bool")==0){
				if(type_flag!=-1)
					fprintf(file, ".field public static %s Z = %d\n",Variable,temp_bool);
				else
					fprintf(file, ".field public static %s Z\n",Variable);
			}
		}
	} 
	| global_declarator_list COMMA global_declarator {
		Function_status=-1;
		strcpy(Kind,"variable");
		Par_count=0;
		Result=insert_symbol();
		if(Result!=0){	//redeclared
			Error=Result;
			strcpy(Error_ID,Variable);
		}
		else if(Result==0){
			/*no void and string here*/
			if(strcmp(Type,"int")==0){
				if(type_flag!=-1)
					fprintf(file, ".field public static %s I = %d\n",Variable,temp_int);
				else
					fprintf(file, ".field public static %s I\n",Variable);
			}
			else if(strcmp(Type,"float")==0){
				if(type_flag!=-1)
					fprintf(file, ".field public static %s F = %f\n",Variable,temp_float);
				else
					fprintf(file, ".field public static %s F\n",Variable);
			}
			else if(strcmp(Type,"bool")==0){
				if(type_flag!=-1)
					fprintf(file, ".field public static %s Z = %d\n",Variable,temp_bool);
				else
					fprintf(file, ".field public static %s Z\n",Variable);
			}
		}
	} 
;

global_declarator
	: ID {strcpy(Variable,$1); type_flag=-1;}
	| ID ASGN {global_flag=1;} const_without_str {global_flag=0; strcpy(Variable,$1);}
	| ID ASGN STR_CONST {strcpy(Variable,$1);}	//don't gen code for string in this assignment
;

const_without_str
	: I_CONST {
		temp_int=$1;
		type_flag=0;
		if(global_flag==0){	//0 for local
			++stack_pointer[Scope];
			fprintf(file, "	ldc %d\n",temp_int);
			strcpy(stack_type[Scope][stack_pointer[Scope]],"int");
		}
	}
	| F_CONST {
		temp_float=$1;
		type_flag=1;
		if(global_flag==0){	//0 for local
			++stack_pointer[Scope];
			fprintf(file, "	ldc %f\n",temp_float);
			strcpy(stack_type[Scope][stack_pointer[Scope]],"float");
		}
	}
	| TRUE {
		temp_bool=1;
		type_flag=2;
		if(global_flag==0){	//0 for local
			++stack_pointer[Scope];
			fprintf(file, "	ldc %d\n",temp_bool);
			strcpy(stack_type[Scope][stack_pointer[Scope]],"bool");
		}
	}
	| FALSE {
		temp_bool=0;
		type_flag=2;
		if(global_flag==0){	//0 for local
			++stack_pointer[Scope];
			fprintf(file, "	ldc %d\n",temp_bool);
			strcpy(stack_type[Scope][stack_pointer[Scope]],"bool");
		}
	}
;

type
	: VOID {strcpy(Type,$1); $$=$1;}
	| INT  {strcpy(Type,$1); $$=$1;}
	| FLOAT  {strcpy(Type,$1); $$=$1;}
	| STRING  {strcpy(Type,$1); $$=$1;}
	| BOOL  {strcpy(Type,$1); $$=$1;}
;

function
	: type ID LB RB SEMICOLON {
		strcpy(Variable, $2);
		strcpy(Kind,"function");
		Par_count=0;
		Function_status=0;	//-1 for not a function, 0 for declare, 1 for define
		Result=insert_symbol();
		if(Result!=0){	//redeclare function
			Error=Result;
			strcpy(Error_ID,Variable);
		}
	}
	| type ID LB function_parameter_list RB SEMICOLON {	//the check of the parameter list is belong to the compound_statement grammar
		strcpy(Variable, $2);
		strcpy(Kind,"function");
		strcpy(Type,$1);
		Function_status=0;	//-1 for not a function, 0 for declare, 1 for define
		Result=insert_symbol();
		if(Result!=0){	//redeclare function
			Error=Result;
			strcpy(Error_ID,Variable);
		}
	}
	| type ID LB RB {
		strcpy(Variable,$2);
		strcpy(Kind,"function");
		Function_status=1;	//-1 for not a function, 0 for declare, 1 for define
		Result=insert_symbol();
		if(Result!=0){	//redeclare function
			Error=Result;
			strcpy(Error_ID,Variable);
		}
		else if(Result==0){	//code generation
			function_legal_flag=1;
			get_return_type($1);
			function_type[Scope]=type_flag;	//use for return_code_gen() (we need to know the return type of the function)

			if(strcmp($2,"main")==0)
				fprintf(file, ".method public static main([Ljava/lang/String;)%c\n",Return_type[type_flag]);
			else
				fprintf(file, ".method public static %s()%s\n",$2,return_type);
			fprintf(file, ".limit stack 50\n");
			fprintf(file, ".limit locals 50\n");
		}
	}compound_statement{
		fprintf(file, ".end method\n");
		function_legal_flag=0;
	}
	| type ID LB function_parameter_list RB {
		int temp_count;
		temp_count=Par_count;
		strcpy(Variable,$2);
		strcpy(Kind,"function");
		strcpy(Type,$1);
		Function_status=1;	//-1 for not a function, 0 for declare, 1 for define
		Result=insert_symbol();
		if(Result!=0){	//redeclare function
			Error=Result;
			strcpy(Error_ID,Variable);
		}
		function_par_flag=1;
		Par_count=temp_count;

		if(Result==0){
			function_legal_flag=1;
			get_return_type($1);
			function_type[Scope]=type_flag;	//use for return_code_gen() (we need to know the return type of the function)

			if(strcmp($2,"main")==0)
				fprintf(file, ".method public static main([Ljava/lang/String;)%c\n",Return_type[type_flag]);
			else{
				create_par_type_list();
				fprintf(file, ".method public static %s(%s)%s\n",$2,Par_type_list,$1);
			}
			fprintf(file, ".limit stack 50\n");
			fprintf(file, ".limit locals 50\n");
		}
	}compound_statement{
		fprintf(file, ".end method\n");
		function_legal_flag=0;
	}
;

function_parameter_list
	: type ID {
		strcpy(Par[Par_count],Type);
		/*used for the local variable of function later*/
		strcpy(Par_id[Par_count++],$2);
	}
	| function_parameter_list COMMA type ID {
		strcpy(Par[Par_count],Type);
		/*used for the local variable of function later*/
		strcpy(Par_id[Par_count++],$4);
	}
;

statement
	: compound_statement
	| statement_with_return
	| selection_statement
	| iteration_statement
	| comment
	| jump_statement
;

statement_with_return
	: expression_statement
	| print_statement
;

print_statement
	: PRINT LB ID RB SEMICOLON{
		Function_status=-1;
		Result=lookup_symbol($3);
		if(Result!=0){
			Error=Result;
			strcpy(Error_ID,$3);
		}
		else if(Result==0 && function_legal_flag==1){
			strcpy(Variable,$3);
			load_code_gen();	//we can gen load code and find type_flag here
			fprintf(file, "	getstatic java/lang/System/out Ljava/io/PrintStream;\n");
			fprintf(file, "	swap\n");
			fprintf(file, "	invokevirtual java/io/PrintStream/println(%c)V\n",Return_type[type_flag]);
		}
	}
	| PRINT LB const_without_str RB SEMICOLON{
		fprintf(file, "	getstatic java/lang/System/out Ljava/io/PrintStream;\n");
		fprintf(file, "	swap\n");
		fprintf(file, "	invokevirtual java/io/PrintStream/println(%c)V\n",Return_type[type_flag]);
	}
	| PRINT LB STR_CONST RB SEMICOLON{
		fprintf(file, "	ldc %s\n",$3);
		fprintf(file, "	getstatic java/lang/System/out Ljava/io/PrintStream;\n");
		fprintf(file, "	swap\n");
		fprintf(file, "	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
	}
;

comment
	: C_COMMENT
	| CPP_COMMENT
;

jump_statement
	: RET SEMICOLON {return_code_gen();}
	| RET statement_with_return {return_code_gen();}
;


compound_statement
	: LCB {
		create_symbol();
		if(function_par_flag){
			int i,count;
			count=Par_count;
			for(i=0;i<count;++i){
				strcpy(Variable,Par_id[i]);
				strcpy(Kind,"parameter");
				strcpy(Type,Par[i]);
				Par_count=0;
				Result=insert_symbol();
				if(Result!=0 && Error==0){	//redefine variable
					Error=Result;
					strcpy(Error_ID,Variable);
				}
			}
			function_par_flag=0;
		}
	}RCB {
		dump_flag=1;
	}
	| LCB {
		create_symbol();
		if(function_par_flag){
			int i,count;
			count=Par_count;
			for(i=0;i<count;++i){
				strcpy(Variable,Par_id[i]);
				strcpy(Kind,"parameter");
				strcpy(Type,Par[i]);
				Par_count=0;
				Result=insert_symbol();
				if(Result!=0 && Error==0){	//redefine variable
					Error=Result;
					strcpy(Error_ID,Variable);
				}
			}
			function_par_flag=0;
		}
	}block_item_list RCB {
		dump_flag=1;
	}
;

block_item_list
	: block_item
	| block_item_list block_item
;

block_item
	: statement
	| local_declaration
	| function
;

local_declaration
	: type SEMICOLON
	| type local_declarator_list SEMICOLON
;

local_declarator_list
	: local_declarator {
		Function_status=-1;
		strcpy(Kind,"variable");
		Par_count=0;
		Result=insert_symbol();
		if(Result!=0){	//redeclared
			Error=Result;
			strcpy(Error_ID,Variable);
		}
		else if(Result==0 && function_legal_flag==1){	//only if function defined successfully, code_gen inside the compound statement is needed
			store_code_gen();
		}
	} 
	| local_declarator_list COMMA local_declarator {
		Function_status=-1;
		strcpy(Kind,"variable");
		Par_count=0;
		Result=insert_symbol();
		if(Result!=0){	//redeclared
			Error=Result;
			strcpy(Error_ID,Variable);
		}
		else if(Result==0 && function_legal_flag==1){	//only if function defined successfully, code_gen inside the compound statement is needed
			store_code_gen();
		}
	} 
;

local_declarator
	: ID {
		strcpy(Variable,$1);
		if(function_legal_flag==1)
			fprintf(file, "	ldc 0\n");
		++stack_pointer[Scope];
		strcpy(stack_type[Scope][stack_pointer[Scope]],"int");
	}
	| ID ASGN {++assignment_layer;} assignment_expression {--assignment_layer; strcpy(Variable,$1);}
	| ID ASGN STR_CONST {
		strcpy(Variable,$1);
		if(function_legal_flag==1)
			fprintf(file, "	ldc %s\n",$3);
		++stack_pointer[Scope];
		strcpy(stack_type[Scope][stack_pointer[Scope]],"string");
	}
;

expression_statement
	: SEMICOLON
	| expression_list SEMICOLON
;

expression_list
	: assignment_expression
	| expression_list COMMA  assignment_expression
;

assignment_expression
	: logical_or_expression
	| ID assignment_operator {++assignment_layer;} assignment_expression{
		--assignment_layer;
		Function_status=-1;
		Result=lookup_symbol($1);
		if(Result!=0){	//0 for no error
			Error=Result;
			strcpy(Error_ID,$1);
		}
		else if(Result==0 && function_legal_flag==1){
			strcpy(Variable,$1);	//Variable will be used in store_code_gen()

			if(assignment_type[assignment_layer]!=0){	//0 for =
				load_code_gen();	//load the id before assign(+=, -=, ...)

				fprintf(file, "	swap\n");	//a*=1; is a=a*1;, not a=1*a;
				char temp_swap[10];	//also swap the stack types
				strcpy(temp_swap,stack_type[Scope][stack_pointer[Scope]]);
				strcpy(stack_type[Scope][stack_pointer[Scope]],stack_type[Scope][stack_pointer[Scope]-1]);
				strcpy(stack_type[Scope][stack_pointer[Scope]-1],temp_swap);

				if(assignment_type[assignment_layer]==1)	//1 for +=
					arith_code_gen("add");
				else if(assignment_type[assignment_layer]==2)	//2 for -=
					arith_code_gen("sub");
				else if(assignment_type[assignment_layer]==3)	//3 for *=
					arith_code_gen("mul");
				else if(assignment_type[assignment_layer]==4)	//4 for /=
					arith_code_gen("div");
				else if(assignment_type[assignment_layer]==5)	//5 for %=
					arith_code_gen("mod");
			}
			store_code_gen();
			if(assignment_layer!=0)	//e.g. a=b=1; we need to load b after store it because we need to store it to a
				load_code_gen();	// but we don't need to load a after store it
		}
	}
	| ID ASGN STR_CONST{
		Function_status=-1;
		Result=lookup_symbol($1);
		if(Result!=0){	//0 for no error
			Error=Result;
			strcpy(Error_ID,$1);
		}
		else if(Result==0 && function_legal_flag==1){
			strcpy(Variable,$1);	//Variable will be used in store_code_gen()
			fprintf(file, "	ldc %s\n",$3);
			++stack_pointer[Scope];
			strcpy(stack_type[Scope][stack_pointer[Scope]],"string");
			store_code_gen();
			if(assignment_layer!=0)
				load_code_gen();
		}
	}
;

assignment_operator
	: ASGN {assignment_type[assignment_layer]=0;}
	| ADDASGN {assignment_type[assignment_layer]=1;}
	| SUBASGN {assignment_type[assignment_layer]=2;}
	| MULASGN {assignment_type[assignment_layer]=3;}
	| DIVASGN {assignment_type[assignment_layer]=4;}
	| MODASGN {assignment_type[assignment_layer]=5;}
;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR logical_and_expression
;

logical_and_expression
	: equality_expression
	| logical_and_expression AND equality_expression
;

equality_expression
	: relational_expression
	| equality_expression EQ relational_expression
	| equality_expression NE relational_expression
;

relational_expression
	: additive_expression
	| relational_expression MT additive_expression
	| relational_expression LT additive_expression
	| relational_expression MTE additive_expression
	| relational_expression LTE additive_expression
;

additive_expression
	: multiplicative_expression
	| additive_expression ADD multiplicative_expression {arith_code_gen("add");}
	| additive_expression SUB multiplicative_expression {arith_code_gen("sub");}
;

multiplicative_expression
	: prefix_expression
	| multiplicative_expression MUL prefix_expression {arith_code_gen("mul");}
	| multiplicative_expression DIV prefix_expression {arith_code_gen("div");}
	| multiplicative_expression MOD prefix_expression {arith_code_gen("mod");}
;

prefix_expression
	: postfix_expression
	| ADD prefix_expression
	| SUB prefix_expression
;

postfix_expression
	: ID{
		Function_status=-1;
		Result=lookup_symbol($1);
		if(Result!=0){
			Error=Result;
			strcpy(Error_ID,$1);
		}
		else if(Result==0 && function_legal_flag==1){
			strcpy(Variable,$1);
			load_code_gen();
		}
	}
	| ID LB {
		Function_status=2;	//function call
		Result=lookup_symbol($1);
		if(Result!=0){
			Error=Result;
			strcpy(Error_ID,$1);
		}
	}RB
	| ID LB {
		Function_status=2;	//function call
		Result=lookup_symbol($1);
		if(Result!=0){
			Error=Result;
			strcpy(Error_ID,$1);
		}
	}expression_list RB
	| const_without_str
	| LB expression_list RB
	| bra_expression INC {
		load_code_gen(); //in order to use the original value for later operation(not the value after INC), I load second time here
		++stack_pointer[Scope];
		fprintf(file, "	ldc 1\n");
		strcpy(stack_type[Scope][stack_pointer[Scope]],"int");
		arith_code_gen("add");
		store_code_gen();	//pop from the stack, so top-of-stack is now the original value(before INC)
	}
	| bra_expression DEC {
		load_code_gen(); //in order to use the original value for later operation(not the value after DEC), I load second time here
		++stack_pointer[Scope];
		fprintf(file, "	ldc 1\n");
		strcpy(stack_type[Scope][stack_pointer[Scope]],"int");
		arith_code_gen("sub");
		store_code_gen();	//pop from the stack, so top-of-stack is now the original value(before DEC)
	}
;

bra_expression
	: ID {
		Function_status=-1;
		Result=lookup_symbol($1);
		if(Result!=0){
			Error=Result;
			strcpy(Error_ID,$1);
		}
		else if(Result==0 && function_legal_flag==1){
			strcpy(Variable,$1);
			load_code_gen();
		}
	}
	| LB bra_expression RB
;

selection_statement
	: IF LB expression_list RB compound_statement
	| IF LB expression_list RB compound_statement ELSE selection_statement
	| IF LB expression_list RB compound_statement ELSE compound_statement
;

iteration_statement
	: WHILE LB expression_list RB loop_compound_statement
;

loop_statement
	: loop_compound_statement
	| expression_statement
	| loop_selection_statement
	| iteration_statement
	| print_statement
	| comment
	| loop_jump_statement
;

loop_selection_statement
	: IF LB expression_list RB loop_compound_statement
	| IF LB expression_list RB loop_compound_statement ELSE loop_selection_statement
	| IF LB expression_list RB loop_compound_statement ELSE loop_compound_statement
;

loop_compound_statement
	: LCB RCB
	| LCB loop_block_item_list RCB
;

loop_block_item_list
	: loop_block_item
	| loop_block_item_list loop_block_item
;

loop_block_item
	: loop_statement
	| local_declaration
	| function
;

loop_jump_statement
	: CONT SEMICOLON
	| BREAK SEMICOLON
	| jump_statement
;

%%
/* C code section */

void create_par_type_list()
{
	int i;
	strcpy(Par_type_list,"");
	for(i=0;i<Par_count;++i){
		if(strcmp(Par[Par_count],"int")==0)
			strcat(Par_type_list,"I");
		else if(strcmp(Par[Par_count],"float")==0)
			strcat(Par_type_list,"F");
		else if(strcmp(Par[Par_count],"bool")==0)
			strcat(Par[Par_count],"Z");
	}
}

void get_return_type(char type[10])
{
	if(strcmp(type,"int")==0)
		type_flag=0;
	else if(strcmp(type,"float")==0)
		type_flag=1;
	else if(strcmp(type,"bool")==0)
		type_flag=2;
	else if(strcmp(type,"void")==0)
		type_flag=3;
	else if(strcmp(type,"string")==0)
		type_flag=4;
}

void find_index_and_scope_and_type()
{
	int i,j,scope,index;
	Find_scope=-1;	//no found in every scope
	Find_index=0;
	for(scope=Scope;scope>=0;--scope){
		for(i=0;i<ENTRY;++i){
			index=hash(Variable,i);
			if(sym_table[scope][index].index==-1)	//not found in this scope
				i=ENTRY;
			else if(strcmp(sym_table[scope][index].name,Variable)==0){	//found
				Find_scope=scope;
				Find_index=sym_table[scope][index].index;
				for(j=1;j<scope;++j)	//get the number of variables from scope 1 to (scope-1)
					Find_index+=(Index[scope]+1);
				strcpy(Find_type,sym_table[scope][index].type);
				return;
			}
		}
	}
}

void store_code_gen()
{
	find_index_and_scope_and_type();	//use global variables: Find_scope, Find_index, Find_type
	get_return_type(Find_type);
	
	if(Find_scope>0){
		if(type_flag==0){	//int
			if(strcmp(stack_type[Scope][stack_pointer[Scope]],"float")==0)
				fprintf(file, "	f2i\n");
			fprintf(file, "	istore %d\n",Find_index);
		}
		else if(type_flag==1){	//float
			if(strcmp(stack_type[Scope][stack_pointer[Scope]],"int")==0)
				fprintf(file, "	i2f\n");
			fprintf(file, "	fstore %d\n",Find_index);
		}
		else if(type_flag==2)	//bool
			fprintf(file, "	istore %d\n",Find_index);
		else if(type_flag==4)	//string
			fprintf(file, "	astore %d\n",Find_index);
	}
	else if(Find_scope==0)	//attetion: no string type is in the global scope
		fprintf(file, "	putstatic %s/%s %c\n",FILE_NAME,Variable,Return_type[type_flag]);

	--stack_pointer[Scope];
}

void load_code_gen()
{
	/*before you call load_code_gen, you have to assign variable name to Variable*/
	find_index_and_scope_and_type();	//use global variables: Find_scope, Find_index
	get_return_type(Find_type);
	
	++stack_pointer[Scope];

	if(Find_scope>0){
		if(type_flag==0)	//int
			fprintf(file, "	iload %d\n",Find_index);
		else if(type_flag==1)	//float
			fprintf(file, "	fload %d\n",Find_index);
		else if(type_flag==2)	//bool
			fprintf(file, "	iload %d\n",Find_index);
		else if(type_flag==4)	//string
			fprintf(file, "	aload %d\n",Find_index);
	}
	else if(Find_scope==0)	//attetion: no string type is in the global scope
		fprintf(file, "	getstatic %s/%s %c\n",FILE_NAME,Variable,Return_type[type_flag]);
	
	if(type_flag==0)	//int
		strcpy(stack_type[Scope][stack_pointer[Scope]],"int");
	else if(type_flag==1)	//float
		strcpy(stack_type[Scope][stack_pointer[Scope]],"float");
	else if(type_flag==2)	//bool
		strcpy(stack_type[Scope][stack_pointer[Scope]],"bool");
	else if(type_flag==4)	//string
		strcpy(stack_type[Scope][stack_pointer[Scope]],"string");
}

void return_code_gen()
{
	printf("123 %d %d %d\n",function_type[Scope],function_type[0],function_type[1]);
	if(function_legal_flag!=1)
		return;

	type_flag=function_type[Scope-1];
	if(type_flag==0){
		if(strcmp(stack_type[Scope][stack_pointer[Scope]],"int")!=0)
			Error=8;
		else
			fprintf(file, "	ireturn\n");
	}
	else if(type_flag==1){
			if(strcmp(stack_type[Scope][stack_pointer[Scope]],"float")!=0)
				Error=8;
		else
				fprintf(file, "	freturn\n");
		}
	else if(type_flag==2){
		if(strcmp(stack_type[Scope][stack_pointer[Scope]],"bool")!=0)
			Error=8;
		else
			fprintf(file, "	zreturn\n");
	}
	else if(type_flag==3){
			fprintf(file, "	return\n");
	}
}

void arith_code_gen(char operator[10])
{
	if(function_legal_flag!=1)
		return;

	type_casting();
	if(strcmp(operator,"add")==0){
		if(type_flag==0)
			fprintf(file, "	iadd\n");
		else	//type_flag==1
			fprintf(file, "	fadd\n");
	}
	else if(strcmp(operator,"sub")==0){
		if(type_flag==0)
			fprintf(file, "	isub\n");
		else
			fprintf(file, "	fsub\n");
	}
	else if(strcmp(operator,"mul")==0){
		if(type_flag==0)
			fprintf(file, "	imul\n");
		else
			fprintf(file, "	fmul\n");
	}
	else if(strcmp(operator,"div")==0){
		if(type_flag==0)
			fprintf(file, "	idiv\n");
		else
			fprintf(file, "	fdiv\n");
	}
	else if(strcmp(operator,"mod")==0){
		if(type_flag==0)
			fprintf(file, "	irem\n");
		else
			Error=7;
	}
	--stack_pointer[Scope];
	if(type_flag==0)
		strcpy(stack_type[Scope][stack_pointer[Scope]],"int");
	else
		strcpy(stack_type[Scope][stack_pointer[Scope]],"float");
}

void type_casting()
{
	if(strcmp(stack_type[Scope][stack_pointer[Scope]-1],"int")==0 && strcmp(stack_type[Scope][stack_pointer[Scope]],"int")==0){
		type_flag=0;	//0 for int
	}
	else if(strcmp(stack_type[Scope][stack_pointer[Scope]-1],"int")==0 && strcmp(stack_type[Scope][stack_pointer[Scope]],"float")==0){
		fprintf(file, "	swap\n");
		fprintf(file, "	i2f\n");
		fprintf(file, "	swap\n");
		type_flag=1;	//1 for float
	}
	else if(strcmp(stack_type[Scope][stack_pointer[Scope]-1],"float")==0 && strcmp(stack_type[Scope][stack_pointer[Scope]],"int")==0){
		fprintf(file, "	i2f\n");
		type_flag=1;	//1 for float
	}
	else if(strcmp(stack_type[Scope][stack_pointer[Scope]-1],"float")==0 && strcmp(stack_type[Scope][stack_pointer[Scope]],"float")==0){
		type_flag=1;	//1 for float
	}
	else
		Error=6;
}

void Sem_Err()
{
	char *s;
	if(Error==1)
		s="Undeclared variable";
	else if(Error==2)
		s="Undeclared function";
	else if(Error==3)
		s="Redeclared variable";
	else if(Error==4)
		s="Redeclared function";
	else if(Error==5)
		s="Redefined function";
	else if(Error==6)
		s="Not int or float arithmetic operation";
	else if(Error==7)
		s="It can only accept \"int mod int\"";
	else if(Error==8)
		s="Function return type is not the same";
	
	printf("\n|-----------------------------------------------|\n");
	if(buf[strlen(buf)-1]=='\n')
		printf("| Error found in line %d: %s", yylineno, buf);
	else
		printf("| Error found in line %d: %s\n", yylineno, buf);
	printf("| %s %s", s, Error_ID);
	printf("\n|-----------------------------------------------|\n\n");
}

void yyerror(char *s)
{
	char temp[256];
	memset(temp,0,sizeof(temp));
	printf("%d: %s\n",++yylineno,buf);
	if(Error!=0)
		Sem_Err();
	printf("\n|-----------------------------------------------|\n");
	printf("| Error found in line %d: %s\n", yylineno, buf);
	printf("| %s", s);
	printf("\n|-----------------------------------------------|\n\n");

	exit(0);
}

int hash(char *id, int num)
{
	/*sum of each char + num^2 (if collision)*/
	int i,sum=0;
	for(i=0;id[i]!='\0';++i)
		sum+=id[i];
	sum+=num*num;
	sum%=97;	//a prime number;
//printf("hash: %s %d %d %d \n\n",id,num,i,sum);
	return sum;
}

void create_symbol()
{
	++Scope;
	/*reset all*/
	int i,j;
	memset(sym_table[Scope],0,sizeof(sym_table[Scope]));
	for(i=0;i<ENTRY;++i){
		sym_table[Scope][i].index=-1;
		sym_table[Scope][i].scope=-1;
		sym_table[Scope][i].par_count=-1;
		sym_table[Scope][i].function_status=-1;
	}
	Index[Scope]=-1;
	memset(stack_type[Scope],0,sizeof(stack_type[Scope]));
	memset(stack_pointer,-1,sizeof(stack_pointer));
}

int insert_symbol()
{
	int index,i,j;
	/*only find in this scope*/
	for(i=0;i<ENTRY;++i){
		index=hash(Variable,i);
		if(sym_table[Scope][index].index==-1){	//found the empty entry
			sym_table[Scope][index].index=++Index[Scope];
			strcpy(sym_table[Scope][index].name,Variable);
			strcpy(sym_table[Scope][index].kind,Kind);
			strcpy(sym_table[Scope][index].type,Type);
			sym_table[Scope][index].scope=Scope;
			sym_table[Scope][index].par_count=Par_count;
			for(j=0;j<Par_count;++j)
				strcpy(sym_table[Scope][index].par[j],Par[j]);
			if(strcmp(Kind,"function")==0)
				sym_table[Scope][index].function_status=Function_status;
			Function_status=-1;
			Par_count=0;
			order[Scope][Index[Scope]]=index;
			return 0;
		}
		else if(strcmp(sym_table[Scope][index].name,Variable)==0){	//already exists
			Par_count=0;
			if(sym_table[Scope][index].function_status==-1){	//not a function
				if(Function_status==-1)
					return 3; //redeclared variable
				if(Function_status==0)
					return 4;	//redeclared function
				else if(Function_status==1)
					return 5;	//redefined function
			}
			else if(Function_status==-1){
				return 3;	//redeclared variable
			}
			else if(sym_table[Scope][index].function_status==2){	//already declared and defined
				if(Function_status==0)
					return 4;	//redeclared function
				else if(Function_status==1)
					return 5;	//redefined function
			}
			else if(sym_table[Scope][index].function_status==1 && Function_status==1){
				return 5;	//redefined function
			}
			else if(sym_table[Scope][index].function_status==0 && Function_status==0){
				return 4;	//redeclared function
			}
			else if(sym_table[Scope][index].function_status==0 && Function_status==1){
				sym_table[Scope][index].function_status=2;	//declared and defined
				return 0;
			}
			else if(sym_table[Scope][index].function_status==1 && Function_status==0){
				sym_table[Scope][index].function_status=2;	//declared and defined
				return 0;
			}
		}
	}
}

int lookup_symbol(char *id)
{
	int index,i,scope=Scope;
	for(;scope>=0;--scope){
		for(i=0;i<ENTRY;++i){
			index=hash(id,i);
			if(sym_table[scope][index].index==-1)	//empty entry (not found)
				break;
			else if(strcmp(sym_table[scope][index].name,id)==0)	//already exists
				return 0;	//no error
		}
		if(i==ENTRY){
			printf("symbol table is too small\n");
			exit(-1);
		}
	}
	if(Function_status==2){	//function call
		return 2;	//undeclared function
	}
	else if(Function_status==-1){	//not a function(is a variable)
		return 1;	//undeclared variable (not found in any scope level)
	}
}

void dump_symbol(int index)
{
	int i,j,entry;
	if(index>=0){
		printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
		"Index", "Name", "Kind", "Type", "Scope", "Attribute");
		for(i=0;i<=index;++i){
    			entry=order[Scope][i];
			printf("%-10d%-10s%-12s%-10s%-10d",
    			i,sym_table[Scope][entry].name,sym_table[Scope][entry].kind,sym_table[Scope][entry].type,sym_table[Scope][entry].scope);
			if(sym_table[Scope][entry].par_count!=-1)
				printf("%s",sym_table[Scope][entry].par[0]);
			for(j=1;j<sym_table[Scope][entry].par_count;++j)
				printf(", %s",sym_table[Scope][entry].par[j]);
			printf("\n");
		}
		printf("\n");
	}
	--Scope;
}

void init()
{
	int i,j;
	yylineno = 0;
	Error=0;	//no error
	for(i=0;i<SCOPE;++i)
		Index[i]=-1;
	for(i=0;i<SCOPE;++i)
		for(j=0;j<ENTRY;++j)
			order[i][j]=-1;

	Scope=-1;
	Par_count=0;
	Function_status=-1;
	dump_flag=0;
	function_par_flag=0;

	function_legal_flag=0;
	assignment_layer=0;
}

int main(int argc, char** argv)
{
	init();
	create_symbol();

	char temp_name[20]=FILE_NAME;
	strcat(temp_name,".j");
    
    	file = fopen(temp_name,"w");
	fprintf(file, ".class public %s\n",FILE_NAME);
	fprintf(file, ".super java/lang/Object\n");

	yyparse();

	dump_symbol(Index[0]);

	printf("\nTotal lines: %d \n",yylineno);

	fclose(file);

	return 0;
}
