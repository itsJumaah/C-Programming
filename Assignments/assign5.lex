%option noyywrap
%{
	#include<stdio.h>
	#include<stdlib.h>
%}
%% 
	[-=+]							{printf("operator %s read\n", yytext);}
	[-+]?[0-9]+					{printf("integer %s read\n", yytext);}
	[-+]?[0-9]+"."[0-9]*		{printf("decimal %s read\n", yytext);}
	[-+]?[0-9]*"."[0-9]+		{printf("decimal %s read\n", yytext);}
	[-+]?[0-9]+"."[0-9]*[Ee][-+]?[0-9]*		{printf("floating point number %s read\n", yytext);}
	[-+]?[0-9]+"."[0-9]*[Ee][-+]?[0-9]+		{printf("floating point number %s read\n", yytext);}
	int		{printf("keyword %s read\n", yytext);}
	float		{printf("keyword %s read\n", yytext);}
	if			{printf("keyword %s read\n", yytext);}
	switch	{printf("keyword %s read\n", yytext);}
	while		{printf("keyword %s read\n", yytext);}
	for		{printf("keyword %s read\n", yytext);}
	[_a-zA-Z][_a-zA-Z0-9]*		{printf("variable %s read\n", yytext);}
	[ \n\t]+		{}
	.		{printf("error :%s:\n",yytext); exit(1);}
%%
int main() {
   yylex();
}
