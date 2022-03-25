#pragma once
#include"head.h"

class Word
{
protected:
	int ID;			//��¼����Ϊ���ʵ�˳�����﷨�����׶α��ض���Ϊ��Ӧ�Ĵ�����λ��
	int Type;		//һ������
	int Type2;		//�������ࣨ�����ౣ���֣�����������֣�
	string Data;	//���浥���е��ַ�
	int Rows;		// ��¼�����ڵڼ���
	double Value;	// ���������������ʾ������Data��Ӧ����ֵ����0��1��ʾtrue��false
	int TempNumber;	// ���������������ʾ�м��������ʱtemp�����ı��
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
	// ���typeΪ0�����ж��Ǳ����ֲ����η��࣬���ǷǷ���ĸ��
	// ���typeΪ1�������������η���
	void doCheck();
	void doPrint();
	void doPrintDataByID();
};