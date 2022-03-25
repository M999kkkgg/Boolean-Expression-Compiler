#pragma once
#include"head.h"
#include"word.h"
#include<fstream>
#include<sstream>

bool readCode(string fname, string &data);
int doCutCode(string* &output, string input);

class OutFile
{
private:
	string rootOutPath;
	string dirName;
public:
	OutFile(string root, string dir)
	{
		rootOutPath = root;
		dirName = dir;
	}
	void setRoot(string root);
	void setDir(string root);
	void doOutputWords(string fname, vector<Word> words, vector<int> statesVector);
};