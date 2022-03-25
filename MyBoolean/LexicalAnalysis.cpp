#include"word.h"
#include"AnalysisFunctions.h"

// �ʷ���������
vector<Word> doLexicalAnalysis(string input, string fname, vector<int> &statesVector)
{
	cout << "-* �ʷ����� *- ��ʼ\t\t�ļ�: " << fname << endl;
	vector<Word> wordsVector;
	if (wordsVector.size() != 0)
	{
		cout << "-* �ʷ����� *-\t���� wordsVector ��Ϊ�� <δ֪�Ĵ���>" << endl;
		exit(-1);
	}
	int length = input.length(); //���봮����
	if (length == 0)
	{
		// ���봮Ϊ��
		Word tempWord1 = Word(-1, -1, -1, "error0", 0);
		wordsVector.push_back(tempWord1);
		return wordsVector;
	}
	int* rowsArray;
	rowsArray = new int[length];	// ���ÿһ���ַ���Ӧ���б��
	bool END_FLAG = false;		// ��Ǵ��봮���Ƿ�����ֹ����
	for (int i = 0, j = 0; i < length; ++i)	// ��ÿһ���ַ������б��
	{
		if (input[i] == '\n')
		{
			rowsArray[i] = j++;
			continue;
		}
		rowsArray[i] = j;
		if (input[i] == '#')
			END_FLAG = true;
	}
	// �ڽ��дʷ�����ǰ�ȼ�����봮�Ƿ�Ϸ���ֹ
	if (!END_FLAG)
	{
		// ���봮����ֹ
		Word tempWord2 = Word(-2, -1, -1, "error1", 0);
		wordsVector.push_back(tempWord2);
		return wordsVector;
	}
	/*// ����б���Ƿ���ȷ
	for (int i = 0; i < length; ++i)
	{
		cout << rowsArray[i] << "  ";
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
	*/
	int STATE = 0;	// ���ó�ʼ״̬
	int wordNum = 0;// ��¼�Ѿ��ָ�Ĵ���
	char tempChar;
	int forNum = 0;	// ��¼ѭ������
	vector<char> charStack;	// �ַ�ջ������Ѿ��������ַ������ս�̬��ȡ�󵯳�
	cout << "-* �ʷ����� *- ״̬ת������\t�ļ�: " << fname  << endl;
	int i = 0;	// �ַ����е�i���ַ�
	bool FLAG = true;	// ѭ��������־
	while (FLAG)	// ����ÿһ���ַ�
	{
		statesVector.push_back(STATE);	// ״̬�����¼ջ�Է���֮�󱣴�
		cout << STATE << '\t';
		if ((forNum + 1) % 10 == 0)
			cout << endl;
		forNum++;
		// ����ǰ״̬�����ս�̬ʱ�����ַ���ȡ
		if (STATE < 1 || STATE>16)
		{
			tempChar = input[i];	// ��ȡ�ַ�
			++i;
			charStack.push_back(tempChar);	// �������ַ���ջ
		}
		// ״̬ת����������Ӧ����
		switch (STATE)
		{
		// ��̬
		case 0:
		{
			if (tempChar == ' ' || tempChar == '\n' || tempChar == '\t')
			{
				STATE = 0;
				charStack.clear();
			}
			else if (tempChar == '\'')
				STATE = 20;
			else if (tempChar == '(')
				STATE = 2;
			else if (tempChar == ')')
				STATE = 3;
			else if ((tempChar >= 'a' && tempChar <= 'z') || (tempChar >= 'A' && tempChar <= 'Z'))
				STATE = 22;
			else if (tempChar == '<')
				STATE = 23;
			else if (tempChar == '>')
				STATE = 24;
			else if (tempChar == '!')
				STATE = 25;
			else if (tempChar == '=')
				STATE = 26;
			else if (tempChar == '-')
				STATE = 27;
			else if (tempChar >= '0' && tempChar <= '9')
				STATE = 30;
			else if (tempChar == '#')
				STATE = 16;
			else
				STATE = 15;
			break;
		}
		// �ս�̬
		case 1:	// ������ĸ
		{
			int StackLength = charStack.size();
			Word tempWord = Word(wordNum, 3, -1, "", rowsArray[i - StackLength + 1]);
			tempWord.addCharToData(charStack[1]);	// ��������ĸ�����Ե�����
			charStack.clear();
			wordsVector.push_back(tempWord);
			wordNum++;
			STATE = 0;
			break;
		}
		case 2:	case 3: // ��� (, )
		{
			int StackLength = charStack.size();
			Word tempWord = Word(wordNum, 4, -1, "", rowsArray[i - StackLength + 1]);
			tempWord.addCharToData(charStack[0]);
			charStack.clear();
			wordsVector.push_back(tempWord);
			wordNum++;
			STATE = 0;
			break;
		}
		/*
		case 3:	// ��� )
			break;
		*/
		case 4:	// �����ֻ�Ƿ���ĸ��
		{
			int StackLength = charStack.size();
			Word tempWord = Word(wordNum, 0, -1, "", rowsArray[i - StackLength + 1]);
			for (int j = 0; j < StackLength; ++j)
				tempWord.addCharToData(charStack[j]);
			charStack.clear();
			tempWord.doCheck();
			wordsVector.push_back(tempWord);
			wordNum++;
			STATE = 0;
			break;
		}
		case 5: case 6: case 7: case 8:	case 9: case 10: // �������
		{
			int StackLength = charStack.size();
			Word tempWord = Word(wordNum, 1, -1, "", rowsArray[i - StackLength + 1]);
			for (int j = 0; j < StackLength; ++j)
				tempWord.addCharToData(charStack[j]);
			charStack.clear();
			tempWord.doCheck();
			wordsVector.push_back(tempWord);
			wordNum++;
			STATE = 0;
			break;
		}
		/*
		case 6:	// С�ڵ��� <=
			break;
		case 7:	// ���� >
			break;
		case 8:	// ���ڵ��� >=
			break;
		case 9:
			break;
		case 10:
			break;
		*/
		case 11: case 12: case 13: case 14:	// ������
		{
			int StackLength = charStack.size();
			Word tempWord = Word(wordNum, 2, STATE-11, "", rowsArray[i - StackLength + 1]);
			for (int j = 0; j < StackLength; ++j)
				tempWord.addCharToData(charStack[j]);
			charStack.clear();
			wordsVector.push_back(tempWord);
			wordNum++;
			STATE = 0;
			break;
		}
		/*
		case 12:
			break;
		case 13:
			break;
		case 14:
			break;
		*/
		case 15: // �����ַ�����һ������
		{
			int StackLength = charStack.size();
			Word tempWord = Word(wordNum, 5, -1, "", rowsArray[i - StackLength + 1]);
			for (int j = 0; j < StackLength; ++j)
				tempWord.addCharToData(charStack[j]);
			charStack.clear();
			wordsVector.push_back(tempWord);
			wordNum++;
			STATE = 0;
			break;
		}
		case 16: // # �ս�̬
		{
			FLAG = false;
			Word tempWord = Word(wordNum, 6, -1, "#", rowsArray[i-1]);
			wordsVector.push_back(tempWord);
			wordNum++;
			break;
		}
		// �м�̬
		case 20:
		{
			// �������ĸ
			if ((tempChar >= 'a' && tempChar <= 'z') || (tempChar >= 'A' && tempChar <= 'Z'))
			{
				STATE = 21;
			}
			// ���������ĸ
			else
			{
				// �������ӳ���
				STATE = 0;
				int n = charStack.size();	//��ǰ�ַ�ջ�еĳ���p
				n--;
				i = i - n;	// ����
				Word tempWord = Word(wordNum, 5, -1, "", rowsArray[i]);
				tempWord.addCharToData(charStack[0]);	// �ѵ�һ����ջ�ַ����������ַ�����
				charStack.clear();	// ���ջ
				wordsVector.push_back(tempWord);
			}
			break;
		}
		case 21:
		{
			// ����ǵ�����
			if (tempChar == '\'')
			{
				STATE = 1;
			}
			// ������ǵ�����
			else
			{
				// �������ӳ���
				STATE = 0;
				int n = charStack.size();	//��ǰ�ַ�ջ�еĳ���
				n--;
				i = i - n;	// ����
				Word tempWord = Word(wordNum, 5, -1, "", rowsArray[i]);
				tempWord.addCharToData(charStack[0]);	// �ѵ�һ����ջ�ַ����������ַ�����
				charStack.clear();	// ���ջ
				wordsVector.push_back(tempWord);
			}
			break;
		}
		case 22:
		{
			// �������ĸ
			if ((tempChar >= 'a' && tempChar <= 'z') || (tempChar >= 'A' && tempChar <= 'Z'))
			{
				STATE = 22;
			}
			// ���������ĸ
			else
			{
				STATE = 4;
				i--;	// ����
				charStack.pop_back();
			}
			break;
		}
		case 23:
		{
			// ����� =
			if (tempChar == '=')
			{
				STATE = 6;
			}
			// ������� =
			else
			{
				STATE = 5;
				i--;	// ����
				charStack.pop_back();
			}
			break;
		}
		case 24:
		{
			// ����� =
			if (tempChar == '=')
			{
				STATE = 8;
			}
			// ������� =
			else
			{
				STATE = 7;
				i--;
				charStack.pop_back();
			}
			break;
		}
		case 25:
		{
			// ����� =
			if (tempChar == '=')
			{
				STATE = 9;
			}
			// ������� =
			else
			{
				// �������ӳ���
				STATE = 0;
				i--;	// ����
				Word tempWord = Word(wordNum, 5, -1, "", rowsArray[i]);
				tempWord.addCharToData(charStack[0]);	// �ѵ�һ����ջ�ַ����������ַ�����
				charStack.clear();	// ���ջ
				wordsVector.push_back(tempWord);
			}
			break;
		}
		case 26:
		{
			// ����� =
			if (tempChar == '=')
			{
				STATE = 10;
			}
			// ������� =
			else
			{
				// �������ӳ���
				STATE = 0;
				i--;	// ����
				Word tempWord = Word(wordNum, 5, -1, "", rowsArray[i]);
				tempWord.addCharToData(charStack[0]);	// �ѵ�һ����ջ�ַ����������ַ�����
				charStack.clear();	// ���ջ
				wordsVector.push_back(tempWord);
			}
			break;
		}
		case 27:
		{
			// ���������
			if (tempChar >= '0'&&tempChar <= '9')
			{
				STATE = 28;
			}
			//�����������
			else
			{
				// �������ӳ���
				STATE = 0;
				int n = charStack.size();	//��ǰ�ַ�ջ�еĳ���
				n--;
				i = i - n;	// ����
				Word tempWord = Word(wordNum, 5, -1, "", rowsArray[i]);
				tempWord.addCharToData(charStack[0]);	// �ѵ�һ����ջ�ַ����������ַ�����
				charStack.clear();	// ���ջ
				wordsVector.push_back(tempWord);
			}
			break;
		}
		case 28:
		{
			// ���������
			if (tempChar >= '0'&&tempChar <= '9')
			{
				STATE = 28;
			}
			// �����С����
			else if (tempChar == '.')
			{
				STATE = 29;
			}
			// ����
			else
			{
				STATE = 11;
				i--;
				charStack.pop_back();
			}
			break;
		}
		case 29:
		{
			// ���������
			if (tempChar >= '0'&&tempChar <= '9')
			{
				STATE = 29;
			}
			// �����������
			else
			{
				STATE = 12;
				i--;
				charStack.pop_back();
			}
			break;
		}
		case 30:
		{
			// ���������
			if (tempChar >= '0'&&tempChar <= '9')
			{
				STATE = 30;
			}
			// �����С����
			else if (tempChar == '.')
			{
				STATE = 31;
			}
			// ����
			else
			{
				STATE = 13;
				i--;
				charStack.pop_back();
			}
			break;
		}
		case 31:
		{
			// ���������
			if (tempChar >= '0'&&tempChar <= '9')
			{
				STATE = 31;
			}
			// ����
			else
			{
				STATE = 14;
				i--;
				charStack.pop_back();
			}
			break;
		}
		default:
			cout << "-* �ʷ����� *- �����޷�ʶ���״̬ <δ֪�Ĵ���>" << endl;
			exit(-1);
		} // switch
	} // for
	if ((forNum + 1) % 10 != 0)
		cout << endl;
	cout << "-* �ʷ����� *- ���\t�ļ�: " << fname << endl;
	return wordsVector;
}

