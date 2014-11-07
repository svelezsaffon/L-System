%{
#include <stdio.h>
#include "y.tab.h"
%}
digit		[0-9]
char            [a-zA-Z]
left            [+]
right           "-"
pitch_up        "^"
pitch_down      [&]
roll_left       [$]
roll_right      ":"
turn            "|"
semicol         [;]
assign          "="
left_bra        "["
right_bra       "]"
angle           "angle"
iter            "iter"
axiom           "axiom"
define          "#define"
render          "render()"
name            "name"
variables       "variables"


%%
{digit}+            {yylval=atoi(yytext);return NUMBER;}
{semicol}           {return SEMICOL;}
{char}{1}           {yylval=(*yytext);return VAR_NAME;}
{left}              {yylval=(*yytext);return LEFT;}
{right_bra}         {yylval=(*yytext);return RBRA;}
{left_bra}          {yylval=(*yytext);return LBRA;}
{right}             {yylval=(*yytext);return RIGHT;}
{pitch_up}          {yylval=(*yytext);return ROT_Z_POS;}
{pitch_down}        {yylval=(*yytext);return ROT_Z_NEG;}
{roll_left}         {yylval=(*yytext);return ROT_Y_POS;}
{roll_right}        {yylval=(*yytext);return ROT_Y_NEG;}
{turn}              {yylval=(*yytext);return ROT_X;}   
{assign}            {return EQUAL;}
{angle}             {return ANGLE;}
{iter}              {return ITER;}
{define}            {return DEFINE;}
{axiom}             {return AXIOM;}
{render}            {return RENDER;}
{name}              {return NAME;}
{variables}         {return VARIABLES;}
.                   {} 		
%%

int yyerror(char *s)
{
	fprintf(stderr,"%s\n",s);                
	return 1;
}
int yywrap(){
	return 1;
}
