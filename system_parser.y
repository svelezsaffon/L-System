%{
#include <stdio.h>
#include "parser_builder.h"

extern FILE * yyin;

/*Set number of iterations*/
int isaxiom=1;

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
%token  DEFINE
%token  AXIOM
%token  NAME
%token VARIABLES

%%

l_system    :
            list_definitions axiom equations RENDER SEMICOL {render();}                                    
            |axiom equations RENDER SEMICOL {render();}

axiom       :
            AXIOM EQUAL word SEMICOL    {isaxiom=0;axiom();}

equations   :
            equations equation
            |equation

equation    :                               
            VAR_NAME EQUAL expression SEMICOL   {int res; res=equation($1); if(!res){yyerror("Undefined constant in rule");};}   

expression  :
            expression word                 
            |expression operator    
            |operator
            |word

word        :
            word VAR_NAME           {(isaxiom==1) ? add_to_word($2):add_operator($2);}
            |VAR_NAME               {(isaxiom==1) ? add_to_word($1):add_operator($1);}

operator    :
            LEFT                    {add_operator($1);}
            |RIGHT                  {add_operator($1);}
            |ROT_Z_POS              {add_operator($1);}              
            |ROT_Z_NEG              {add_operator($1);}
            |ROT_Y_POS              {add_operator($1);}
            |ROT_Y_NEG              {add_operator($1);}
            |ROT_X                  {add_operator($1);}            
            |LBRA                   {add_operator($1);}
            |RBRA                   {add_operator($1);}

list_definitions    :
                    list_definitions define
                    |define

define  :
        DEFINE ANGLE EQUAL NUMBER SEMICOL  {set_angle($4);}
        |DEFINE ITER EQUAL NUMBER SEMICOL  {set_iter($4);}
        |DEFINE NAME EQUAL word SEMICOL    {tree_name();}
        |DEFINE VARIABLES EQUAL word SEMICOL {variables();};
%%

main(argc, argv)
int argc;
char **argv;
{

	FILE *f = fopen("tree.svs", "r");
  
	if(!f) {
		printf("I can't open your file :( \n"	);
		return (1);
	}
	yyin=f;

	yyparse();

        fclose(f);
        
	return 0;
}
