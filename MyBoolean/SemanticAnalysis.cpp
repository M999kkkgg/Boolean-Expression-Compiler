#include"AnalysisFunctions.h"

// �������õ��ʵ�ID���������Ӧ���ȼ���ƥ��
void setWordInSemantic(vector<Word> &wordsVector)
{
	int length = wordsVector.size();
	for (int i = 0; i < length; ++i)
	{
		int oldID = wordsVector[i].getID();
		switch (oldID)
		{
		case 0:
			wordsVector[i].setID(0);
			break;
		case 1:
			wordsVector[i].setID(1);
			break;
		case 2:
			wordsVector[i].setID(2);
			break;
		case 3:
			wordsVector[i].setID(3);
			break;
		case 4:
			wordsVector[i].setID(4);
			break;
		case 5:
			wordsVector[i].setID(11);
			break;
		case 6:
		{
			if (wordsVector[i].getData() == ">")
				wordsVector[i].setID(5);
			else if (wordsVector[i].getData() == ">=")
				wordsVector[i].setID(6);
			else if (wordsVector[i].getData() == "<")
				wordsVector[i].setID(7);
			else if (wordsVector[i].getData() == "<=")
				wordsVector[i].setID(8);
			else if (wordsVector[i].getData() == "==")
				wordsVector[i].setID(9);
			else if (wordsVector[i].getData() == "!=")
				wordsVector[i].setID(10);
			else
			{
				cout << "-* ������� *-\t�﷨��������󣬳�����ԭ����ID��Dataֵ��ƥ��Ĵ��� <δ֪�Ĵ���>" << endl;
				exit(-1);
			}
			break;
		}
		case 7:
			wordsVector[i].setID(12);
			break;
		case 8:
			wordsVector[i].setID(13);
			break;
		case 9:
			wordsVector[i].setID(14);
			break;
		default:
			cout << "-* ������� *-\t�﷨��������󣬳����˲���ʶ��Ĵ���ID <δ֪�Ĵ���>" << endl;
			exit(-1);
		}
	}
}

// ��ӡ�������ú��ID��Data�����ȼ�
void printWordInSemantic(vector<Word> wordsVector)
{
	cout << "-* ������� *- ��ӡ���¶���ID�ĵ���" << endl;
	int length = wordsVector.size();
	cout << "ID\tType\tData\tPriority" << endl;
	for (int i = 0; i < length; ++i)
	{
		int id = wordsVector[i].getID();
		cout << id << '\t';
		cout << WORD_TYPE_SEM[id] << '\t';
		cout << wordsVector[i].getData() << '\t';
		cout << PRIORITY[id] << endl;
	}
	cout << endl;
}

// �����沨��ʽ
void doCreateRPolish(vector<Word> input, vector<Word> &output)
{
	int length = input.size();
	vector<Word> tempStack;	// ��ʱջ
	// ɨ�����봮��������������ɨ��
	for (int i = 0; i < length - 1; ++i)
	{
		int id = input[i].getID();	// ��ȡ��ǰ�ַ���ID
		// ����ǲ����� id,true,false
		if (id == 11 || id == 12 || id == 13)
		{
			output.push_back(input[i]);
		}
		// ����� (
		else if (id == 3)
		{
			tempStack.push_back(input[i]);
		}
		// ���������� or,and,not,rop
		else if ((id >= 0 && id <= 2) || (id >= 5 && id <= 10))
		{
			while (true)
			{
				if (tempStack.empty())
				{
					tempStack.push_back(input[i]);
					break;
				}
				int inputPriority = PRIORITY[input[i].getID()];
				int topPriority = PRIORITY[tempStack.back().getID()];
				// ջΪ�գ���ջ��Ϊ ( ����ջ����������ȼ�С��ɨ�赽����������ȼ�
				if (tempStack.back().getID() == 3 || (inputPriority > topPriority))
				{
					tempStack.push_back(input[i]);
					break;
				}
				else
				{
					output.push_back(tempStack.back());
					tempStack.pop_back();
				}
			}// while
		}
		// ����� )
		else if (id == 4)
		{
			while (tempStack.back().getID() != 3)
			{
				output.push_back(tempStack.back());
				tempStack.pop_back();
			}
			tempStack.pop_back();
		}
		else
		{
			cout << "-* ������� *-\t�ض���ID����󣬳������޷�ʶ���ID <δ֪�Ĵ���>" << endl;
			exit(-1);
		}
	} //for
	// ɨ����������ջ�л��з���
	while (!tempStack.empty())
	{
		output.push_back(tempStack.back());
		tempStack.pop_back();
	}
	cout << "-* ������� *-\t�����м���루�沨��ʽ��" << endl;
}

