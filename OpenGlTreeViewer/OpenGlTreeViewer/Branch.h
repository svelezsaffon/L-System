#pragma once

using namespace std;

#define PI 3.141592654
#define DIR_MAG 1

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