#pragma once
#include"head.h"

class Word
{
protected:
	int ID;			//记录读入为单词的顺序，在语法分析阶段被重定义为对应的词语表的位置
	int Type;		//一级分类
	int Type2;		//二级分类（仅分类保留字，运算符和数字）
	string Data;	//保存单词中的字符
	int Rows;		// 记录词语在第几行
	double Value;	// 用于语义分析，表示操作数Data对应的真值，用0和1表示true和false
	int TempNumber;	// 用于语义分析，表示中间代码生成时temp变量的编号
public:
	Word()
	{

	}
	Word(int id, int type, int type2, string data, int rows)
	{
		ID = id;
		Type = type;
		Type2 = type2;
		Data = data; 
		Rows = rows;
	}
	Word(const Word &temp)
	{
		this->ID = temp.ID;
		this->Type = temp.Type;
		this->Type2 = temp.Type2;
		this->Data = temp.Data;
		this->Rows = temp.Rows;
		this->Value = temp.Value;
		this->TempNumber = temp.TempNumber;
	}
	void setID(int id);
	void setType(int type);
	void setType2(int type2);
	void setData(string data);
	void addCharToData(char temp);
	void setRows(int rows);
	void setValue(double value);
	void setTempNumber(int number);
	int getID();
	int getType();
	int getType2();
	int getRows();
	double getValue();
	int getTempNumber();
	string getTypeSTR();
	string getType2STR();
	string getData();
	// 如果type为0，则判断是保留字并二次分类，还是非法字母串
	// 如果type为1，则对运算符二次分类
	void doCheck();
	void doPrint();
	void doPrintDataByID();
};