#include"word.h"
#include"AnalysisFunctions.h"

// ������
void doPrintErrors(Word nextWord, int state, string fname, Word topWord=Word())
{
	int topWordID = topWord.getID();
	int nextWordID = nextWord.getID();
	if (topWordID < 0 || topWordID>12)
	{
		cout << "-* �﷨���� *- �������г������޷�ʶ���ID���ݲ��ܽ��д����ж� <δ֪�Ĵ���>" << endl;
		exit(-1);
	}
	if (nextWordID < 0 || nextWordID>12)
	{
		cout << "-* �﷨���� *- �������г������޷�ʶ���ID���ݲ��ܽ��д����ж� <δ֪�Ĵ���>" << endl;
		exit(-1);
	}
	switch (state)
	{
	case 0:
	{
		if (nextWordID == 0 || nextWordID == 1 || nextWordID == 4 || nextWordID == 6 || nextWordID == 9)
		{
			cout << "ERROR(20): �����øô��� " << nextWord.getData() << " ��Ϊ���봮�Ŀ�ʼ��" << endl;
			cout << "\t�ļ�: " << fname << "\t��: " << nextWord.getRows() << endl;
			cout << "\t���е��޸ķ���: �볢��ʹ�����´��� not, (, ���ֻ���ĸ, true, false��" << endl;
		}
		else
		{
			cout << "-* �﷨���� *- ״̬ " << state << " ��������ʶ��Ĵ��� " << nextWord.getData() << " ʱ����Ȼ�����˴������ӳ����� " << "<δ֪�Ĵ���>" << endl;
			exit(-1);
		}
		break;
	}
	case 1:
	{
		if (nextWordID == 2 || nextWordID == 3 || nextWordID == 4 || nextWordID == 5 || nextWordID == 6 || nextWordID == 7 || nextWordID == 8 || nextWordID == 10)
		{
			cout << "ERROR(21): �� " << topWord.getData() << "��" << nextWord.getData() << " ֮�䣬ȱ���߼������ or ���� and��" << endl;
			cout << "\t�ļ�: " << fname << "\t��: " << nextWord.getRows() << endl;
			cout << "\t���е��޸ķ���: �볢������߼������ or �� and��" << endl;
		}
		else
		{
			cout << "-* �﷨���� *- ״̬ " << state << " ��������ʶ��ĵ��� " << nextWord.getData() << " ʱ����Ȼ�����˴������ӳ����� " << "<δ֪�Ĵ���>" << endl;
			exit(-1);
		}
		break;
	}
	case 2:
	{
		if (nextWordID == 0 || nextWordID == 1 || nextWordID == 4 || nextWordID == 6 || nextWordID == 9)
		{
			cout << "ERROR(22): ��� not ��ȱ�� not �� ( �� ������ĸ �� true �� false��" << endl;
			cout << "\t�ļ�: " << fname << "\t��: " << nextWord.getRows() << endl;
			cout << "\t���е��޸ķ���: �޸�not�߼�����������ı��ʽ��" << endl;
		}
		else
		{
			cout << "-* �﷨���� *- ״̬ " << state << " ��������ʶ��ĵ��� " << nextWord.getData() << " ʱ����Ȼ�����˴������ӳ����� " << "<δ֪�Ĵ���>" << endl;
			exit(-1);
		}
		break;
	}
	case 3:
	{
		if (nextWordID == 0 || nextWordID == 1 || nextWordID == 4 || nextWordID == 6 || nextWordID == 9)
		{
			cout << "ERROR(23): ��� ( ��ȱ�� not �� ( �� ������ĸ �� true �� false��" << endl;
			cout << "\t�ļ�: " << fname << "\t��: " << nextWord.getRows() << endl;
			cout << "\t���е��޸ķ���: �޸Ľ�������ı��ʽ��" << endl;
		}
		else
		{
			cout << "-* �﷨���� *- ״̬ " << state << " ��������ʶ��ĵ��� " << nextWord.getData() << " ʱ����Ȼ�����˴������ӳ����� " << "<δ֪�Ĵ���>" << endl;
			exit(-1);
		}
		break;
	}
	case 4:
	{
		if (nextWordID != 6)
		{
			cout << "ERROR(24): ��ĸ�����ֺ�ȱ���������" << endl;
			cout << "\t�ļ�: " << fname << "\t��: " << nextWord.getRows() << endl;
			cout << "\t���е��޸ķ���: �ڳ���λ����Ӻ����������" << endl;
		}
		else
		{
			cout << "-* �﷨���� *- ״̬ " << state << " ��������ʶ��ĵ��� " << nextWord.getData() << " ʱ����Ȼ�����˴������ӳ����� " << "<δ֪�Ĵ���>" << endl;
			exit(-1);
		}
		break;
	}
	case 5:
	{
		if (nextWordID != 0 && nextWordID != 1 && nextWordID != 4 && nextWordID != 9)
		{
			cout << "ERROR(25): true �� ȱ�� or �� and �� )��" << endl;
			cout << "\t�ļ�: " << fname << "\t��: " << nextWord.getRows() << endl;
			cout << "\t���е��޸ķ���: �ڳ���λ����Ӻ��ʵ��߼������������" << endl;
		}
		else
		{
			cout << "-* �﷨���� *- ״̬ " << state << " ��������ʶ��ĵ��� " << nextWord.getData() << " ʱ����Ȼ�����˴������ӳ����� " << "<δ֪�Ĵ���>" << endl;
			exit(-1);
		}
		break;
	}
	case 6:
	{
		if (nextWordID != 0 && nextWordID != 1 && nextWordID != 4 && nextWordID != 9)
		{
			cout << "ERROR(26): false �� ȱ�� or �� and �� )��" << endl;
			cout << "\t�ļ�: " << fname << "\t��: " << nextWord.getRows() << endl;
			cout << "\t���е��޸ķ���: �ڳ���λ����Ӻ��ʵ��߼������������" << endl;
		}
		else
		{
			cout << "-* �﷨���� *- ״̬ " << state << " ��������ʶ��ĵ��� " << nextWord.getData() << " ʱ����Ȼ�����˴������ӳ����� " << "<δ֪�Ĵ���>" << endl;
			exit(-1);
		}
		break;
	}
	case 7:
	{
		if (nextWordID == 0 || nextWordID == 1 || nextWordID == 4 || nextWordID == 6 || nextWordID == 9)
		{
			cout << "ERROR(27): �߼������ or ��ȱ�ٺϷ����ʽ��" << endl;
			cout << "\t�ļ�: " << fname << "\t��: " << nextWord.getRows() << endl;
			cout << "\t���е��޸ķ���: �޸� or ����߼����ʽ��" << endl;
		}
		else
		{
			cout << "-* �﷨���� *- ״̬ " << state << " ��������ʶ��ĵ��� " << nextWord.getData() << " ʱ����Ȼ�����˴������ӳ����� " << "<δ֪�Ĵ���>" << endl;
			exit(-1);
		}
		break;
	}
	case 8:
	{
		if (nextWordID == 0 || nextWordID == 1 || nextWordID == 4 || nextWordID == 6 || nextWordID == 9)
		{
			cout << "ERROR(28): �߼������ and ��ȱ�ٺϷ����ʽ��" << endl;
			cout << "\t�ļ�: " << fname << "\t��: " << nextWord.getRows() << endl;
			cout << "\t���е��޸ķ���: �޸� and ����߼����ʽ��" << endl;
		}
		else
		{
			cout << "-* �﷨���� *- ״̬ " << state << " ��������ʶ��ĵ��� " << nextWord.getData() << " ʱ����Ȼ�����˴������ӳ����� " << "<δ֪�Ĵ���>" << endl;
			exit(-1);
		}
		break;
	}
	case 9:
	{
		if (nextWordID != 0 && nextWordID != 1 && nextWordID != 4 && nextWordID != 9)
		{
			cout << "ERROR(29): not���߼����ʽֻ�ܳ�����or/and�߼�������Ĳ��������ֻ��������С�" << endl;
			cout << "\t�ļ�: " << fname << "\t��: " << nextWord.getRows() << endl;
			cout << "\t���е��޸ķ���: �޸�not���߼����ʽ�����Ĳ�λ��߼���ϵ��" << endl;
		}
		else
		{
			cout << "-* �﷨���� *- ״̬ " << state << " ��������ʶ��ĵ��� " << nextWord.getData() << " ʱ����Ȼ�����˴������ӳ����� " << "<δ֪�Ĵ���>" << endl;
			exit(-1);
		}
		break;
	}
	case 10:
	{
		if (nextWordID != 0 && nextWordID != 1 && nextWordID != 4)
		{
			cout << "ERROR(30): ()����ʽ�ڲ��ı��ʽ������" << endl;
			cout << "\t�ļ�: " << fname << "\t��: " << nextWord.getRows() << endl;
			cout << "\t���е��޸ķ���: �޸�()����ʽ�ڲ����ʽ�Ĳ�λ��߼���ϵ��" << endl;
		}
		else
		{
			cout << "-* �﷨���� *- ״̬ " << state << " ��������ʶ��ĵ��� " << nextWord.getData() << " ʱ����Ȼ�����˴������ӳ����� " << "<δ֪�Ĵ���>" << endl;
			exit(-1);
		}
		break;
	}
	case 11:
	{
		if (nextWordID != 5)
		{
			cout << "ERROR(31): ����� " << topWord.getData() << " ��ȱ�����ֻ���ĸ��" << endl;
			cout << "\t�ļ�: " << fname << "\t��: " << nextWord.getRows() << endl;
			cout << "\t���е��޸ķ���: �ڶ�Ӧ���������ӺϷ������ֻ���ĸ��" << endl;
		}
		else
		{
			cout << "-* �﷨���� *- ״̬ " << state << " ��������ʶ��ĵ��� " << nextWord.getData() << " ʱ����Ȼ�����˴������ӳ����� " << "<δ֪�Ĵ���>" << endl;
			exit(-1);
		}
		break;
	}
	case 12: case 13: case 14: case 15:
	{
		if (nextWordID != 0 && nextWordID != 1 && nextWordID != 4 && nextWordID != 9)
		{
			cout << "ERROR(32): ����"<< nextWord.getData()<< "λ�ò��Ϸ���" << endl;
			cout << "\t�ļ�: " << fname << "\t��: " << nextWord.getRows() << endl;
			cout << "\t���е��޸ķ���: �޸Ķ�Ӧ�����λ�á�" << endl;
		}
		else
		{
			cout << "-* �﷨���� *- ״̬ " << state << " ��������ʶ��ĵ��� " << nextWord.getData() << " ʱ����Ȼ�����˴������ӳ����� " << "<δ֪�Ĵ���>" << endl;
			exit(-1);
		}
		break;
	}
	default:
		cout << "-* �﷨���� *- �ڴ���������У������˲���ʶ���״̬���� <δ֪�Ĵ���>" << endl;
		exit(-1);
	}
}
// �ƽ�����
bool doMoveIn(vector<Word> &symbolStack, vector<int> &stateStack, Word word)
{
	if (word.getData() != "#")
		symbolStack.push_back(word);		// ���봮����ĸ��ջ
	int topState = stateStack.back();
	int newState = SLR[topState][word.getID()];
	if (newState == -1)
	{
		// ����
		return false;
	}
	// ����
	stateStack.push_back(newState);	// ��Ӧ״̬��ջ
	return true;
}
// ��Լ����
bool doStatute(vector<Word> &symbolStack, vector<int> &stateStack, int exper_id)
{
	int out_num = WORD_NUM_IN_STATUTE[exper_id];	// Ҫ��ջ����Ŀ
	Word statuteWord = Word(-1, -1, -1, LEFT_WORD_IN_STATUTE[exper_id], -1); // ��Լ�����ķ���
	if (LEFT_WORD_IN_STATUTE[exper_id] == "S")
		statuteWord.setID(11);
	else
		statuteWord.setID(10);
	for (int i = 0; i < out_num; ++i)
	{
		symbolStack.pop_back();	// ����ջ��ջ
		stateStack.pop_back();	// ״̬ջ��ջ
	}
	int topState = stateStack.back();
	int newState = SLR[topState][statuteWord.getID()];
	if (newState == -1)
	{
		// ����
		return false;
	}
	// ����
	stateStack.push_back(newState);	// ״̬��ջ
	symbolStack.push_back(statuteWord);	// ��Լ����󲿷��Ž�ջ
	return true;
}
// �ս��ж�
bool isACC(vector<Word> &symbolStack, Word word)
{
	Word topWord = symbolStack.back();
	if (topWord.getID() == 10 && word.getData() == "#")
		return true;
	return false;
}
// �����������е�����SLR�������е�ID
void doSetAllID(vector<Word> &wordsVector)
{
	int length = wordsVector.size();
	for (int i = 0; i < length; ++i)
	{
		string wordData = wordsVector[i].getData();
		if (wordData == "or")
			wordsVector[i].setID(0);
		else if (wordData == "and")
			wordsVector[i].setID(1);
		else if (wordData == "not")
			wordsVector[i].setID(2);
		else if (wordData == "(")
			wordsVector[i].setID(3);
		else if (wordData == ")")
			wordsVector[i].setID(4);
		else if (wordData == "true")
			wordsVector[i].setID(7);
		else if (wordData == "false")
			wordsVector[i].setID(8);
		else if (wordData == "#")
			wordsVector[i].setID(9);
		else
		{
			int wordType = wordsVector[i].getType();
			if (wordType == 1)
				wordsVector[i].setID(6);
			else if (wordType == 2 || wordType == 3)
				wordsVector[i].setID(5);
			else
			{
				cout << "-* �﷨���� *-\t�ʷ�����������Գ������޷�ʶ��ĵ��� <δ֪�Ĵ���>" << endl;
				exit(-1);
			}
		}
	}
}
// ���״̬ջ
void printStateStack(vector<int> stateStack)
{
	int length = stateStack.size();
	for (int i = 0; i < length; ++i)
	{
		cout << stateStack[i] << ' ';
	}
}
// �������ջ
void printSymbolStack(vector<Word> symbolStack)
{
	int length = symbolStack.size();
	for (int i = 0; i < length; ++i)
	{
		symbolStack[i].doPrintDataByID();
		cout << " ";
	}
}
// �﷨��������
bool doGrammaticalAnalysis(vector<Word> wordsVector, string fname)
{
	vector<Word> symbolStack;			// ����ջ
	vector<int> stateStack;				// ״̬ջ
	int length = wordsVector.size();
	int STATE = 0;						// ��¼��ǰ״̬����ʼ��Ϊ 0
	stateStack.push_back(STATE);		// ��״̬��ջ
	Word startWord = Word(12, 6, -1, "$", 0);
	symbolStack.push_back(startWord);	// ��ʼ���Ž�ջ
	int i = 0;							// ȡ��index
	int num = 0;						// ѭ������
	bool flag = true;					// ѭ�������ı�־
	bool hasError = false;				// ��¼�Ƿ����﷨����
	cout << "���̺ţ�״̬ջ �� ����ջ �� �����봮" << endl;
	while (flag)
	{
		// ��ӡ��ǰ��Ϣ
		cout << setw(3) << num << " �� ";
		printStateStack(stateStack);
		cout << " �� ";
		printSymbolStack(symbolStack);
		cout << " �� ";
		for (int j = i; j < length; ++j)
		{
			wordsVector[j].doPrintDataByID();
			cout << ' ';
		}
		cout << endl;

		Word tempWord;
		if (i == length)	// ��ȡ��i��������봮�������򱣳����һ���������
			tempWord = wordsVector[length-1];
		else
			tempWord = wordsVector[i];
		int topState = stateStack.back();
		int wordID = tempWord.getID();
		int slr = SLR_S[topState][wordID];	// ��ȡSLR_S���У��ж���һ���ǹ�Լ�����ƽ�
		if (slr == 0)	// �ƽ�
		{
			if (!doMoveIn(symbolStack, stateStack, tempWord))
			{
				// ����
				hasError = true;
				flag = false;
				doPrintErrors(tempWord, stateStack.back(), fname, symbolStack.back());
			}
			else
				++i;
		}
		else if (slr == -1)	// ��Լ
		{
			if (SLR[topState][wordID] == -1)
			{
				// ����
				hasError = true;
				flag = false;
				doPrintErrors(tempWord, stateStack.back(), fname, symbolStack.back());
			}
			else if (SLR[topState][wordID] == 0)
			{
				// acc
				if (isACC(symbolStack, tempWord))
				{
					flag = false;
					hasError = false;
					cout << "acc" << endl;
				}
				else
				{
					// ����
					flag = false;
					hasError = true;
					doPrintErrors(tempWord, stateStack.back(), fname, symbolStack.back());
				}
			}
			else
			{
				if (!doStatute(symbolStack, stateStack, SLR[topState][wordID]))
				{
					// ����
					hasError = true;
					flag = false;
					doPrintErrors(tempWord, stateStack.back(), fname, symbolStack.back());
				}
			}
		}
		else // ����
		{
			cout << "-* ������� *-\t�ʷ���������ִ��г�����S / E <δ֪�Ĵ���>" << endl;
			exit(-1);
		}
		num++;
	} // while
	return !hasError;
}