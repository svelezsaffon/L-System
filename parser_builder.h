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
char word[300];
char pos_equa=0;
int pos_word=0;


void add_operator(char oper){    
    array_equa[pos_equa]=oper;
    pos_equa++;
    array_equa[pos_equa]='\0';
}

 
void set_angle(float number){
    angle=number;
    printf("angle %lf\n",angle);
}

void set_iter(int number){
    iterations=number;
    printf("iter %d\n",iterations);    
}

void equation(char var){
    printf("---%c----\n",var);    
    printf(array_equa);
    printf("\n");
    printf("-------\n");
    
    
    
    int i;
    pos_equa=0;
    for(i=0;i<300;i++){
        array_equa[i]='\0';
    }
}

void add_to_word(char letter){
    word[pos_word]=letter;
    pos_word++;    
    word[pos_word]='\0';
}

void render(){
    printf("Rendering\n");
}

void axiom(){
    printf("Axiom\n");
    printf(word);
}

#ifdef	__cplusplus
}
#endif

#endif	/* PARSER_BUILDER_H */

