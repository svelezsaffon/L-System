/*
C++ stuff
*/
#include <stack>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string.h>
#include "Helper.h"
/*
C stuff
*/
#include<string.h>

using namespace std;

class SmallTree
{
public:	
	SmallTree();
	~SmallTree();	
	void add_branch();
	void init_variables();
	void vizualize_opengl();
	void set_structur(char *inst);
	void create();
	int sign(float value);
	void update_direction(float *point,float angle);
	void update_translate();
	vector<branch> get_branches();
private:
	stack<branch> back;
	char inst[6253];
	float angle = 90.000000;
	vector<branch> structure;
	
	//This vector gives me the previous point
	float previous[4];

	unsigned int first_branch = 1;
	//This is the vector that gives me the new point
	float writer[4];

	//this vector will help me with the translation
	float trans[4];

	float magnitude = 0.05;

	float direction[4];

	branch last;
	
float decrese=1.000000;

	void xrotation(int sign);
	void yrotation(int sign);
	void zrotation(int sign);
	void copy_last();
	void translate();
	
};


void SmallTree::init_variables(){
	float start = 0.0;
	previous[0] = start;
	previous[1] = start;
	previous[2] = start;
	previous[3] = start;

	direction[0] = start ;
	direction[1] = 1 ;
	direction[2] = start ;
	direction[3] = start;

	trans[0] = start;
	trans[1] = start;
	trans[2] = start;
	trans[3] = start;

	writer[0] = start;
	writer[1] = start;
	writer[2] = start;
	writer[3] = start;
}

void SmallTree::set_structur(char *insts){
	int len = strlen(insts);
	
	for(int i = 0; i < len; i++){
		this->inst[i] = insts[i];
	}
	
	inst[len] = '\0';
}

SmallTree::SmallTree(){
	init_variables();
strcpy_s(inst,6253,"F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F");
}

SmallTree::~SmallTree()
{
}

vector<branch> SmallTree::get_branches(){
	return this->structure;
}

void SmallTree::update_translate(){
	if (direction[0] != 0){
		this->trans[0] = magnitude * this->sign(direction[0]);
	}
	if (direction[1] != 0){
		this->trans[1] = magnitude * this->sign(direction[1]);
	}
	if (direction[2] != 0){
		this->trans[2] = magnitude *this->sign(direction[2]);
	}
}


void SmallTree::create(){	
	unsigned int pos = 0;
	while (pos < strlen(this->inst)){	

		char aux = this->inst[pos];

		if (aux == '+'){
			this->xrotation(1);
			this->copy_last();
		}
		else if (aux =='-' ){
			this->xrotation(-1);			
			this->copy_last();
		}
		else if (aux == '&'){
			this->yrotation(1);
			this->copy_last();
		}
		else if (aux == '$'){
			this->yrotation(-1);
			this->copy_last();
		}
		else if (aux == ':'){
			this->zrotation(1);			
			this->copy_last();
		}
		else if (aux == '|'){			
			this->zrotation(-1);
			this->copy_last();
		}
		else if (aux == '['){
			branch aux(this->last.begin, this->last.end, this->last.trans);
			aux.decrease = magnitude;
			this->back.push(aux);
		
		}
		else if (aux == ']'){
			branch aux = this->back.top();
			this->last.copy_all(aux.begin, aux.end, aux.trans);
			this->back.pop();
			this->writer[0] = aux.end[0];
			this->writer[1] = aux.end[1];
			this->writer[2] = aux.end[2];
			

			this->previous[0] = aux.end[0];
			this->previous[1] = aux.end[1];
			this->previous[2] = aux.end[2];
			
			this->direction[0] = (aux.trans[0] != 0) ? 1*sign(direction[0]) : 0;
			this->direction[1] = (aux.trans[1] != 0) ? 1 * sign(direction[1]) : 0;
			this->direction[2] = (aux.trans[2] != 0) ? 1 * sign(direction[2]) : 0;
			
			this->trans[0] = 0;
			this->trans[1] = 0;
			this->trans[2] = 0;
			magnitude = aux.decrease;			

		}
		
		else if ((aux >= 'a' && aux <= 'z') || (aux >= 'A' && aux <= 'Z')){
			this->update_translate();			
			this->translate();
			this->copy_last();
			this->add_branch();
		}

		pos++;
		
	}
}