// �ʷ��������ռ�������
int doFindLexicalErrors(vector<Word> wordsVector, string fname)
{
	int errorNum = 0;
	int length = wordsVector.size();
	if (length == 0)
	{
		cout << "-* �ʷ����� *- �ʷ��������ռ��������������Ϊ�� <δ֪�Ĵ���>" << endl;
		return -1;
	}
	if (wordsVector[0].getID() == -1)
	{
		cout << "ERROR(0): ����ʴ�Ϊ��\t�ļ�: " << fname << "\t��: 0" << endl;
		errorNum++;
		cout << "-* �ʷ����� *- ���Ѽ������� " << errorNum << " ��\t�ļ�: " << fname << endl;
		return errorNum;
	}
	else if (wordsVector[0].getID() == -2)
	{
		cout << "ERROR(1): ���봮�в����н�����\t�ļ�: " << fname << "\t��: ?" << endl;
		errorNum++;
		cout << "-* �ʷ����� *- ���Ѽ������� " << errorNum << " ��\t�ļ�: " << fname << endl;
		return errorNum;
	}
	for (int i = 0; i < length; ++i)
	{
		Word tempWord = wordsVector[i];
		if (tempWord.getType() == 5)
		{
			errorNum++;
			if (tempWord.getData() == "\'")
			{
				cout << "ERROR(10): �޷�ʶ����ַ� \' \t�ļ�: " << fname << "\t��: " << tempWord.getRows() << endl;
				cout << "     ���ܵ��޸ķ���: ����������ֻ��֤��һ����ĸ" << endl;
			}
			else if (tempWord.getData() == ".")
			{
				cout << "ERROR(11): �޷�ʶ����ַ� . \t�ļ�: " << fname << "\t��: " << tempWord.getRows() << endl;
				cout << "     ���ܵ��޸ķ���: ����С����ֻ����һ��С����" << endl;
			}
			else if (tempWord.getData() == "+")
			{
				cout << "ERROR(12): �޷�ʶ����ַ� + \t�ļ�: " << fname << "\t��: " << tempWord.getRows() << endl;
				cout << "     ���ܵ��޸ķ���: ����ȥ�� + (�������� + )" << endl;
			}
			else if (tempWord.getData() == "!")
			{
				cout << "ERROR(13): �޷�ʶ����ַ� ! \t�ļ�: " << fname << "\t��: " << tempWord.getRows() << endl;
				cout << "     ���ܵ��޸ķ���: ���Խ� ! �滻Ϊ !=" << endl;
			}
			else if (tempWord.getData() == "=")
			{
				cout << "ERROR(14): �޷�ʶ����ַ� = \t�ļ�: " << fname << "\t��: " << tempWord.getRows() << endl;
				cout << "     ���ܵ��޸ķ���: ���Խ� = �滻Ϊ ==" << endl;
			}
			else if (tempWord.getData() == "-")
			{
				cout << "ERROR(15): �޷�ʶ����ַ� - \t�ļ�: " << fname << "\t��: " << tempWord.getRows() << endl;
				cout << "     ���ܵ��޸ķ���: �����ں���׷������" << endl;
			}
			else if (tempWord.getData() == "��" || tempWord.getData() == "��" || tempWord.getData() == "��" || tempWord.getData() == "��" || tempWord.getData() == "��" || tempWord.getData() == "��")
			{
				cout << "ERROR(18): �޷�ʶ����ַ� " << tempWord.getData() << "\t�ļ�: " << fname << "\t��: " << tempWord.getRows() << endl;
				cout << "     ���ܵ��޸ķ���: �����滻ΪӢ�İ���ַ�" << endl;
			}
			else if (tempWord.getData().size() > 1)
			{
				cout << "ERROR(16): �޷�ʶ��ı����� " << tempWord.getData() << "\t�ļ�: " << fname << "\t��: " << tempWord.getRows() << endl;
				cout << "     ���ܵ��޸ķ���: �޸�Ϊ��ȷ�ı�����" << endl;
			}
			else
			{
				cout << "ERROR(17): �޷�ʶ����ַ� " << tempWord.getData() << "\t�ļ�: " << fname << "\t��: " << tempWord.getRows() << endl;
				cout << "     ���ܵ��޸ķ���: ����ɾ�����滻" << endl;
			}
		}
	}// for
	cout << "-* �ʷ����� *- ���Ѽ������� " << errorNum << " ��\t�ļ�: " << fname << endl;
	return errorNum;
}