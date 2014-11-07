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
char final_equa[2000];
char aux_final[2000];
char *tree_word;
char *defvar;
char *axiom_word;
int name_is_set=0;
unsigned int num_equations=0;

char *result_equa;

void add_operator(char oper){
    sprintf(array_equa, "%s%c", array_equa,oper);
}

void free_memory(){
    free(axiom_word);
    free(tree_word);    
}

unsigned int axiom_contains(char var){
    unsigned int contains=0;
    unsigned int i=0;
    unsigned int size=strlen(defvar);
    while(!contains && i<size){
        if(defvar[i]==var){
            contains=1;
        }else{
            i++;
        }
    }
    
    return contains;
}

unsigned int give_rule(char var){
    int i=0;
    unsigned int flag=0;
    while(1<20 && !flag){
        if(rules[i][0]==var){
            flag=1;
        }else{
            i++;
        }
    }

    
    return i;
}

 
void set_angle(float number){
    angle=number;    
}

void set_iter(int number){
    iterations=number;    
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
    sprintf(word, "%s%c", word,letter);    
}

void axiom(){    
    axiom_word=(char *)calloc(strlen(word),sizeof(char));    
    sprintf(axiom_word, "%s", word);
    memset (word,'\0',strlen(word));    
}

void tree_name(){
    tree_word=(char *)calloc(strlen(word),sizeof(char));    
    sprintf(tree_word, "%s", word);
    memset (word,'\0',strlen(word));    
    name_is_set=1;
}

void variables(){    
    defvar=(char *)calloc(strlen(word),sizeof(char));    
    sprintf(defvar, "%s", word);    
    memset (word,'\0',strlen(word));
}


void render(){
        
    if(iterations){
        printf("Rendering\n");
        
        aux_final[0]='\0';
        final_equa[0]='\0';
        
        FILE *f ;
        
        if(name_is_set){
            f=fopen(tree_word, "w");
        }else{
            //fix this to a better output
            f=fopen("tree.h", "w");
        }
        unsigned int i;
        unsigned int len=strlen(axiom_word);
        
        fprintf(f,"%s|", tree_word);
        fprintf(f,"%s|", defvar);
        fprintf(f,"%s|", axiom_word);
        fprintf(f,"%d|", iterations);
        fprintf(f,"%lf|", angle);
        
        for(i=0;i<1;i++){
            fprintf(f,"%s|", rules[i]);
        }
        
        for(i=0;i<len;i++){
            if((axiom_word[i] >= 'a' && axiom_word[i]<='z') || (axiom_word[i]>='A' && axiom_word[i]<='Z') ){                
                sprintf(aux_final, "%s%s", aux_final,rules[give_rule(axiom_word[i])]+1);                                
            }else{
                sprintf(aux_final, "%s%c", aux_final,axiom_word[i]);
            }
            
        }
        
        iterations--;        
        
        if(!iterations){
            sprintf(final_equa, "%s", aux_final);
        }
        
        while(iterations){
            
            len=strlen(aux_final);
            final_equa[0]=='\0';
            
            for(i=0;i<len;i++){
                if((aux_final[i] >= 'a' && aux_final[i]<='z') || (aux_final[i]>='A' && aux_final[i]<='Z') ){                
                    sprintf(final_equa, "%s%s", final_equa,rules[give_rule(aux_final[i])]+1);                                
                }else{
                    sprintf(final_equa, "%s%c", final_equa,aux_final[i]);
                }
            }
            strcpy(aux_final,final_equa);
            aux_final[strlen(final_equa)+1]='\0';
            iterations--;
            if(iterations){
                memset (final_equa,'\0',strlen(final_equa));
            }
        }
        
        
        fprintf(f, final_equa);
        
        fclose(f);
        free_memory();        
    }
    
   
}

#ifdef	__cplusplus
}
#endif

#endif	/* PARSER_BUILDER_H */