// ��ӡ�沨��ʽ
void printRPolish(vector<Word> RPolish)
{
	int length = RPolish.size();
	for (int i = 0; i < length; ++i)
	{
		cout << RPolish[i].getData() << ' ';
	}
	cout << endl;
}

// ��id��ֵ
void setAllValue(vector<Word> &RPolish)
{
	cout << "-* ������� *- ���沨��ʽ�еĲ���������ֵ" << endl;
	int length = RPolish.size();
	for (int i = 0; i < length; ++i)
	{
		int id = RPolish[i].getID();
		if (id >= 0 && id <= 10)
			continue;
		else if (id == 11)
		{
			double temp;
			if (RPolish[i].getType() == 2)	// ������
			{
				stringstream sstr(RPolish[i].getData());
				sstr >> temp;
				RPolish[i].setValue(temp);
			}
			else if (RPolish[i].getType() == 3)	// ����ĸ
			{
				temp = RPolish[i].getData()[0];
				RPolish[i].setValue(temp);
			}
			else
			{
				cout << "-* ������� *-\t������沨��ʽ���ٸ���������ֵʱ���������޷�ʶ���TYPE <δ֪�Ĵ���>" << endl;
				exit(-1);
			}
		}
		else if (id == 12)
			RPolish[i].setValue(1.0);
		else if (id == 13)
			RPolish[i].setValue(0.0);
		else
		{
			cout << "-* ������� *-\t������沨��ʽ���ٸ���������ֵʱ���������޷�ʶ���ID <δ֪�Ĵ���>" << endl;
			exit(-1);
		}
	}
}

void printValue(vector<Word> RPolish)
{
	int length = RPolish.size();
	for (int i = 0; i < length; ++i)
	{
		int id = RPolish[i].getID();
		if (id >= 0 && id <= 10)
			continue;
		else if (id == 11 || id == 12 || id == 13)
			cout << RPolish[i].getData() << " �� " << RPolish[i].getValue() << endl;
		else
		{
			cout << "-* ������� *-\t������沨��ʽ���ٸ���������ֵʱ���������޷�ʶ���ID <δ֪�Ĵ���>" << endl;
			exit(-1);
		}
	}
}

// ��ӡ��Ԫʽ
void printQuaternion(Word op1, Word op2, int tempNums, string p)
{
	cout << "( " << p << " ";
	if (op2.getTempNumber() == 0)
		cout << op2.getData() << " ";
	else
		cout << "T" << op2.getTempNumber() << " ";
	if (op1.getTempNumber() == -1)
		cout << "__ ";
	else
	{
		if (op1.getTempNumber() == 0)
			cout << op1.getData() << " ";
		else
			cout << "T" << op1.getTempNumber() << " ";
	}
	cout << "T" << tempNums << " )" << endl;
}

