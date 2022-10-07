%{
#include "y.tab.h"
#include <stdio.h>
#include <string.h>
int i=1;
int declaretype = 0;
char token[80];
char errChar[5];
char FullLine[1024] = {'\0'};
unsigned charCount = 1, lineCount = 1, ErrorChar, ErrorChar2;
void PUSH()
{
	charCount += yyleng;
	strcat(FullLine,yytext);
}
%}
integer [1-9][0-9]*
Digit [0-9]+
Space [ \t]
comment \(\*([^*]|[\n]|(\*+([^*)]|[\n])))*\*+\)
id [_a-zA-Z][_a-zA-Z0-9]*
quoted_string '([^\n']*('')*)*'

%%
[aA][bB][sS][oO][lL][uU][tT][eE]	{PUSH(); return ABSOLUTE;}
[aA][nN][dD]						{PUSH(); return AND;}
[bB][eE][gG][iI][nN]				{strcpy(errChar,yytext); PUSH(); return BEGIN_;}
[bB][rR][eE][aA][kK]				{PUSH(); return BREAK;}
[cC][aA][sS][eE]					{PUSH(); return CASE;}
[cC][oO][nN][sS][tT]				{PUSH(); return CONST;}
[cC][oO][nN][tT][iI][nN][uU][eE]	{PUSH(); return CONTINUE;}
[dD][oO]							{PUSH(); return DO;}
[eE][lL][sS][eE]					{PUSH(); return ELSE;}
[eE][nN][dD]						{strcpy(errChar,yytext); PUSH(); return END;}
[fF][oO][rR]						{PUSH(); return FOR;}
[fF][uU][nN][cC][tT][iI][oO][nN]	{PUSH(); return FUNCTION;}
[iI][fF]							{PUSH(); return IF;}
[mM][oO][dD]						{PUSH(); return MOD;}
[nN][iI][lL]						{PUSH(); return NIL;}
[nN][oO][tT]						{PUSH(); return NOT;}
[oO][bB][jJ][eE][cC][tT]			{PUSH(); return OBJECT;}
[oO][fF]							{PUSH(); return OF;}
[oO][rR]							{PUSH(); return OR;}
[pP][rR][oO][gG][rR][aA][mM]		{PUSH(); return PROGRAM;}
[tT][hH][eE][nN]					{strcpy(errChar,yytext); PUSH(); return THEN;}
[tT][oO]							{PUSH(); return TO;}
[vV][aA][rR]						{PUSH(); return VAR;}
[wW][hH][iI][lL][eE]				{PUSH(); return WHILE;}
[aA][rR][rR][aA][yY]				{PUSH(); return ARRAY;}
[iI][nN][tT][eE][gG][eE][rR]		{PUSH(); declaretype=1; return INTEGER;}
[dD][oO][uU][bB][lL][eE]			{PUSH(); declaretype=2; return DOUBLE;}
[wW][rR][iI][tT][eE]				{PUSH(); return WRITE;}
[wW][rR][iI][tT][eE][lL][nN]		{PUSH(); return WRITELN;}
[sS][tT][rR][iI][nN][gG]			{PUSH(); declaretype=4; return STRING;}
[fF][lL][oO][aA][tT]				{PUSH(); declaretype=3; return FLOAT;}
[rR][eE][aA][dD]					{PUSH(); return READ;}
{Digit}		{PUSH(); return NUMBER;}
\+	{PUSH(); return PLUS;}
\-	{PUSH(); return MINUS;}
\*	{PUSH(); return MUL;}
\/	{PUSH(); return DIV;}
\=	{ErrorChar = charCount; PUSH(); return EQ;}
\>	{PUSH(); return GT;}
\<	{PUSH(); return LT;}
\<=	{PUSH(); return LE;}
\>=	{PUSH(); return GE;}
\(	{PUSH(); return LP;}
\)	{PUSH(); return RP;}
\[	{PUSH(); return LMP;}
\]	{PUSH(); return RMP;}
:=	{strcpy(errChar,yytext); ErrorChar = charCount; PUSH(); return ASSIGN;}
\;	{ErrorChar = charCount; PUSH(); return SEMICOLON;}
\:	{PUSH(); return COLON;}
\.	{strcpy(errChar,yytext); PUSH(); return DOT;}
\,	{PUSH(); return COMMA;}
\n	{ ++lineCount; charCount = 1; return NEWLINE; }
\r	{;}
{Space} { PUSH(); }
{id}	{
	ErrorChar2 = charCount;
	PUSH(); 
	for (int i = 0 ; i < 80 ; ++i)
		token[i] = 0;
	strcpy(token,yytext);
	return ID;
}
{comment}	{
	int i;
	for(i = 0 ; i < yyleng ; ++i)
	{
		++charCount;
		if(yytext[i] == '\n')
		{
			lineCount++;
			charCount = 1;
		}
	}
	for(int i = 0 ; i < strlen(FullLine) ; ++i)
		FullLine[i] = '\0';
}
{quoted_string}	{
	PUSH(); 
	int i,j;
	yytext[yyleng-1] = '\0';
	for(i = 1 ; i < yyleng-2 ; ++i)
		if(yytext[i]=='\'' && yytext[i+1]=='\'')
			for(j = i+1 ; j < yyleng-1 ; j++)
				yytext[j] = yytext[j+1];
	return STR;
}
.	{return yytext[0];}
%%

int yywrap(){
    return 1;
}
