#include"word.h"
#include"AnalysisFunctions.h"

// 词法分析函数
vector<Word> doLexicalAnalysis(string input, string fname, vector<int> &statesVector)
{
	cout << "-* 词法分析 *- 开始\t\t文件: " << fname << endl;
	vector<Word> wordsVector;
	if (wordsVector.size() != 0)
	{
		cout << "-* 词法分析 *-\t变量 wordsVector 不为空 <未知的错误>" << endl;
		exit(-1);
	}
	int length = input.length(); //输入串长度
	if (length == 0)
	{
		// 代码串为空
		Word tempWord1 = Word(-1, -1, -1, "error0", 0);
		wordsVector.push_back(tempWord1);
		return wordsVector;
	}
	int* rowsArray;
	rowsArray = new int[length];	// 存放每一个字符对应的行标记
	bool END_FLAG = false;		// 标记代码串中是否含有终止符号
	for (int i = 0, j = 0; i < length; ++i)	// 对每一个字符进行行标记
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
	// 在进行词法分析前先检验代码串是否合法终止
	if (!END_FLAG)
	{
		// 代码串无中止
		Word tempWord2 = Word(-2, -1, -1, "error1", 0);
		wordsVector.push_back(tempWord2);
		return wordsVector;
	}
	/*// 检查行标记是否正确
	for (int i = 0; i < length; ++i)
	{
		cout << rowsArray[i] << "  ";
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
	*/
	int STATE = 0;	// 设置初始状态
	int wordNum = 0;// 记录已经分割的词语
	char tempChar;
	int forNum = 0;	// 记录循环次数
	vector<char> charStack;	// 字符栈，存放已经读到的字符，在终结态读取后弹出
	cout << "-* 词法分析 *- 状态转换过程\t文件: " << fname  << endl;
	int i = 0;	// 字符串中第i个字符
	bool FLAG = true;	// 循环结束标志
	while (FLAG)	// 对于每一个字符
	{
		statesVector.push_back(STATE);	// 状态进入记录栈以方便之后保存
		cout << STATE << '\t';
		if ((forNum + 1) % 10 == 0)
			cout << endl;
		forNum++;
		// 当当前状态不是终结态时进行字符读取
		if (STATE < 1 || STATE>16)
		{
			tempChar = input[i];	// 读取字符
			++i;
			charStack.push_back(tempChar);	// 读到的字符进栈
		}
		// 状态转换并进行相应处理
		switch (STATE)
		{
		// 初态
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
		// 终结态
		case 1:	// 单个字母
		{
			int StackLength = charStack.size();
			Word tempWord = Word(wordNum, 3, -1, "", rowsArray[i - StackLength + 1]);
			tempWord.addCharToData(charStack[1]);	// 仅保留字母，忽略单引号
			charStack.clear();
			wordsVector.push_back(tempWord);
			wordNum++;
			STATE = 0;
			break;
		}
		case 2:	case 3: // 界符 (, )
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
		case 3:	// 界符 )
			break;
		*/
		case 4:	// 保留字或非法字母串
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
		case 5: case 6: case 7: case 8:	case 9: case 10: // 运算符类
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
		case 6:	// 小于等于 <=
			break;
		case 7:	// 大于 >
			break;
		case 8:	// 大于等于 >=
			break;
		case 9:
			break;
		case 10:
			break;
		*/
		case 11: case 12: case 13: case 14:	// 数字类
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
		case 15: // 其他字符看做一个单词
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
		case 16: // # 终结态
		{
			FLAG = false;
			Word tempWord = Word(wordNum, 6, -1, "#", rowsArray[i-1]);
			wordsVector.push_back(tempWord);
			wordNum++;
			break;
		}
		// 中间态
		case 20:
		{
			// 如果是字母
			if ((tempChar >= 'a' && tempChar <= 'z') || (tempChar >= 'A' && tempChar <= 'Z'))
			{
				STATE = 21;
			}
			// 如果不是字母
			else
			{
				// 错误处理子程序
				STATE = 0;
				int n = charStack.size();	//当前字符栈中的长度p
				n--;
				i = i - n;	// 回溯
				Word tempWord = Word(wordNum, 5, -1, "", rowsArray[i]);
				tempWord.addCharToData(charStack[0]);	// 把第一个进栈字符当做其他字符处理
				charStack.clear();	// 清空栈
				wordsVector.push_back(tempWord);
			}
			break;
		}
		case 21:
		{
			// 如果是单引号
			if (tempChar == '\'')
			{
				STATE = 1;
			}
			// 如果不是单引号
			else
			{
				// 错误处理子程序
				STATE = 0;
				int n = charStack.size();	//当前字符栈中的长度
				n--;
				i = i - n;	// 回溯
				Word tempWord = Word(wordNum, 5, -1, "", rowsArray[i]);
				tempWord.addCharToData(charStack[0]);	// 把第一个进栈字符当做其他字符处理
				charStack.clear();	// 清空栈
				wordsVector.push_back(tempWord);
			}
			break;
		}
		case 22:
		{
			// 如果是字母
			if ((tempChar >= 'a' && tempChar <= 'z') || (tempChar >= 'A' && tempChar <= 'Z'))
			{
				STATE = 22;
			}
			// 如果不是字母
			else
			{
				STATE = 4;
				i--;	// 回溯
				charStack.pop_back();
			}
			break;
		}
		case 23:
		{
			// 如果是 =
			if (tempChar == '=')
			{
				STATE = 6;
			}
			// 如果不是 =
			else
			{
				STATE = 5;
				i--;	// 回溯
				charStack.pop_back();
			}
			break;
		}
		case 24:
		{
			// 如果是 =
			if (tempChar == '=')
			{
				STATE = 8;
			}
			// 如果不是 =
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
			// 如果是 =
			if (tempChar == '=')
			{
				STATE = 9;
			}
			// 如果不是 =
			else
			{
				// 错误处理子程序
				STATE = 0;
				i--;	// 回溯
				Word tempWord = Word(wordNum, 5, -1, "", rowsArray[i]);
				tempWord.addCharToData(charStack[0]);	// 把第一个进栈字符当做其他字符处理
				charStack.clear();	// 清空栈
				wordsVector.push_back(tempWord);
			}
			break;
		}
		case 26:
		{
			// 如果是 =
			if (tempChar == '=')
			{
				STATE = 10;
			}
			// 如果不是 =
			else
			{
				// 错误处理子程序
				STATE = 0;
				i--;	// 回溯
				Word tempWord = Word(wordNum, 5, -1, "", rowsArray[i]);
				tempWord.addCharToData(charStack[0]);	// 把第一个进栈字符当做其他字符处理
				charStack.clear();	// 清空栈
				wordsVector.push_back(tempWord);
			}
			break;
		}
		case 27:
		{
			// 如果是数字
			if (tempChar >= '0'&&tempChar <= '9')
			{
				STATE = 28;
			}
			//如果不是数字
			else
			{
				// 错误处理子程序
				STATE = 0;
				int n = charStack.size();	//当前字符栈中的长度
				n--;
				i = i - n;	// 回溯
				Word tempWord = Word(wordNum, 5, -1, "", rowsArray[i]);
				tempWord.addCharToData(charStack[0]);	// 把第一个进栈字符当做其他字符处理
				charStack.clear();	// 清空栈
				wordsVector.push_back(tempWord);
			}
			break;
		}
		case 28:
		{
			// 如果是数字
			if (tempChar >= '0'&&tempChar <= '9')
			{
				STATE = 28;
			}
			// 如果是小数点
			else if (tempChar == '.')
			{
				STATE = 29;
			}
			// 其他
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
			// 如果是数字
			if (tempChar >= '0'&&tempChar <= '9')
			{
				STATE = 29;
			}
			// 如果不是数字
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
			// 如果是数字
			if (tempChar >= '0'&&tempChar <= '9')
			{
				STATE = 30;
			}
			// 如果是小数点
			else if (tempChar == '.')
			{
				STATE = 31;
			}
			// 其他
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
			// 如果是数字
			if (tempChar >= '0'&&tempChar <= '9')
			{
				STATE = 31;
			}
			// 其他
			else
			{
				STATE = 14;
				i--;
				charStack.pop_back();
			}
			break;
		}
		default:
			cout << "-* 词法分析 *- 出现无法识别的状态 <未知的错误>" << endl;
			exit(-1);
		} // switch
	} // for
	if ((forNum + 1) % 10 != 0)
		cout << endl;
	cout << "-* 词法分析 *- 完成\t文件: " << fname << endl;
	return wordsVector;
}

