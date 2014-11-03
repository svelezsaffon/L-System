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
#include <stdio.h>
#include <stdlib.h>

    
int iterations=1;   
float angle=90;

char array_equa[300];
char word[300];
char pos_equa=0;
int pos_word=0;

char *rules[20];
char *tree_word;
char *axiom_word;
unsigned int num_equations=0;


void add_operator(char oper){    
    array_equa[pos_equa]=oper;
    pos_equa++;
    array_equa[pos_equa]='\0';
}

void free_memory(){
    free(axiom_word);
    free(tree_word);    
}

unsigned int axiom_contains(char var){
    unsigned int contains=0;
    unsigned int i=0;
    unsigned int size=strlen(axiom_word);
    while(!contains && i<size){
        if(axiom_word[i]==var){
            contains=1;
        }else{
            i++;
        }
    }
    
    return contains;
}
 
void set_angle(float number){
    angle=number;
    printf("angle %lf\n",angle);
}

void set_iter(int number){
    iterations=number;
    printf("iter %d\n",iterations);    
}




unsigned int equation(char var){
    
    unsigned int good=0;
    int cont=axiom_contains(var);
    int len=strlen(array_equa);
    int i;
    char aux;
    for(i=0;i<len;i++){
        aux=array_equa[i];
        if((aux >= 'a' && aux <='z') || (aux >= 'A' && aux <='Z') ){
            cont*=axiom_contains(array_equa[i]);
        }
    }
    
    if(cont){
        rules[num_equations]=(char *)calloc(len+1,sizeof(char));
        rules[num_equations][0]=var;        
        sprintf(rules[num_equations]+1, "%s", array_equa);
        
        good=1;
        num_equations++;
        
        for(i=0;i<num_equations;i++){
            printf("%s\n",rules[i]);
        }
    }else{        
        free_memory();
    }
    
    
    pos_equa=0;
    for(i=0;i<300;i++){
        array_equa[i]='\0';
    }
    
    return good;
}



void add_to_word(char letter){
    word[pos_word]=letter;
    pos_word++;    
    word[pos_word]='\0';
}

void render(){
    printf("Rendering\n");
    free_memory();
}

void axiom(){
    printf("Axiom\n");    
    axiom_word=(char *)calloc(strlen(word),sizeof(char));    
    strcpy(axiom_word,word);
    printf("%s",axiom_word);
    
    
    int i=0;
    for(i=0;i<300;i++){
        word[i]='\0';
    }
    pos_word=0;
}

void tree_name(){

    tree_word=(char *)calloc(strlen(word),sizeof(char));    
    strcpy(tree_word,word);


    printf("Name\n");
    printf("%s",tree_word);
    
    
    int i=0;
    for(i=0;i<300;i++){
        word[i]='\0';
    }
    pos_word=0;
}


#ifdef	__cplusplus
}
#endif

#endif	/* PARSER_BUILDER_H */

