%{
#include <stdio.h>
#include "parser_builder.h"

extern FILE * yyin;

/*Set number of iterations*/


%}

%token	RIGHT
%token	LEFT
%token	EQUAL
%token	ROT_Z_POS
%token	ROT_Z_NEG
%token	ROT_Y_POS
%token	ROT_Y_NEG
%token	ROT_X
%token  VAR_NAME
%token  SEMICOL
%token  ANGLE
%token  NUMBER
%token  RBRA
%token  LBRA
%token  ITER
%token  RENDER
%%

lis_equations:
            lis_equations equation
            |lis_equations angle
            |lis_equations iter
            |equation
            |angle
            |iter

equation    :                               
            VAR_NAME EQUAL expression SEMICOL   {equation($1);}   

expression  :
            expression VAR_NAME            
            |expression operator
            |VAR_NAME
            |operator                        

operator    :
            LEFT                    {add_operator($1);}
            |RIGHT                  {add_operator($1);}
            |ROT_Z_POS              {add_operator($1);}              
            |ROT_Z_NEG              {add_operator($1);}
            |ROT_Y_POS              {add_operator($1);}
            |ROT_Y_NEG              {add_operator($1);}
            |ROT_X                  {add_operator($1);}            
            |LBRA expression RBRA   {$$=$2;add_operator($3);}
            
angle       :
            ANGLE EQUAL NUMBER SEMICOL  {set_angle($3);}

iter        :
            ITER EQUAL NUMBER SEMICOL  {set_iter($3);}

%%

main(argc, argv)
int argc;
char **argv;
{
	yyparse();

	return 0;
}
