#pragma once
#include <sstream>
using namespace std;

#define PI 3.141592654
#define DIR_MAG 0.04

class branch
{
public:
	branch();
	~branch();
	branch(float *begin,float *end,float *trans);
	float begin[3];
	float end[3];
	float trans[3];
	float decrease;

	void copy_begin(float *);
	void copy_end(float *);
	void copy_all(float *begin, float *end, float *trans);
private:

};

void branch::copy_all(float *begin, float *end, float *trans){
	this->copy_begin(begin);
	this->copy_end(end);
	this->trans[0] = trans[0];
	this->trans[1] = trans[1];
	this->trans[2] = trans[2];
}
branch::branch(float *begin, float *end, float *trans){
	this->copy_begin(begin);
	this->copy_end(end);
	this->trans[0] = trans[0];
	this->trans[1] = trans[1];
	this->trans[2] = trans[2];
}

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
class ObjExporter
{
public:
	
	std::string filename;

	void set_file_name(std::string filename);
	void export_tree(std::vector<branch>);


};

void ObjExporter::set_file_name(std::string file){
	this->filename = file;
}


void ObjExporter::export_tree(std::vector<branch> tree){
	std::vector<branch>::iterator bra = tree.begin();

	std::ofstream obj;
	obj.open(this->filename);

	std::stringstream ss;

	obj << "#Vertex Info " << std::endl;
	for (int i = 1; bra != tree.end(); bra++){
		obj << "v " << (*bra).begin[0] << " " << (*bra).begin[1] << " " << (*bra).begin[2] << " " << std::endl;
		obj << "v " << (*bra).end[0] << " " << (*bra).end[1] << " " << (*bra).end[2] << " " << std::endl;
		ss << "l " << (i) << " " << (i+1) << endl;
		i += 2;
	}
	obj << "#Lines Info " << std::endl;
	obj << ss.str();


	obj.close();

}