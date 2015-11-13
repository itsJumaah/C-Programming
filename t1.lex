%option noyywrap
%{
   int i;
%}

%% /*place rules here*/
peter	{printf("the greatest");}
ca(t|d)og {printf("cat or dog");}
[-+]?[0-9]+ {i = atoi(yytext);printf("%d", i+1);}
%%

/*place your C code here*/
int main() {
   yylex(); //call flex
}
