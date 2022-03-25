#pragma once
#include"word.h"
#include"File.h"
#include<windows.h>
#include<stdlib.h>
#include<direct.h>
#include<vector>
#include<iomanip>

// 词法分析函数
// 返回的是分析后的单词组
// 若出现一般错误则不终止分析
// 严重错误：代码串为空、代码串无终止符
vector<Word> doLexicalAnalysis(string input, string fname, vector<int> &statesVector);
// 词法分析后收集错误函数
// 返回的是错误数
// 执行中会在控制台打印错误信息以及建议的修改方案
int doFindLexicalErrors(vector<Word> wordsVector, string fname);

// 语法分析函数
// 返回true表示语法无错误
bool doGrammaticalAnalysis(vector<Word> wordsVector, string fname);
void doPrintErrors(Word, int, string, Word topWord);
bool doMoveIn(vector<Word> &symbolStack, vector<int> &stateStack, Word word);
bool doStatute(vector<Word> &symbolStack, vector<int> &stateStack, int exper_id);
void doSetAllID(vector<Word> &wordsVector);
bool isACC(vector<Word> &symbolStack, Word word);

// 语义分析函数
bool SemanticAnalysis(vector<Word> wordsVector);
void setWordInSemantic(vector<Word> &wordsVector);
void printWordInSemantic(vector<Word> wordsVector);
void doCreateRPolish(vector<Word> input, vector<Word> &output);
void printRPolish(vector<Word> RPolish);
void setAllValue(vector<Word> &RPolish);
void printValue(vector<Word> RPolish);
void printQuaternion(Word op1, Word op2, int tempNums, string p);
bool doCalculation(vector<Word> RPolish);


// main.cpp中的主要函数
// 打印读入的全部代码
void showReadCodes(vector<string> codes, int length);
// 暂停函数，flag为真时，则执行完清屏
void PAUSE(bool flag);
// 打印词语ID
void doPrintAllWordID(vector<Word> wordsVector);
// 打印SLR
void doPrintSLR();
// 打印词法分析后的全部词语
void doPrintWordsVector(vector<Word> wordsVector);
// 半自动分析子程序
void autoAnalysis();
// 手动操作分析步骤子程序
void handAnalysis(); string getstring(int n);
// int转为string
string getString(int n);