void SmallTree::copy_last(){
	this->last.copy_begin(previous);
	this->last.copy_end(writer);
	this->last.trans[0] = this->trans[0];
	this->last.trans[1] = this->trans[1];
	this->last.trans[2] = this->trans[2];
}


void SmallTree::add_branch(){
	branch bra;
	bra.copy_begin(previous);
	bra.copy_end(writer);
	bra.trans[0] = this->trans[0];
	bra.trans[1] = this->trans[1];
	bra.trans[2] = this->trans[2];
	previous[0] = writer[0];
	previous[1] = writer[1];
	previous[2] = writer[2];
	this->structure.push_back(bra);
}


void SmallTree::translate(){
	if (direction[0] == 0 && direction[2] == 0 && direction[1] != 0){
		if (writer[0] == 0 && writer[2] == 0 && writer[1] != 0){
			magnitude = magnitude *decrese;
		}
	}
for (int i = 0; i < 3; i++){
	this->writer[i] = this->writer[i] + trans[i];
}	
	
}

int SmallTree::sign(float value){
	if (value >= 0)
		return 1;
	else
		return -1;
}


void SmallTree::xrotation(int sign){
	float auxangle = this->angle*sign;
	float rotmat[4][4];
	float newpoint[4] = {0.0,0.0,0.0,0.0};
	for (int i = 0; i < 4; i++){
		
		for (int j = 0; j < 4; j++){
			if (i == 0 && j == 0){
				rotmat[i][j] = 1;
			}
			else if (i==j && i<3 ){
				rotmat[i][j] = cos_svs(auxangle);
			}
			else if (i == j && i == 3){
				rotmat[i][j] = 1;
			}
			else if (i==1 && j==2){
				
				rotmat[i][j] = -sin_svs(auxangle);
			}else if (i == 2 && j == 1){
				rotmat[i][j] = sin_svs(auxangle);
			}
			else{
				rotmat[i][j] = 0;
			}
			newpoint[i] += rotmat[i][j] * this->direction[j];
		}
	}

	this->update_direction(newpoint,auxangle);

}

void SmallTree::zrotation(int sign){
	float auxangle = this->angle*sign;
	float rotmat[4][4];
	float newpoint[4] = { 0.0, 0.0, 0.0, 0.0 };

	for (int i = 0; i < 4; i++){
		
		for (int j = 0; j < 4; j++){
			if (i == j && i<2){
				rotmat[i][j] = cos_svs(auxangle);
			}
			else if (i == j && i >= 2){
				rotmat[i][j] = 1;
			}
			else if (i == 0 && j == 1){
				rotmat[i][j] = -sin_svs(auxangle);
			}else if (i == 1 && j == 0){
				rotmat[i][j] = sin_svs(auxangle);
			}else{
				rotmat[i][j] = 0;
			}
			newpoint[i] += rotmat[i][j] * this->direction[j];
		}
	}
	
	this->update_direction(newpoint, auxangle);
	
}



void SmallTree::yrotation(int sign){
	float auxangle = this->angle*sign;
	float rotmat[4][4];
	float newpoint[4] = { 0.0, 0.0, 0.0, 0.0 };
	for (int i = 0; i < 4; i++){
		
		for (int j = 0; j < 4; j++){
			if (i == j){
				if (i == 0 || i==2){
					rotmat[i][j] = cos_svs(auxangle);
				}
				else if (i == 1 || i==3){
					rotmat[i][j] = 1;
				}
			}
			else if (j==2 && i==0){
				rotmat[i][j] = sin_svs(auxangle);
			}
			else if (j==0 && i==2){
				rotmat[i][j] = -sin_svs(auxangle);
			}
			else{
				rotmat[i][j] = 0;
			}
			newpoint[i] += rotmat[i][j] * this->direction[j];
		}
	}

	this->update_direction(newpoint,auxangle);
}

void SmallTree::update_direction(float *newpoint,float angle){
	this->trans[0] = 0;
	this->trans[1] = 0;
	this->trans[2] = 0;
	this->trans[3] = 0;

	this->direction[0] = newpoint[0];
	this->direction[1] = newpoint[1];
	this->direction[2] = newpoint[2];
	this->direction[3] = newpoint[3];

}
