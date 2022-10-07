%{
#include<stdio.h>
unsigned charCount = 1, idCount = 0, lineCount = 1;
%}

space [ \t]
eol \n
reserved_word [aA][bB][sS][oO][lL][uU][tT][eE]|[aA][nN][dD]|[bB][eE][gG][iI][nN]|[bB][rR][eE][aA][kK]|[cC][aA][sS][eE]|[cC][oO][nN][sS][tT]|[cC][oO][nN][tT][iI][nN][uU][eE]|[dD][oO]|[eE][lL][sS][eE]|[eE][nN][dD]|[fF][oO][rR]|[fF][uU][nN][cC][tT][iI][oO][nN]|[iI][fF]|[mM][oO][dD]|[nN][iI][lL]|[nN][oO][tT]|[oO][bB][jJ][eE][cC][tT]|[oO][fF]|[oO][rR]|[pP][rR][oO][gG][rR][aA][mM]|[tT][hH][eE][nN]|[tT][oO]|[vV][aA][rR]|[wW][hH][iI][lL][eE]|[aA][rR][rR][aA][yY]|[iI][nN][tT][eE][gG][eE][rR]|[dD][oO][uU][bB][lL][eE]|[wW][rR][iI][tT][eE]|[wW][rR][iI][tT][eE][lL][nN]|[sS][tT][rR][iI][nN][gG]|[fF][lL][oO][aA][tT]|[rR][eE][aA][dD]

invalid_string '[^'\n;]*
quoted_string '([^\n']*('')*)*'

invalid_id {real_number}+{id}|[^ _a-zA-Z\t\r\n;:\(\)\[\]<>=\+\-\*\/\.,=']+{id}|^{symbol}+{id}
id [_a-zA-Z][_a-zA-Z0-9]*

invalid_comment \(\*\)|([^*\n]|(\*+[^*)]))*\*+\)|\(\*([^*]|[\n]|(\*+([^*)]|[\n])))*
comment \(\*([^*]|[\n]|(\*+([^*)]|[\n])))*\*+\)

symbol [;:\(\)\[\]<>=\+\-\*\/\.,]|:=|==|<=|>=

invalid_real 0{integer}\.?|0{float}\.?|{integer}\.|{float}\.{real_number}|\.{real_number}
integer [-]?[1-9][0-9]*
float {integer}\.[0-9]+
real_number ({integer}|{float})([eE][+-][0-9]+)?

%%

{reserved_word}	{
	printf("Line: %d, 1st char: %d, \"%s\" is a \"reserved word\".\n", lineCount, charCount, yytext);
	charCount += yyleng;
}
{comment}	{
	int i;
	printf("Line: %d, 1st char: %d, \"%s\" is a \"comment\".\n", lineCount, charCount, yytext);
	for(i = 0 ; i < yyleng ; ++i)
	{
		++charCount;
		if(yytext[i] == '\n')
		{
			lineCount++;
			charCount = 1;
		}
	}
}
{invalid_comment}	{
	int i; 
	printf("Line: %d, 1st char: %d, \"%s\" is an invalid \"comment\".\n", lineCount, charCount, yytext);
	for(i = 0 ; i < yyleng ; ++i)
	{
		++charCount;
		if(yytext[i] == '\n')
		{
			lineCount++;
			charCount = 1;
		}
	}
} 
{symbol} {
	printf("Line: %d, 1st char: %d, \"%s\" is a \"symbol\".\n", lineCount, charCount, yytext);
	charCount += yyleng;
}
{id}	{
	if(yyleng <= 15)
	{
		printf("Line: %d, 1st char: %d, \"%s\" is an \"ID\".\n", lineCount, charCount, yytext);
		idCount += 1;
	}
	else
		printf("Line: %d, 1st char: %d, \"%s\" is an invalid \"ID\".\n", lineCount, charCount, yytext);
	charCount += yyleng;
}
{invalid_id}	{
	printf("Line: %d, 1st char: %d, \"%s\" is an invalid \"ID\".\n", lineCount, charCount, yytext);
	charCount += yyleng;
}
{quoted_string}	{
	int i,j;
	yytext[yyleng-1] = '\0';
	for(i = 1 ; i < yyleng-2 ; ++i)
		if(yytext[i]=='\'' && yytext[i+1]=='\'')
			for(j = i+1 ; j < yyleng-1 ; j++)
				yytext[j] = yytext[j+1];
	if(yyleng <= 32)
		printf("Line: %d, 1st char: %d, \"%s\" is a \"quoted string\".\n", lineCount, charCount, yytext+1);
	else
		printf("Line: %d, 1st char: %d, \"%s\" is an invalid \"string\".\n", lineCount, charCount, yytext+1);
	charCount += yyleng;
}
{invalid_string}	{
	printf("Line: %d, 1st char: %d, \"%s\" is an invalid \"string\".\n", lineCount, charCount, yytext);
	charCount += yyleng;
}
{integer}	{
	printf("Line: %d, 1st char: %d, \"%s\" is a \"real number\".\n", lineCount, charCount, yytext);
	charCount += yyleng;
}
{real_number}|{float}	{
	if(yytext[yyleng-1] == '0' && yytext[yyleng-2] == '0')
		printf("Line: %d, 1st char: %d, \"%s\" is an invalid \"real number\".\n", lineCount, charCount, yytext);
	else
		printf("Line: %d, 1st char: %d, \"%s\" is a \"real number\".\n", lineCount, charCount, yytext);
	charCount += yyleng;
}
{invalid_real}	{
	printf("Line: %d, 1st char: %d, \"%s\" is an invalid \"real number\".\n", lineCount, charCount, yytext);
	charCount += yyleng;
}
{space} {
	charCount++;
}
{eol}   {
	lineCount++;
	charCount = 1;
}
%%
int main(){
	yylex();
	return 0;
 }
