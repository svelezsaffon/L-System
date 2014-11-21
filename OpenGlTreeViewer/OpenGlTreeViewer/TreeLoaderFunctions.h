#include <string>
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

class OperationsLoader
{
public:
	OperationsLoader(string);
	~OperationsLoader();
	char * load_file();

private:
	string file_name;
	ifstream file_reader;
};

OperationsLoader::OperationsLoader(string file)
{
	this->file_name = file;
	this->file_reader.open(this->file_name);

}

OperationsLoader::~OperationsLoader()
{

}


char* OperationsLoader::load_file() {
	string line;
	if (this->file_reader.is_open()){		
		getline(this->file_reader, line);
	}
	else{
		cout << "File ["+this->file_name+"] Could not be opend!!" << endl;
	}

	char inst[70000];
	//inst=(char *)calloc(2, sizeof(char));

	
	for (int i = 0; i < line.length(); i++){
		inst[i] = line[i];
	}
	inst[line.length()] = '\0';

	cout<< inst<<endl;

	this->file_reader.close();

	return inst;
}