// 词法分析后收集错误函数
int doFindLexicalErrors(vector<Word> wordsVector, string fname)
{
	int errorNum = 0;
	int length = wordsVector.size();
	if (length == 0)
	{
		cout << "-* 词法分析 *- 词法分析后收集错误函数传入参数为空 <未知的错误>" << endl;
		return -1;
	}
	if (wordsVector[0].getID() == -1)
	{
		cout << "ERROR(0): 代码词串为空\t文件: " << fname << "\t行: 0" << endl;
		errorNum++;
		cout << "-* 词法分析 *- 共搜集到错误 " << errorNum << " 条\t文件: " << fname << endl;
		return errorNum;
	}
	else if (wordsVector[0].getID() == -2)
	{
		cout << "ERROR(1): 代码串中不含有结束符\t文件: " << fname << "\t行: ?" << endl;
		errorNum++;
		cout << "-* 词法分析 *- 共搜集到错误 " << errorNum << " 条\t文件: " << fname << endl;
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
				cout << "ERROR(10): 无法识别的字符 \' \t文件: " << fname << "\t行: " << tempWord.getRows() << endl;
				cout << "     可能的修改方法: 尝试引号中只保证有一个字母" << endl;
			}
			else if (tempWord.getData() == ".")
			{
				cout << "ERROR(11): 无法识别的字符 . \t文件: " << fname << "\t行: " << tempWord.getRows() << endl;
				cout << "     可能的修改方法: 尝试小数中只含有一个小数点" << endl;
			}
			else if (tempWord.getData() == "+")
			{
				cout << "ERROR(12): 无法识别的字符 + \t文件: " << fname << "\t行: " << tempWord.getRows() << endl;
				cout << "     可能的修改方法: 尝试去掉 + (正数忽略 + )" << endl;
			}
			else if (tempWord.getData() == "!")
			{
				cout << "ERROR(13): 无法识别的字符 ! \t文件: " << fname << "\t行: " << tempWord.getRows() << endl;
				cout << "     可能的修改方法: 尝试将 ! 替换为 !=" << endl;
			}
			else if (tempWord.getData() == "=")
			{
				cout << "ERROR(14): 无法识别的字符 = \t文件: " << fname << "\t行: " << tempWord.getRows() << endl;
				cout << "     可能的修改方法: 尝试将 = 替换为 ==" << endl;
			}
			else if (tempWord.getData() == "-")
			{
				cout << "ERROR(15): 无法识别的字符 - \t文件: " << fname << "\t行: " << tempWord.getRows() << endl;
				cout << "     可能的修改方法: 尝试在后面追加数字" << endl;
			}
			else if (tempWord.getData() == "！" || tempWord.getData() == "‘" || tempWord.getData() == "’" || tempWord.getData() == "（" || tempWord.getData() == "）" || tempWord.getData() == "。")
			{
				cout << "ERROR(18): 无法识别的字符 " << tempWord.getData() << "\t文件: " << fname << "\t行: " << tempWord.getRows() << endl;
				cout << "     可能的修改方法: 尝试替换为英文半角字符" << endl;
			}
			else if (tempWord.getData().size() > 1)
			{
				cout << "ERROR(16): 无法识别的保留字 " << tempWord.getData() << "\t文件: " << fname << "\t行: " << tempWord.getRows() << endl;
				cout << "     可能的修改方法: 修改为正确的保留字" << endl;
			}
			else
			{
				cout << "ERROR(17): 无法识别的字符 " << tempWord.getData() << "\t文件: " << fname << "\t行: " << tempWord.getRows() << endl;
				cout << "     可能的修改方法: 尝试删除或替换" << endl;
			}
		}
	}// for
	cout << "-* 词法分析 *- 共搜集到错误 " << errorNum << " 条\t文件: " << fname << endl;
	return errorNum;
}