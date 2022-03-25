#include"word.h"
#include"AnalysisFunctions.h"

// 报错函数
void doPrintErrors(Word nextWord, int state, string fname, Word topWord=Word())
{
	int topWordID = topWord.getID();
	int nextWordID = nextWord.getID();
	if (topWordID < 0 || topWordID>12)
	{
		cout << "-* 语法分析 *- 错误处理中出现了无法识别的ID，暂不能进行错误判断 <未知的错误>" << endl;
		exit(-1);
	}
	if (nextWordID < 0 || nextWordID>12)
	{
		cout << "-* 语法分析 *- 错误处理中出现了无法识别的ID，暂不能进行错误判断 <未知的错误>" << endl;
		exit(-1);
	}
	switch (state)
	{
	case 0:
	{
		if (nextWordID == 0 || nextWordID == 1 || nextWordID == 4 || nextWordID == 6 || nextWordID == 9)
		{
			cout << "ERROR(20): 不能用该词语 " << nextWord.getData() << " 作为代码串的开始。" << endl;
			cout << "\t文件: " << fname << "\t行: " << nextWord.getRows() << endl;
			cout << "\t可行的修改方案: 请尝试使用如下词语 not, (, 数字或字母, true, false。" << endl;
		}
		else
		{
			cout << "-* 语法分析 *- 状态 " << state << " 在遇到可识别的词语 " << nextWord.getData() << " 时，仍然进入了错误处理子程序中 " << "<未知的错误>" << endl;
			exit(-1);
		}
		break;
	}
	case 1:
	{
		if (nextWordID == 2 || nextWordID == 3 || nextWordID == 4 || nextWordID == 5 || nextWordID == 6 || nextWordID == 7 || nextWordID == 8 || nextWordID == 10)
		{
			cout << "ERROR(21): 在 " << topWord.getData() << "与" << nextWord.getData() << " 之间，缺少逻辑运算符 or 或者 and。" << endl;
			cout << "\t文件: " << fname << "\t行: " << nextWord.getRows() << endl;
			cout << "\t可行的修改方案: 请尝试添加逻辑运算符 or 与 and。" << endl;
		}
		else
		{
			cout << "-* 语法分析 *- 状态 " << state << " 在遇到可识别的单词 " << nextWord.getData() << " 时，仍然进入了错误处理子程序中 " << "<未知的错误>" << endl;
			exit(-1);
		}
		break;
	}
	case 2:
	{
		if (nextWordID == 0 || nextWordID == 1 || nextWordID == 4 || nextWordID == 6 || nextWordID == 9)
		{
			cout << "ERROR(22): 界符 not 后缺少 not 或 ( 或 数字字母 或 true 或 false。" << endl;
			cout << "\t文件: " << fname << "\t行: " << nextWord.getRows() << endl;
			cout << "\t可行的修改方案: 修改not逻辑运算符附近的表达式。" << endl;
		}
		else
		{
			cout << "-* 语法分析 *- 状态 " << state << " 在遇到可识别的单词 " << nextWord.getData() << " 时，仍然进入了错误处理子程序中 " << "<未知的错误>" << endl;
			exit(-1);
		}
		break;
	}
	case 3:
	{
		if (nextWordID == 0 || nextWordID == 1 || nextWordID == 4 || nextWordID == 6 || nextWordID == 9)
		{
			cout << "ERROR(23): 界符 ( 后缺少 not 或 ( 或 数字字母 或 true 或 false。" << endl;
			cout << "\t文件: " << fname << "\t行: " << nextWord.getRows() << endl;
			cout << "\t可行的修改方案: 修改界符附近的表达式。" << endl;
		}
		else
		{
			cout << "-* 语法分析 *- 状态 " << state << " 在遇到可识别的单词 " << nextWord.getData() << " 时，仍然进入了错误处理子程序中 " << "<未知的错误>" << endl;
			exit(-1);
		}
		break;
	}
	case 4:
	{
		if (nextWordID != 6)
		{
			cout << "ERROR(24): 字母或数字后缺少运算符。" << endl;
			cout << "\t文件: " << fname << "\t行: " << nextWord.getRows() << endl;
			cout << "\t可行的修改方案: 在出错位置添加合适运算符。" << endl;
		}
		else
		{
			cout << "-* 语法分析 *- 状态 " << state << " 在遇到可识别的单词 " << nextWord.getData() << " 时，仍然进入了错误处理子程序中 " << "<未知的错误>" << endl;
			exit(-1);
		}
		break;
	}
	case 5:
	{
		if (nextWordID != 0 && nextWordID != 1 && nextWordID != 4 && nextWordID != 9)
		{
			cout << "ERROR(25): true 后 缺少 or 或 and 或 )。" << endl;
			cout << "\t文件: " << fname << "\t行: " << nextWord.getRows() << endl;
			cout << "\t可行的修改方案: 在出错位置添加合适的逻辑运算符或界符。" << endl;
		}
		else
		{
			cout << "-* 语法分析 *- 状态 " << state << " 在遇到可识别的单词 " << nextWord.getData() << " 时，仍然进入了错误处理子程序中 " << "<未知的错误>" << endl;
			exit(-1);
		}
		break;
	}
	case 6:
	{
		if (nextWordID != 0 && nextWordID != 1 && nextWordID != 4 && nextWordID != 9)
		{
			cout << "ERROR(26): false 后 缺少 or 或 and 或 )。" << endl;
			cout << "\t文件: " << fname << "\t行: " << nextWord.getRows() << endl;
			cout << "\t可行的修改方案: 在出错位置添加合适的逻辑运算符或界符。" << endl;
		}
		else
		{
			cout << "-* 语法分析 *- 状态 " << state << " 在遇到可识别的单词 " << nextWord.getData() << " 时，仍然进入了错误处理子程序中 " << "<未知的错误>" << endl;
			exit(-1);
		}
		break;
	}
	case 7:
	{
		if (nextWordID == 0 || nextWordID == 1 || nextWordID == 4 || nextWordID == 6 || nextWordID == 9)
		{
			cout << "ERROR(27): 逻辑运算符 or 后缺少合法表达式。" << endl;
			cout << "\t文件: " << fname << "\t行: " << nextWord.getRows() << endl;
			cout << "\t可行的修改方案: 修改 or 后的逻辑表达式。" << endl;
		}
		else
		{
			cout << "-* 语法分析 *- 状态 " << state << " 在遇到可识别的单词 " << nextWord.getData() << " 时，仍然进入了错误处理子程序中 " << "<未知的错误>" << endl;
			exit(-1);
		}
		break;
	}
	case 8:
	{
		if (nextWordID == 0 || nextWordID == 1 || nextWordID == 4 || nextWordID == 6 || nextWordID == 9)
		{
			cout << "ERROR(28): 逻辑运算符 and 后缺少合法表达式。" << endl;
			cout << "\t文件: " << fname << "\t行: " << nextWord.getRows() << endl;
			cout << "\t可行的修改方案: 修改 and 后的逻辑表达式。" << endl;
		}
		else
		{
			cout << "-* 语法分析 *- 状态 " << state << " 在遇到可识别的单词 " << nextWord.getData() << " 时，仍然进入了错误处理子程序中 " << "<未知的错误>" << endl;
			exit(-1);
		}
		break;
	}
	case 9:
	{
		if (nextWordID != 0 && nextWordID != 1 && nextWordID != 4 && nextWordID != 9)
		{
			cout << "ERROR(29): not类逻辑表达式只能出现在or/and逻辑运算符的操作数部分或者括号中。" << endl;
			cout << "\t文件: " << fname << "\t行: " << nextWord.getRows() << endl;
			cout << "\t可行的修改方案: 修改not类逻辑表达式附近的层次或逻辑关系。" << endl;
		}
		else
		{
			cout << "-* 语法分析 *- 状态 " << state << " 在遇到可识别的单词 " << nextWord.getData() << " 时，仍然进入了错误处理子程序中 " << "<未知的错误>" << endl;
			exit(-1);
		}
		break;
	}
	case 10:
	{
		if (nextWordID != 0 && nextWordID != 1 && nextWordID != 4)
		{
			cout << "ERROR(30): ()类表达式内部的表达式不合理。" << endl;
			cout << "\t文件: " << fname << "\t行: " << nextWord.getRows() << endl;
			cout << "\t可行的修改方案: 修改()类表达式内部表达式的层次或逻辑关系。" << endl;
		}
		else
		{
			cout << "-* 语法分析 *- 状态 " << state << " 在遇到可识别的单词 " << nextWord.getData() << " 时，仍然进入了错误处理子程序中 " << "<未知的错误>" << endl;
			exit(-1);
		}
		break;
	}
	case 11:
	{
		if (nextWordID != 5)
		{
			cout << "ERROR(31): 运算符 " << topWord.getData() << " 后缺少数字或字母。" << endl;
			cout << "\t文件: " << fname << "\t行: " << nextWord.getRows() << endl;
			cout << "\t可行的修改方案: 在对应运算符后添加合法的数字或字母。" << endl;
		}
		else
		{
			cout << "-* 语法分析 *- 状态 " << state << " 在遇到可识别的单词 " << nextWord.getData() << " 时，仍然进入了错误处理子程序中 " << "<未知的错误>" << endl;
			exit(-1);
		}
		break;
	}
	case 12: case 13: case 14: case 15:
	{
		if (nextWordID != 0 && nextWordID != 1 && nextWordID != 4 && nextWordID != 9)
		{
			cout << "ERROR(32): 词语"<< nextWord.getData()<< "位置不合法。" << endl;
			cout << "\t文件: " << fname << "\t行: " << nextWord.getRows() << endl;
			cout << "\t可行的修改方案: 修改对应词语的位置。" << endl;
		}
		else
		{
			cout << "-* 语法分析 *- 状态 " << state << " 在遇到可识别的单词 " << nextWord.getData() << " 时，仍然进入了错误处理子程序中 " << "<未知的错误>" << endl;
			exit(-1);
		}
		break;
	}
	default:
		cout << "-* 语法分析 *- 在错误处理程序中，出现了不可识别的状态参数 <未知的错误>" << endl;
		exit(-1);
	}
}
// 移进函数
bool doMoveIn(vector<Word> &symbolStack, vector<int> &stateStack, Word word)
{
	if (word.getData() != "#")
		symbolStack.push_back(word);		// 输入串首字母进栈
	int topState = stateStack.back();
	int newState = SLR[topState][word.getID()];
	if (newState == -1)
	{
		// 错误
		return false;
	}
	// 操作
	stateStack.push_back(newState);	// 对应状态进栈
	return true;
}
// 规约函数
bool doStatute(vector<Word> &symbolStack, vector<int> &stateStack, int exper_id)
{
	int out_num = WORD_NUM_IN_STATUTE[exper_id];	// 要出栈的数目
	Word statuteWord = Word(-1, -1, -1, LEFT_WORD_IN_STATUTE[exper_id], -1); // 规约产生的符号
	if (LEFT_WORD_IN_STATUTE[exper_id] == "S")
		statuteWord.setID(11);
	else
		statuteWord.setID(10);
	for (int i = 0; i < out_num; ++i)
	{
		symbolStack.pop_back();	// 符号栈出栈
		stateStack.pop_back();	// 状态栈出栈
	}
	int topState = stateStack.back();
	int newState = SLR[topState][statuteWord.getID()];
	if (newState == -1)
	{
		// 错误
		return false;
	}
	// 操作
	stateStack.push_back(newState);	// 状态进栈
	symbolStack.push_back(statuteWord);	// 规约后的左部符号进栈
	return true;
}
// 终结判断
bool isACC(vector<Word> &symbolStack, Word word)
{
	Word topWord = symbolStack.back();
	if (topWord.getID() == 10 && word.getData() == "#")
		return true;
	return false;
}
// 重新设置所有单词在SLR分析表中的ID
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
				cout << "-* 语法分析 *-\t词法分析合理后，仍出现了无法识别的单词 <未知的错误>" << endl;
				exit(-1);
			}
		}
	}
}
// 输出状态栈
void printStateStack(vector<int> stateStack)
{
	int length = stateStack.size();
	for (int i = 0; i < length; ++i)
	{
		cout << stateStack[i] << ' ';
	}
}
// 输出符号栈
void printSymbolStack(vector<Word> symbolStack)
{
	int length = symbolStack.size();
	for (int i = 0; i < length; ++i)
	{
		symbolStack[i].doPrintDataByID();
		cout << " ";
	}
}
// 语法分析函数
bool doGrammaticalAnalysis(vector<Word> wordsVector, string fname)
{
	vector<Word> symbolStack;			// 符号栈
	vector<int> stateStack;				// 状态栈
	int length = wordsVector.size();
	int STATE = 0;						// 记录当前状态并初始化为 0
	stateStack.push_back(STATE);		// 初状态进栈
	Word startWord = Word(12, 6, -1, "$", 0);
	symbolStack.push_back(startWord);	// 开始符号进栈
	int i = 0;							// 取词index
	int num = 0;						// 循环计数
	bool flag = true;					// 循环结束的标志
	bool hasError = false;				// 记录是否有语法错误
	cout << "过程号，状态栈 → 符号栈 → 待输入串" << endl;
	while (flag)
	{
		// 打印当前信息
		cout << setw(3) << num << " → ";
		printStateStack(stateStack);
		cout << " → ";
		printSymbolStack(symbolStack);
		cout << " → ";
		for (int j = i; j < length; ++j)
		{
			wordsVector[j].doPrintDataByID();
			cout << ' ';
		}
		cout << endl;

		Word tempWord;
		if (i == length)	// 获取第i个词语，输入串结束后则保持最后一个输入符号
			tempWord = wordsVector[length-1];
		else
			tempWord = wordsVector[i];
		int topState = stateStack.back();
		int wordID = tempWord.getID();
		int slr = SLR_S[topState][wordID];	// 获取SLR_S表中，判断这一步是规约还是移进
		if (slr == 0)	// 移进
		{
			if (!doMoveIn(symbolStack, stateStack, tempWord))
			{
				// 报错
				hasError = true;
				flag = false;
				doPrintErrors(tempWord, stateStack.back(), fname, symbolStack.back());
			}
			else
				++i;
		}
		else if (slr == -1)	// 规约
		{
			if (SLR[topState][wordID] == -1)
			{
				// 报错
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
					// 报错
					flag = false;
					hasError = true;
					doPrintErrors(tempWord, stateStack.back(), fname, symbolStack.back());
				}
			}
			else
			{
				if (!doStatute(symbolStack, stateStack, SLR[topState][wordID]))
				{
					// 报错
					hasError = true;
					flag = false;
					doPrintErrors(tempWord, stateStack.back(), fname, symbolStack.back());
				}
			}
		}
		else // 错误
		{
			cout << "-* 词语分析 *-\t词法分析后的字串中出现了S / E <未知的错误>" << endl;
			exit(-1);
		}
		num++;
	} // while
	return !hasError;
}