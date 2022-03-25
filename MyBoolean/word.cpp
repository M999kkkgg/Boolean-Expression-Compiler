#include"word.h"
int Word::getID()
{
	return ID;
}
int Word::getType()
{
	return Type;
}
int Word::getType2()
{
	return Type2;
}
string Word::getData()
{
	return Data;
}
string Word::getTypeSTR()
{
	if (Type == -1)
	{
		return "None";
	}
	return WORD_TYPE[Type];
}
string Word::getType2STR()
{
	if (Type2 == -1 && Type == -1)
	{
		return "None";
	}
	if (Type == 0)
	{
		return RESERVED_ALL[Type2];
	}
	else if (Type == 1)
	{
		return OPERATOR_ALL[Type2];
	}
	else if (Type == 2)
	{
		return NUMBER_ALL[Type2];
	}
	else
	{
		return "None";
	}
}
void Word::setID(int id)
{
	ID = id;
}
void Word::setType(int type)
{
	Type = type;
}
void Word::setType2(int type2)
{
	Type2 = type2;
}
void Word::setData(string data)
{
	Data = data;
}
void Word::addCharToData(char temp)
{
	Data.push_back(temp);
}
void Word::doCheck()
{
	if (Type == 0)
	{
		for (int i = 0; i < RESERVED_NUM; ++i)
		{
			if (Data == RESERVED_ALL[i])
			{
				Type2 = i;
				return;
			}
		}
		Type = 5;	// 标记种类为非法字符
	}
	if (Type == 1)
	{
		for (int i = 0; i < OPERATOR_NUM; ++i)
		{
			if (Data == OPERATOR_ALL[i])
			{
				Type2 = i;
				return;
			}
		}
	}
}
void Word::setRows(int rows)
{
	Rows = rows;
}
int Word::getRows()
{
	return Rows;
}
void Word::doPrint()
{
	if (ID == -1 || ID == -2)
	{
		cout << ID << '\t' << "None\t\t\t" << "None\t\t0\t" << Data << endl;
	}
	else
	{
		cout << ID << '\t' << this->getTypeSTR() << "\t\t";
		if (Type == 0)
			cout << RESERVED_ALL[Type2] << '\t';
		else if (Type == 1)
			cout << OPERATOR_ALL[Type2] << '\t';
		else if (Type == 2)
			cout << NUMBER_ALL[Type2] << '\t';
		else
			cout << "None" << '\t';
		cout << "\t";
		cout << Rows << '\t' << Data << endl;
	}
}
void Word::doPrintDataByID()
{
	switch (ID)
	{
	case 0:
		cout << "or";
		break;
	case 1:
		cout << "and";
		break;
	case 2:
		cout << "not";
		break;
	case 3:
		cout << "(";
		break;
	case 4:
		cout << ")";
		break;
	case 5:
		cout << "id";
		break;
	case 6:
		cout << "rop";
		break;
	case 7:
		cout << "true";
		break;
	case 8:
		cout << "false";
		break;
	case 9:
		cout << "#";
		break;
	case 10:
		cout << "E";
		break;
	case 11:
		cout << "S";
		break;
	case 12:
		cout << "$";
		break;
	default:
		cout << "None";
		break;
	}
}
void Word::setValue(double value)
{
	Value = value;
}
double Word::getValue()
{
	return Value;
}
void Word::setTempNumber(int number)
{
	TempNumber = number;
}
int Word::getTempNumber()
{
	return TempNumber;
}