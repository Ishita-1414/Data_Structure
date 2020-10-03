%option noyywrap
%{
#include <stdlib.h>
/* To check if given input is a number or a word */
void display(int);
%}

%%

[a-zA-z]+ { display(1); return 1; }

[0-9]+ { display(0); return 1; }

%%

void display(int flag)
{
  if(flag==1)
	 printf("The given input [%s] is a word",yytext); 
  else
	{
		int num= atoi(yytext);
		printf("The given input [%d] is a number",num);
	}	
}

int main()
{
	printf("Enter an input to check if it is word or number");
	yylex();
	return 0;
}