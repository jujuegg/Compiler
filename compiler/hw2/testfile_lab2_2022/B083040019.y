%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int yylex();
extern char token[80];
extern char FullLine[1024];
extern char errChar[5];
extern int declaretype;
char id[5][10] = {'\0'};
int type[5];
int idcount = 0;
int two_id = 0;
int flag = 0, flag2 = 0;
int Ltype,Rtype;
extern unsigned charCount, lineCount, ErrorChar, ErrorChar2;

void yyerror(const char* message) 
{
    printf("Line %2d: Syntax error, ",lineCount);
	if(!strcmp(errChar,"end"))
		printf("\".\" expected but \"end of file\" found\n");
}
void clear_FullLine()
{
	for(int i = 0 ; i < strlen(FullLine) ; ++i)
			FullLine[i] = '\0';
}
void PRINT()
{
	int flag = 0;
	for(int i = 0 ; i < strlen(FullLine) ; ++i)
		if(FullLine[i] != ' ' && FullLine[i] != '\t')
			flag = 1;
	if(flag)
	{
		printf("Line %2d: %s\n",lineCount, FullLine);
		fflush(stdout);
	}
	clear_FullLine();
}
int Var_is_Declared(char* var)
{
	for(int i = 0 ; i < 5 ; ++i)
	{
		if(!strcmp(var,id[i]))
			return 1;
	}
	return 0;
}
int DataType(char* var)
{
	for(int i = 0 ; i < 5 ; ++i)
	{
		if(!strcmp(var,id[i]))
			return type[i];
	}
	if(var[0] == '\'')
		return 4;
}
void ILL_EXP()
{
	printf("Line %2d, Char %d: Error: Illegal expression\n",lineCount, ErrorChar);
	clear_FullLine();
}
void ID_NOT_FOUND()
{
	printf("Line %2d, Char %d: Error: Identifier not found \"%s\"\n",lineCount, ErrorChar2, token);
	clear_FullLine();
}
void DeclareERR()
{
	printf("Line %2d, Char %d: Error: \":\" expected but \"%s\" found\n",lineCount, ErrorChar, errChar);
	clear_FullLine();
}
void TypeWrong(int LType, int RType, int errtype)
{
	char L[10] = {'\0'};
	char R[10] = {'\0'};
	switch(LType)
	{
		case 1: strcpy(L,"INTEGER"); break;
		case 2: strcat(L,"DOUBLE"); break;
		case 3: strcat(L,"FLOAT"); break;
		case 4: strcat(L,"STRING"); break;
	}
	switch(RType)
	{
		case 1: strcpy(R,"INTEGER"); break;
		case 2: strcat(R,"DOUBLE"); break;
		case 3: strcat(R,"FLOAT"); break;
		case 4: strcat(R,"STRING"); break;
	}
	if (errtype == 0)
		printf("Line %2d, Char %d: Error: Operator is not overloaded: \"%s\" + \"%s\"\n",lineCount, ErrorChar2, L, R);
	else if (errtype ==1)
		printf("Line %2d, Char %d: Error: Incompatible types: got \"%s\" expected \"%s\"\n",lineCount, ErrorChar2, R, L);
	clear_FullLine();
}
void MissRP(char* next)
{
	printf("\")\" expected but \"%s\" found\n",next);
	clear_FullLine();
}
void MissSMC(char* next)
{
	printf("\";\" expected but \"%s\" found\n",next);
	clear_FullLine();
}
void MissSDOT(char* next)
{
	printf("\".\" expected but \"%s\" found\n",next);
	clear_FullLine();
}
%}
%union {
    float 	floatVal;
    int 	intVal;
}
%token PLUS MINUS MUL DIV LP RP LMP RMP SEMICOLON COLON DOT COMMA ASSIGN EQ GT LT LE GE NEWLINE
%token ABSOLUTE AND BEGIN_ BREAK CASE CONST CONTINUE DO ELSE END FOR FUNCTION IF MOD NIL NOT OBJECT OF OR PROGRAM
%token THEN TO WHILE ARRAY INTEGER DOUBLE WRITE WRITELN STRING FLOAT READ VAR
%token NUMBER ID STR
%%
Program: PROGRAM ID SEMICOLON {PRINT();}NL DeclarationPart CodePart DOT {PRINT();}NL{printf("done1\n");} |
;
DeclarationPart: VAR {PRINT();}NL Declarations
;
Declarations: |
			  Declarations IDlist COLON Type  { type[idcount] = declaretype;
												if(two_id == 1){
													type[idcount-1] = declaretype;}
												++idcount; } SEMICOLON {PRINT();}NL |
			  Declarations IDlist ASSIGN {	DeclareERR();
											memset(id[idcount],0,10);
											if(two_id == 1) {memset(id[idcount-1],0,10);}	} Type SEMICOLON {clear_FullLine();} NL |
			  Declarations IDlist COLON Type error {	MissSMC(errChar);
														memset(id[idcount],0,10);
														if(two_id == 1) {memset(id[idcount-1],0,10);}	} NL
