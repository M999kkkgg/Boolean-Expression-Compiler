#pragma once
#include"word.h"
#include"File.h"
#include<windows.h>
#include<stdlib.h>
#include<direct.h>
#include<vector>
#include<iomanip>

// �ʷ���������
// ���ص��Ƿ�����ĵ�����
// ������һ���������ֹ����
// ���ش��󣺴��봮Ϊ�ա����봮����ֹ��
vector<Word> doLexicalAnalysis(string input, string fname, vector<int> &statesVector);
// �ʷ��������ռ�������
// ���ص��Ǵ�����
// ִ���л��ڿ���̨��ӡ������Ϣ�Լ�������޸ķ���
int doFindLexicalErrors(vector<Word> wordsVector, string fname);

// �﷨��������
// ����true��ʾ�﷨�޴���
bool doGrammaticalAnalysis(vector<Word> wordsVector, string fname);
void doPrintErrors(Word, int, string, Word topWord);
bool doMoveIn(vector<Word> &symbolStack, vector<int> &stateStack, Word word);
bool doStatute(vector<Word> &symbolStack, vector<int> &stateStack, int exper_id);
void doSetAllID(vector<Word> &wordsVector);
bool isACC(vector<Word> &symbolStack, Word word);

// �����������
bool SemanticAnalysis(vector<Word> wordsVector);
void setWordInSemantic(vector<Word> &wordsVector);
void printWordInSemantic(vector<Word> wordsVector);
void doCreateRPolish(vector<Word> input, vector<Word> &output);
void printRPolish(vector<Word> RPolish);
void setAllValue(vector<Word> &RPolish);
void printValue(vector<Word> RPolish);
void printQuaternion(Word op1, Word op2, int tempNums, string p);
bool doCalculation(vector<Word> RPolish);


// main.cpp�е���Ҫ����
// ��ӡ�����ȫ������
void showReadCodes(vector<string> codes, int length);
// ��ͣ������flagΪ��ʱ����ִ��������
void PAUSE(bool flag);
// ��ӡ����ID
void doPrintAllWordID(vector<Word> wordsVector);
// ��ӡSLR
void doPrintSLR();
// ��ӡ�ʷ��������ȫ������
void doPrintWordsVector(vector<Word> wordsVector);
// ���Զ������ӳ���
void autoAnalysis();
// �ֶ��������������ӳ���
void handAnalysis(); string getstring(int n);
// intתΪstring
string getString(int n);