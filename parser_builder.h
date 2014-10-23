/* 
 * File:   parser_builder.h
 * Author: Santiago
 *
 * Created on 18 de octubre de 2014, 18:10
 */

#ifndef PARSER_BUILDER_H
#define	PARSER_BUILDER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <string.h>

    
int iterations=1;   
float angle=90;

char array_equa[300];
char pos_equa=0;
int wherelefbra=0;
int leftbras=0;

void add_operator(char oper){    
    array_equa[pos_equa]=oper;
    pos_equa++;
    wherelefbra++;
}

 
void set_angle(float number){
    angle=number;
    printf("angle %lf\n",angle);
}

void set_iter(int number){
    iterations=number;
    printf("iter %d\n",iterations);    
}

void add_oper_at(char oper, int pos){    
    printf("Len=%d\n",pos);
    pos_equa++;    
    leftbras++;
}

void equation(char var){
    printf("---%c----\n",var);
    int i;
    printf(array_equa);
    printf("\n");
    printf("-------\n");
    pos_equa=0;
    for(i=0;i<300;i++){
        array_equa[i]='\0';
    }
    
}

void render(){
    printf("Rendering\n");
}


#ifdef	__cplusplus
}
#endif

#endif	/* PARSER_BUILDER_H */

