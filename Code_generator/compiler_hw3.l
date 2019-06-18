/* Definition section */
%{
#include <stdio.h>
#include <stdbool.h>
#include "y.tab.h"	/* header file generated by bison */

#define BUF_SIZE 256

extern void Sem_Err();

extern YYSTYPE yylval; //YYSTYPE
extern int Error,Scope,Function_status,dump_flag;
extern int Index[10];
extern void dump_symbol(int);
char buf[BUF_SIZE];

/* This macro is used to record code line */
#define CONCAT { strncat(buf, yytext, BUF_SIZE - strlen(buf) - 1); }
%}

/* Define regular expression label */
digit		[0-9]
letter		[a-zA-Z]
integer     {digit}+
float       {digit}+"."{digit}+
id			{letter}+({letter}|{digit})*

%option yylineno

/* used for the tag latter*/
%x COMMENT STRING_STATE

/* Rules section */
%%

 /* Arithmetic */
"+"     { CONCAT return ADD; }
"-" 	{ CONCAT return SUB; }
"*" 	{ CONCAT return MUL; }
"/" 	{ CONCAT return DIV; }
"%"     { CONCAT return MOD; }
"++"    { CONCAT return INC; }
"--"    { CONCAT return DEC; }

 /* Relational */
">"	{ CONCAT return MT; }
"<"	{ CONCAT return LT; }
">="	{ CONCAT return MTE; }
"<="	{ CONCAT return LTE; }
"=="	{ CONCAT return EQ; }
"!="	{ CONCAT return NE; }

 /* Assignment */
"="	{ CONCAT return ASGN; }
"+="	{ CONCAT return ADDASGN; }
"-="	{ CONCAT return SUBASGN; }
"*="	{ CONCAT return MULASGN; }
"/="	{ CONCAT return DIVASGN; }
"%="	{ CONCAT return MODASGN; }

 /* Logical */
"&&"	{ CONCAT return AND; }
"||"	{ CONCAT return OR; }
"!"	{ CONCAT return NOT; }

 /* Delimiters */
"("	{ CONCAT return LB; }
")"	{ CONCAT return RB; }
"{"	{ CONCAT return LCB; }
"}"	{ CONCAT return RCB; }
"["	{ CONCAT return LSB; }
"]"	{ CONCAT return RSB; }
","	{ CONCAT return COMMA; }

 /* Print Keywords */	
"print"		{ CONCAT return PRINT; }

 /* Condition and Loop Keywords */
"if"		{ CONCAT return IF; }
"else"		{ CONCAT return ELSE; }
"for"		{ CONCAT return FOR; }
"while"		{ CONCAT return WHILE; }
"return"    	{ CONCAT return RET; }
"continue"  	{ CONCAT return CONT; }
"break"     	{ CONCAT return BREAK; }

 /* Declaration Keywords */
"void"		{ CONCAT yylval.string=strdup(yytext); return VOID; }
"int"		{ CONCAT yylval.string=strdup(yytext); return INT; }
"float"  	{ CONCAT yylval.string=strdup(yytext); return FLOAT; }
"string"  	{ CONCAT yylval.string=strdup(yytext); return STRING; }
"bool"  	{ CONCAT yylval.string=strdup(yytext); return BOOL; }

 /* boolean Keywords */
"true"      { CONCAT return TRUE; }
"false"     { CONCAT return FALSE; }

 /* String Constant */
\"			{ BEGIN STRING_STATE; CONCAT }
<STRING_STATE>\"	{ BEGIN INITIAL; CONCAT return STR_CONST;}
<STRING_STATE>[^"]*	{ CONCAT }

 /* Number Constant */
{integer}	{ CONCAT; yylval.i_val=atoi(yytext); return I_CONST; }
{float}		{ CONCAT; yylval.f_val=atof(yytext); return F_CONST; }

 /* C type Comment */
"/*"			{ BEGIN COMMENT; CONCAT }
<COMMENT>[^*\n]+	{ CONCAT }
<COMMENT>\n		{ CONCAT printf("%d: %s",yylineno,buf); memset(buf,0,sizeof(buf));}
<COMMENT>"*"		{ CONCAT }
<COMMENT>"*/"		{ BEGIN INITIAL; CONCAT return C_COMMENT;}

 /* C++ type Comment */
\/\/.*	{ CONCAT return CPP_COMMENT; }

 /* Variable ID */
 {id}       { CONCAT yylval.string=strdup(yytext); return ID; }

 /* others */

[;]		{ CONCAT return SEMICOLON; }
[\n]		{ CONCAT if(buf[0]=='\n') printf("%d:\n",yylineno); else printf("%d: %s",yylineno,buf); 
			if(Error!=0){	//no error
				Sem_Err();
			}
			Error=0;
			memset(buf,0,sizeof(buf));
			if(dump_flag==1){
				dump_symbol(Index[Scope]);
				dump_flag=0;
			}
		}
[ \t]		{ CONCAT } /* Ignore */
[^ \t\n]	{ CONCAT } /* Ignore other charactor sets */
<<EOF>>		{ yyterminate();}

%%

int yywrap()
{
    return 1;
}