;
IDlist: ID {strcpy(id[idcount],token); two_id = 0;} |
		IDlist COMMA ID {strcpy(id[++idcount],token); two_id = 1;}
;
Type: Standardtype |
	  ARRAY LMP NUMBER DOT DOT NUMBER RMP OF Standardtype
;
Standardtype: INTEGER /*1*/|
			  DOUBLE /*2*/|
			  FLOAT /*3*/|
			  STRING /*4*/
;
CodePart: BEGIN_ {PRINT();}NL StatementList END
;
StatementList: |
			StatementList Statement {if(flag2==1){clear_FullLine();}flag2=0;}SEMICOLON {if(flag==1){clear_FullLine();}PRINT(); flag = 0;}NL |
			StatementList Expression{ILL_EXP();} SEMICOLON NL
;
Statement: SimpleStatement |
		   StructedStatement
;
StructedStatement: LoopStatement |
				   CompoundStatement |
				   ConditionalStatement	   
;
CompoundStatement: BEGIN_ {PRINT();}NL StatementList END
;
ConditionalStatement: IfStatement
;
IfStatement: IF Expression THEN {PRINT();flag2=0;}NL Statement |
			 IF Expression THEN {PRINT();}NL Statement ELSE Statement
;
LoopStatement: ForStatement
;
ForStatement: FOR ID ASSIGN Expression TO Expression DO {PRINT();}NL Statement
;
SimpleStatement: Variable {	if(!Var_is_Declared(token)){ID_NOT_FOUND();flag=1;}
							else {Ltype = DataType(token);}	} ASSIGN Expression {	if((Ltype != Rtype) && flag != 1)
																						TypeWrong(Ltype, Rtype, 1);
																					Ltype = 0; Rtype = 0;	} |
				 WriteFunction |
				 WRITELN
;
WriteFunction: WRITE LP ParameterList RP
;
ParameterList: SimpleExpression |
			   ParameterList COMMA SimpleExpression
;
Variable: ID |
	 	  ID LMP Expression RMP
;
Expression: SimpleExpression |
			SimpleExpression RelationalOperator SimpleExpression
;
RelationalOperator: EQ | GT | LT | LE | GE
;
SimpleExpression: term |
				  SimpleExpression{	if(Var_is_Declared(token))
										Ltype = DataType(token);}
				  PLUS term {	if(Var_is_Declared(token))
									Rtype = DataType(token);
									if(Ltype!=Rtype){TypeWrong(Ltype, Rtype, 0);}	} |
				  SimpleExpression MINUS term 
;
term: factor |
	  term MUL factor |
	  term DIV factor |
	  term MOD factor
	;
factor: Sign NUMBER{Rtype=1;} | STR{Rtype=4;} | group | Variable {	if(!Var_is_Declared(token))
												{
													ID_NOT_FOUND();
													flag2 = 1;
												}	}
;
group : LP Expression RP |
		LP Expression error {MissRP(errChar);} NL
;
Sign: | PLUS | MINUS
;
NL: | NLs
;
NLs: NEWLINE | NLs NEWLINE
;
%%
int main() {
    yyparse();
    return 0;
}
