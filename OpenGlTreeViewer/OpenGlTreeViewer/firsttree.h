/*
C++ stuff
*/
#include <stack>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string.h>
/*
C stuff
*/
#include<string.h>
/*
OpenGL and Glut Stuff
*/

#define PI 3.141592654
#define DIR_MAG 1

using namespace std;

int cont = 0;
int color[3] = {255,0,0};

class branch
{
public:
	branch();
	~branch();
	float begin[3];
	float end[3];
	float trans[3];
	
	void copy_begin(float *);
	void copy_end(float *);
private:

};

branch::branch()
{
}

branch::~branch()
{
}

void branch::copy_begin(float *point){
	this->begin[0] = point[0];
	this->begin[1] = point[1];
	this->begin[2] = point[2];
}

void branch::copy_end(float *point){
	this->end[0] = point[0];
	this->end[1] = point[1];
	this->end[2] = point[2];
}

class Tree
{
public:
	Tree(char *inst);
	Tree();
	~Tree();	
	void add_branch();
	void init_variables();
	void vizualize_opengl();
	void set_structur(char *inst);
	void create();
	int sign(float value);
	void update_direction(float *point,float angle);
	vector<branch> get_branches();
private:
	stack<branch> back;
	char inst[63];
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

	void xrotation(int sign);
	void yrotation(int sign);
	void zrotation(int sign);
	void copy_last();
	void translate();
	
};

float cos_svs(float angle){
	angle = angle*PI / 180.0; // To radians
	float value = cos(angle);
	if (abs(value) < 0.0000001){
		value = 0.0;
	}

	return value;
}


float sin_svs(float angle){
	angle = angle*PI / 180.0; // To radians
	float value = sin(angle);
	if (abs(value) < 0.0000001){
		value = 0.0;
	}

	return value;
}


void Tree::init_variables(){
	float start = 0.0;
	previous[0] = start;
	previous[1] = start;
	previous[2] = start;
	previous[3] = start;

	direction[0] = start ;
	direction[1] = start + DIR_MAG;
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

Tree::Tree(char *inst)
{
	set_structur(inst);
	init_variables();
strcpy_s(inst,63,"A$A[+B+B]A&[-B-B]A$[:B:B]A&[|B|B]A$[+B+B]A&[-B-B]A$[+B+B]AA");
}

void Tree::set_structur(char *insts){
	int len = strlen(insts);
	
	for(int i = 0; i < len; i++){
		this->inst[i] = insts[i];
	}
	
	inst[len] = '\0';
}

Tree::Tree(){
	init_variables();
strcpy_s(inst,63,"A$A[+B+B]A&[-B-B]A$[:B:B]A&[|B|B]A$[+B+B]A&[-B-B]A$[+B+B]AA");
}

Tree::~Tree()
{
}

vector<branch> Tree::get_branches(){
	return this->structure;
}

void Tree::create(){	
	unsigned int pos = 0;
	while (pos < strlen(this->inst)){	

		char aux = this->inst[pos];

		if (aux == '+'){
			this->xrotation(1);
			color[0] = 0;
			color[1] = 255;
			color[2] = 0;
			this->copy_last();
		}
		else if (aux =='-' ){
			this->xrotation(-1);			
			color[0] = 0;
			color[1] = 255;
			color[2] = 0;
			this->copy_last();
		}
		else if (aux == '&'){
			this->yrotation(1);
			color[0] = 255;
			color[1] = 0;
			color[2] = 0;
			this->copy_last();
		}
		else if (aux == '$'){
			this->yrotation(-1);
			color[0] = 255;
			color[1] = 0;
			color[2] = 0;
			this->copy_last();
		}
		else if (aux == ':'){
			this->zrotation(1);
			color[0] = 0;
			color[1] = 0;
			color[2] = 255;
			this->copy_last();
		}
		else if (aux == '|'){			
			this->zrotation(-1);
			color[0] = 0;
			color[1] = 0;
			color[2] = 255;
			this->copy_last();
		}
		else if (aux == '['){
			this->back.push(this->last);
			//this->back.push(this->structure.back());
		}
		else if (aux == ']'){
			branch aux = this->back.top();
			this->writer[0] = aux.end[0];
			this->writer[1] = aux.end[1];
			this->writer[2] = aux.end[2];
			

			this->previous[0] = aux.begin[0];
			this->previous[1] = aux.begin[1];
			this->previous[2] = aux.begin[2];
			

			this->direction[0] = aux.end[0];
			this->direction[1] = aux.end[1];
			this->direction[2] = aux.end[2];

			this->trans[0] = aux.trans[0];
			this->trans[1] = aux.trans[1];
			this->trans[2] = aux.trans[2];
			

		}
		
		else if ((aux >= 'a' && aux <= 'z') || (aux >= 'A' && aux <= 'Z')){			
			this->translate();
			this->copy_last();
			this->add_branch();
		}

		pos++;
		
	}
}

void Tree::copy_last(){
	this->last.copy_begin(previous);
	this->last.copy_end(writer);
	this->last.trans[0] = this->trans[0];
	this->last.trans[1] = this->trans[1];
	this->last.trans[2] = this->trans[2];
}


void Tree::add_branch(){
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


void Tree::translate(){

for (int i = 0; i < 3; i++){
	this->writer[i] = this->writer[i] + trans[i];
}	
	
}

int Tree::sign(float value){
	if (value >= 0)
		return 1;
	else
		return -1;
}


void Tree::xrotation(int sign){
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

void Tree::zrotation(int sign){
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



void Tree::yrotation(int sign){
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

void Tree::update_direction(float *newpoint,float angle){
	this->trans[0] = 0;
	this->trans[1] = 0;
	this->trans[2] = 0;
	this->trans[3] = 0;

	this->direction[0] = newpoint[0];
	this->direction[1] = newpoint[1];
	this->direction[2] = newpoint[2];
	this->direction[3] = newpoint[3];

	if (newpoint[0] != 0){
		this->trans[0] = magnitude * this->sign(newpoint[0]);
	}
	if (newpoint[1] != 0){
		this->trans[1] = magnitude * this->sign(newpoint[1]);
	}
	if (newpoint[2] != 0){
		this->trans[2] = magnitude *this->sign(newpoint[2]);
	}
}
