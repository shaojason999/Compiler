/*	Definition section */
%{
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define SCOPE 10
#define ENTRY 100
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

int type_flag;	//-1 for no assign, 0 for int, 1 for float, 2 for bool
int function_legal_flag;	//whether to generate code for function
int temp_int;
float temp_float;
bool temp_bool;
char Par_type_list[10],return_type[10];
char RETURN_TYPE[4]="IFZV";
int Find_scope,Find_index;

/* Symbol table function*/
void create_symbol();
int insert_symbol();
int lookup_symbol(char *id);
void dump_symbol(int index);

int hash(char *,int);

/* code generation function */
void create_par_type_list();
int get_return_type(char type[10]);
void find_index_and_scope();
void store_code_gen();

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
	| ID ASGN const_without_str {strcpy(Variable,$1);}
	| ID ASGN STR_CONST {strcpy(Variable,$1);}
;

const_without_str
	: I_CONST {temp_int=$1; type_flag=0;}
	| F_CONST {temp_float=$1; type_flag=1;}
	| TRUE {temp_bool=1; type_flag=2;}
	| FALSE {temp_bool=0; type_flag=2;}
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

			int type_flag;
			type_flag=get_return_type($1);

			if(strcmp($2,"main")==0)
				fprintf(file, ".method public static main([Ljava/lang/String;)%c\n",RETURN_TYPE[type_flag]);
			else
				fprintf(file, ".method public static %s()%s\n",$2,return_type);
			fprintf(file, ".limit stack 50\n");
			fprintf(file, ".limit locals 50\n");
		}
	}compound_statement{
		if(function_legal_flag==1){
			int type_flag;
			type_flag=get_return_type($1);

			if(type_flag==0)
				fprintf(file, "	ireturn\n");
			else if(type_flag==1)
				fprintf(file, "	freturn\n");
			else if(type_flag==2)
				fprintf(file, "	zreturn\n");
			else if(type_flag==3)
				fprintf(file, "	return\n");
			fprintf(file, ".end method\n");
			function_legal_flag=0;
		}
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

			int type_flag;
			type_flag=get_return_type($1);

			if(strcmp($2,"main")==0)
				fprintf(file, ".method public static main([Ljava/lang/String;)%c\n",RETURN_TYPE[type_flag]);
			else{
				create_par_type_list();
				fprintf(file, ".method public static %s(%s)%s\n",$2,Par_type_list,$1);
			}
			fprintf(file, ".limit stack 50\n");
			fprintf(file, ".limit locals 50\n");
		}
	}compound_statement{
		if(function_legal_flag==1){
			int type_flag;
			type_flag=get_return_type($1);

			if(type_flag==0)
				fprintf(file, "	ireturn\n");
			else if(type_flag==1)
				fprintf(file, "	freturn\n");
			else if(type_flag==2)
				fprintf(file, "	zreturn\n");
			else if(type_flag==3)
				fprintf(file, "	return\n");
			fprintf(file, ".end method\n");
			function_legal_flag=0;
		}
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
	: PRINT LB ID {
		Function_status=-1;
		Result=lookup_symbol($3);
		if(Result!=0){
			Error=Result;
			strcpy(Error_ID,$3);
		}
	}RB SEMICOLON
	| PRINT LB STR_CONST RB SEMICOLON
;

comment
	: C_COMMENT
	| CPP_COMMENT
;

jump_statement
	: RET SEMICOLON
	| RET statement_with_return
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
	: ID {strcpy(Variable,$1); fprintf(file, "	ldc 0\n");}
	| ID ASGN assignment_expression {strcpy(Variable,$1);}
	| ID ASGN STR_CONST {strcpy(Variable,$1); fprintf(file, "	ldc %s\n",$3);}
;

expression_statement
	: SEMICOLON
	| expression_list SEMICOLON
;

expression_list
	: assignment_expression
	| expression_list COMMA assignment_expression
;

assignment_expression
	: logical_or_expression
	| ID assignment_operator{
		Function_status=-1;
		Result=lookup_symbol($1);
		if(Result!=0){	//0 for no error
			Error=Result;
			strcpy(Error_ID,$1);
		}
	}assignment_expression
	| ID ASGN {
		Function_status=-1;
		Result=lookup_symbol($1);
		if(Result!=0){	//0 for no error
			Error=Result;
			strcpy(Error_ID,$1);
		}
	}STR_CONST
;

assignment_operator
	: ASGN
	| ADDASGN
	| SUBASGN
	| MULASGN
	| DIVASGN
	| MODASGN
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
	| additive_expression ADD multiplicative_expression
	| additive_expression SUB multiplicative_expression
;

multiplicative_expression
	: prefix_expression
	| multiplicative_expression MUL prefix_expression
	| multiplicative_expression DIV prefix_expression
	| multiplicative_expression MOD prefix_expression
;

prefix_expression
	: postfix_expression
	| ADD prefix_expression
	| SUB prefix_expression
/*	| INC bra_expression
	| DEC bra_expression*/
;

postfix_expression
	: ID{
		Function_status=-1;
		Result=lookup_symbol($1);
		if(Result!=0){
			Error=Result;
			strcpy(Error_ID,$1);
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
	| bra_expression INC
	| bra_expression DEC 
;

bra_expression
	: ID {
		Function_status=-1;
		Result=lookup_symbol($1);
		if(Result!=0){
			Error=Result;
			strcpy(Error_ID,$1);
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

int get_return_type(char type[10])
{
	if(strcmp(type,"int")==0)
		return 0;
	else if(strcmp(type,"float")==0)
		return 1;
	else if(strcmp(type,"bool")==0)
		return 2;
	else if(strcmp(type,"void")==0)
		return 3;
	else if(strcmp(type,"string")==0)
		return 4;
}

void find_index_and_scope()
{
	int i,j,scope,index;
	Find_scope=-1;	//no found in every scope
	Find_index=0;
	for(scope=Scope;scope>=0;--scope){
		for(i=0;i<ENTRY;++i){
			index=hash(Variable,i);
			if(sym_table[scope][index].index==-1)	//not found in this scope
				i=ENTRY;
			else if(strcmp(sym_table[scope][index].name,Variable)==0){
				Find_scope=scope;
				Find_index=sym_table[scope][index].index;
				for(j=1;j<scope;++j)	//get the number of variables from scope 1 to (scope-1)
					Find_index+=(Index[scope]+1);
				return;
			}
		}
	}
}

void store_code_gen()
{
	int type_flag;
	find_index_and_scope();	//use global variables: Find_scope, Find_index
	type_flag=get_return_type(Type);
	
	if(Find_scope>0){
		if(type_flag==0)	//int
			fprintf(file, "	istore %d\n",Find_index);
		else if(type_flag==1)	//float
			fprintf(file, "	fstore %d\n",Find_index);
		else if(type_flag==2)	//bool
			fprintf(file, "	istore %d\n",Find_index);
		else if(type_flag==4)	//string
			fprintf(file, "	astore %d\n",Find_index);
	}
	else if(Find_scope==0)	//attetion: no string type is in the global scope
		fprintf(file, "	getstatic %s/%s %c\n",FILE_NAME,Variable,RETURN_TYPE[type_flag]);
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

void dump_symbol(int index) {
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
