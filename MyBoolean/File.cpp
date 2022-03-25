#pragma once
#include"File.h"

bool readCode(string fname, string &data)
{
	ifstream read;
	read.open(fname, ios::in);
	if (!read)
	{
		cout << "Open file<" + fname + "> failed." << endl;
		return false;
	}
	stringstream buffer;
	buffer << read.rdbuf();
	data = (buffer.str());
	read.close();
	cout << "Read file<" + fname + "> completed." << endl;
	return true;
}
int doCutCode(string* &output, string input)
{
	int length = input.length();
	int codeNum = 0;
	for (int i = 0; i < length; ++i)
		if (input[i] == '#')
			codeNum++;
	/*
	if (codeNum > 10)
	{
		codeNum = 10;
		cout << "-* ���� *- ���ֻ�ܴ���ʮ���������ʽ�����Ѿ�����ΪĬ�϶�ȡǰʮ��" << endl;
	}
	*/
	output = new string[codeNum];
	int j = 0;
	for (int i = 0; i < codeNum; ++i)
	{
		while (j < length)
		{
			output[i] += input[j];
			if (input[j] == '#')
			{
				j++;
				break;
			}
			++j;
		}
	}
	return codeNum;
}

void OutFile::setDir(string dir)
{
	dirName = dir;
}
void OutFile::setRoot(string root)
{
	rootOutPath = root;
}
void OutFile::doOutputWords(string fname, vector<Word> words, vector<int> statesVector)
{
	string path = rootOutPath + dirName + fname;
	cout << "���� => " << path << endl << endl;
	ofstream myOut(path);
	myOut << "-* �ʷ������������ *-" << endl;
	myOut << "���������е�״̬ת��" << endl;
	int stateSize = statesVector.size();
	int wordSize = words.size();
	int i;
	for (i = 0; i < stateSize; ++i)
	{
		myOut << statesVector[i] << '\t';
		if ((i+ 1) % 10 == 0)
			myOut << endl;
	}
	if ((i + 1) % 10 != 0)
		myOut << endl;
	myOut << "\n�������" << endl;
	myOut << "���\t" << "һ������\t\t" << "��������\t" << "�б��\t" << "�ַ�(��)" << endl;
	for (i = 0; i < wordSize; ++i)
	{
		if (words[i].getID() == -1 || words[i].getID() == -2)
		{
			myOut << words[i].getID() << '\t' << "None\t\t\t" << "None\t\t0\t" << words[i].getData() << endl;
		}
		else
		{
			myOut << words[i].getID() << '\t' << words[i].getTypeSTR() << "\t\t";
			if (words[i].getType() == 0)
				myOut << RESERVED_ALL[words[i].getType2()] << '\t';
			else if (words[i].getType() == 1)
				myOut << OPERATOR_ALL[words[i].getType2()] << '\t';
			else if (words[i].getType() == 2)
				myOut << NUMBER_ALL[words[i].getType2()] << '\t';
			else
				myOut << "None" << '\t';
			myOut << "\t";
			myOut << words[i].getRows() << '\t' << words[i].getData() << endl;
		}
	}
}