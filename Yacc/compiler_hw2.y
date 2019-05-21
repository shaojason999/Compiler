/*	Definition section */
%{
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

extern int yylineno;
extern int yylex();
extern void yyerror(char *s);
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex

/* Symbol table function - you can add new function if needed. */
int lookup_symbol();
void create_symbol();
void insert_symbol();
void dump_symbol();

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
%token VOID INT FLOAT STRING BOOL
%token TRUE FALSE
%token STR_CONST
%token I_CONST F_CONST
%token C_COMMENT
%token CPP_COMMENT
%token ID
%token SEMICOLON

/* Token with return, which need to sepcify type */
//%token <i_val> I_CONST
//%token <f_val> F_CONST
//%token <string> STRING

/* Nonterminal with return, which need to sepcify type */
//%type <f_val> stat

/* Yacc will start at this nonterminal */
%start program

/* Grammar section */
%%
program
	: external_declaration
	| program external_declaration
;

external_declaration
	: function_declaration
	| function_definition
	| global_declaration
	| comment
;

global_declaration
	: type SEMICOLON
	| type global_declarator_list SEMICOLON
;

global_declarator_list
	: global_declarator
	| global_declarator_list COMMA global_declarator
;

global_declarator
	: ID
	| ID ASGN only_const_operation
	| ID ASGN STR_CONST
;

only_const_operation
	: const_logical_or_expression
;

const_without_str
	: I_CONST
	| F_CONST
	| TRUE
	| FALSE
;

type
	: VOID
	| INT
	| FLOAT
	| STRING
	| BOOL
;

function_declaration
	: type ID LB RB SEMICOLON
	| type ID LB function_parameter_list RB SEMICOLON
;

function_definition
	: type ID LB RB compound_statement
	| type ID LB function_parameter_list RB compound_statement
;

function_parameter_list
	: type ID
	| function_parameter_list COMMA type ID
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
	: PRINT LB ID RB SEMICOLON
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
	: LCB RCB
	| LCB block_item_list RCB
;

block_item_list
	: block_item
	| block_item_list block_item
;

block_item
	: statement
	| local_declaration
	| function_definition
;

local_declaration
	: type SEMICOLON
	| type local_declarator_list SEMICOLON
;

local_declarator_list
	: local_declarator
	| local_declarator_list COMMA local_declarator
;

local_declarator
	: ID
	| ID ASGN assignment_expression
	| ID ASGN STR_CONST
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
	| ID assignment_operator assignment_expression
	| ID ASGN STR_CONST
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
	: ID
	| ID LB RB
	| ID LB expression_list RB
	| const_without_str 
	| LB expression_list RB
	| bra_expression INC
	| bra_expression DEC 
;

bra_expression
	: ID
	| LB bra_expression RB
;

const_logical_or_expression
	: const_logical_and_expression
	| const_logical_or_expression OR const_logical_and_expression
;

const_logical_and_expression
	: const_equality_expression
	| const_logical_and_expression AND const_equality_expression
;

const_equality_expression
	: const_relational_expression
	| const_equality_expression EQ const_relational_expression
	| const_equality_expression NE const_relational_expression
;

const_relational_expression
	: const_additive_expression
	| const_relational_expression MT const_additive_expression
	| const_relational_expression LT const_additive_expression
	| const_relational_expression MTE const_additive_expression
	| const_relational_expression LTE const_additive_expression
;

const_additive_expression
	: const_multiplicative_expression
	| const_additive_expression ADD const_multiplicative_expression
	| const_additive_expression SUB const_multiplicative_expression
;

const_multiplicative_expression
	: const_prefix_expression
	| const_multiplicative_expression MUL const_prefix_expression
	| const_multiplicative_expression DIV const_prefix_expression
	| const_multiplicative_expression MOD const_prefix_expression
;

const_prefix_expression
	: const_postfix_expression
	| ADD const_prefix_expression
	| SUB const_prefix_expression
;

const_postfix_expression
	: const_without_str
	| LB const_logical_or_expression RB
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
	: compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| print_statement
	| comment
	| loop_jump_statement
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
	| function_definition
;

loop_jump_statement
	: CONT SEMICOLON
	| BREAK SEMICOLON
	| jump_statement
;



/*
program
    : program stat
    |
;

stat
    : declaration
    | compound_stat
    | expression_stat
    | print_func
;

declaration
    : type ID '=' initializer SEMICOLON
    | type ID SEMICOLON
;

// actions can be taken when meet the token or rule

type
    : INT { $$ = $1; }
    | FLOAT { $$ = $1; }
    | BOOL  { $$ = $1; }
    | STRING { $$ = $1; }
    | VOID { $$ = $1; }
;
*/
%%

/* C code section */
int main(int argc, char** argv)
{
    yylineno = 0;

    yyparse();
	printf("\nTotal lines: %d \n",yylineno);

    return 0;
}

void yyerror(char *s)
{
    char temp[256];
    memset(temp,0,sizeof(temp));
    strncpy(temp,buf,strlen(buf)-1);	//discard the unmatched token
    printf("%d: %s",++yylineno,temp);
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");
}

void create_symbol() {}
void insert_symbol() {}
int lookup_symbol() {}
void dump_symbol() {
    printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
           "Index", "Name", "Kind", "Type", "Scope", "Attribute");
}