// ������ֵ
bool doCalculation(vector<Word> RPolish)
{
	vector<Word> dataStack;		// ������ջ
	int tempNums = 0;
	int length = RPolish.size();
	for (int i = 0; i < length; ++i)
	{
		int id = RPolish[i].getID();
		switch (id)
		{
		case 0:	// or
		{
			Word op1 = dataStack.back();
			dataStack.pop_back();
			Word op2 = dataStack.back();
			dataStack.pop_back();
			double temp = op2.getValue() || op1.getValue();

			tempNums++;
			Word tempWord;
			tempWord.setValue(temp);
			tempWord.setTempNumber(tempNums);
			
			printQuaternion(op1, op2, tempNums, "or");
			dataStack.push_back(tempWord);
			break;
		}
		case 1:	// and
		{
			Word op1 = dataStack.back();
			dataStack.pop_back();
			Word op2 = dataStack.back();
			dataStack.pop_back();
			double temp = op2.getValue() && op1.getValue();

			tempNums++;
			Word tempWord;
			tempWord.setValue(temp);
			tempWord.setTempNumber(tempNums);

			printQuaternion(op1, op2, tempNums, "and");
			dataStack.push_back(tempWord);
			break;
		}
		case 2:	// not
		{
			Word op1 = dataStack.back();
			dataStack.pop_back();
			Word op2 = Word();
			op2.setTempNumber(-1);
			double temp = !op1.getValue();

			tempNums++;
			Word tempWord;
			tempWord.setValue(temp);
			tempWord.setTempNumber(tempNums);

			printQuaternion(op2, op1, tempNums, "not");
			dataStack.push_back(tempWord);
			break;
		}
		case 5: // >
		{
			Word op1 = dataStack.back();
			dataStack.pop_back();
			Word op2 = dataStack.back();
			dataStack.pop_back();
			double temp = op2.getValue() > op1.getValue();

			tempNums++;
			Word tempWord;
			tempWord.setValue(temp);
			tempWord.setTempNumber(tempNums);

			printQuaternion(op1, op2, tempNums, ">");
			dataStack.push_back(tempWord);
			break;
		}
		case 6:	// >=
		{
			Word op1 = dataStack.back();
			dataStack.pop_back();
			Word op2 = dataStack.back();
			dataStack.pop_back();
			double temp = op2.getValue() >= op1.getValue();

			tempNums++;
			Word tempWord;
			tempWord.setValue(temp);
			tempWord.setTempNumber(tempNums);

			printQuaternion(op1, op2, tempNums, ">=");
			dataStack.push_back(tempWord);
			break;
		}
		case 7: // <
		{
			Word op1 = dataStack.back();
			dataStack.pop_back();
			Word op2 = dataStack.back();
			dataStack.pop_back();
			double temp = op2.getValue() < op1.getValue();

			tempNums++;
			Word tempWord;
			tempWord.setValue(temp);
			tempWord.setTempNumber(tempNums);

			printQuaternion(op1, op2, tempNums, "<");
			dataStack.push_back(tempWord);
			break;
		}
		case 8:	// <=
		{
			Word op1 = dataStack.back();
			dataStack.pop_back();
			Word op2 = dataStack.back();
			dataStack.pop_back();
			double temp = op2.getValue() <= op1.getValue();

			tempNums++;
			Word tempWord;
			tempWord.setValue(temp);
			tempWord.setTempNumber(tempNums);

			printQuaternion(op1, op2, tempNums, "<=");
			dataStack.push_back(tempWord);
			break;
		}
		case 9:	// ==
		{
			Word op1 = dataStack.back();
			dataStack.pop_back();
			Word op2 = dataStack.back();
			dataStack.pop_back();
			double temp = op2.getValue() == op1.getValue();

			tempNums++;
			Word tempWord;
			tempWord.setValue(temp);
			tempWord.setTempNumber(tempNums);

			printQuaternion(op1, op2, tempNums, "==");
			dataStack.push_back(tempWord);
			break;
		}
		case 10:	// !=
		{
			Word op1 = dataStack.back();
			dataStack.pop_back();
			Word op2 = dataStack.back();
			dataStack.pop_back();
			double temp = op2.getValue() != op1.getValue();

			tempNums++;
			Word tempWord;
			tempWord.setValue(temp);
			tempWord.setTempNumber(tempNums);

			printQuaternion(op1, op2, tempNums, "!=");
			dataStack.push_back(tempWord);
			break;
		}
		case 11: case 12: case 13:
		{
			RPolish[i].setTempNumber(0);
			dataStack.push_back(RPolish[i]);
			break;
		}
		default:
			cout << "-* ������� *-\t������沨��ʽ����������ֵ�󣬳������޷�ʶ���ID <δ֪�Ĵ���>" << endl;
			exit(-1);
		}
	}
	if (dataStack.size() != 1)
	{
		cout << "-* ������� *-\t�����沨��ʽ����ʱ���ִ��� <δ֪�Ĵ���>" << endl;
		exit(-1);
	}
	double result = dataStack.back().getValue();
	return result;
}

// �����������
bool SemanticAnalysis(vector<Word> wordsVector)
{
	vector<Word> RPolish;
	doCreateRPolish(wordsVector, RPolish);
	printRPolish(RPolish);
	setAllValue(RPolish);
	printValue(RPolish);
	cout << "-* ������� *-\t�м��������" << endl;
	double result = doCalculation(RPolish);
	cout << "-* ������� *-\t���" << endl;
	if (result == 0.0)
		return false;
	else
		return true;
}