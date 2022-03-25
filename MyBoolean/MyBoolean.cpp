#include"AnalysisFunctions.h"

// 打印读入的全部代码
void showReadCodes(vector<string> codes, int length)
{
	for (int i = 0; i < length; ++i)
	{
		cout << "■■■ 文件: code0" << i << ".txt ■■■" << endl;
		cout << codes[i] << endl;
	}
	cout << "以上为读入的全部代码串，共 " << length << "组" << endl;
}

// 暂停函数，flag为真时，则执行完清屏
void PAUSE(bool flag)
{
	char JUDGE;
	JUDGE = getchar();
	if (JUDGE == 'Y' || JUDGE == 'y')
	{
		JUDGE = getchar();
		cout << endl;
		if (flag)
			system("cls");
	}
	else
	{
		JUDGE = getchar();
		if (flag)
			system("cls");
		exit(0);
	}
}

// 打印词语ID
void doPrintAllWordID(vector<Word> wordsVector)
{
	int length = wordsVector.size();
	int i = 0;
	for (; i < length; ++i)
	{
		cout << wordsVector[i].getID();
		cout << '\t';
		cout << wordsVector[i].getData() << '\t';
		if ((i + 1) % 2 == 0)
			cout << endl;
	}
	if (i % 2 != 0)
		cout << endl;
}

// 打印SLR
void doPrintSLR()
{
	cout << "state     or   and  not   (    )   id  rop  true false  #   E" << endl;
	for (int i = 0; i < STATE_NUM; ++i)
	{
		cout << i << "\t| ";
		for (int j = 0; j < WORD_NUM; ++j)
		{
			if (SLR[i][j] == -1)
				cout << "   | ";
			else
			{
				if (SLR_S[i][j] == 0)
					cout << 'S' << setiosflags(ios::left) << setw(2) << SLR[i][j] << "| ";
				else if (SLR_S[i][j] == -1)
				{
					if (SLR[i][j] == 0)
						cout << "acc| ";
					else
						cout << 'r' << setiosflags(ios::left) << setw(2) << SLR[i][j] << "| ";
				}
				else 
					cout << setw(3) << SLR[i][j] << "| ";
			}
		}
		cout << endl;
	}
}

// 打印词法分析后的全部词语
void doPrintWordsVector(vector<Word> wordsVector)
{
	int length = wordsVector.size();
	cout << "$ ";
	for (int i = 0; i < length; ++i)
	{
		cout << wordsVector[i].getData() << " ";
	}
}

// int转为string
string getString(int n)
{
	std::stringstream newstr;
	newstr << n;
	return newstr.str();
}

// 半自动分析子程序
void autoAnalysis()
{
	// 初始化读文件路径
	char root[MAX_PATH];
	_getcwd(root, MAX_PATH);
	string inPath = "\\input\\";
	string outPath = "\\output\\";
	string nextDir = "codeAll\\";
	// cout << openFileName << endl;
	// 初始化写文件类
	OutFile output = OutFile(root + outPath, "");

	char spaceC = '\n';	// 用于去除做getchar的缓冲

	/*
		读文件
	*/
	vector<string> myCodes;		// 存放读到的代码
	// 判断批量读取还是选择指定文件读取
	char readFlag = 'y';
	cout << "-* 读取文件 *- 是否进行批量读取代码文件" << endl;
	cout << "\ty - 读取codeAll.txt文件内容，读取前请确认文件中代码分割格式是否正确" << endl;
	cout << "\tn - 读取code00.txt - code09.txt文件内容" << endl;
	cout << "[Y/n]: ";
	readFlag = getchar();
	spaceC = getchar();
	if (readFlag == 'Y' || readFlag == 'y')	// 读取 codeAll.txt
	{
		string temp;
		string *myCodesSTR;
		int codeNum = 0;
		string openFileName = root + inPath + "codeAll.txt";
		if (readCode(openFileName, temp))
			codeNum = doCutCode(myCodesSTR, temp);
		else
		{
			cout << "没有找到文件" << endl;
			exit(-1);
		}
		if (codeNum <= 0)
		{
			cout << "文件中没有合法的代码串(查看是否缺少结束符)" << endl;
			exit(-1);
		}
		for (int i = 0; i < codeNum; ++i)
		{
			myCodes.push_back(myCodesSTR[i]);
		}
	}
	else // 读取code00.txt-code09.txt
	{
		for (int i = 0; i < MAX_READ_FILE_NUM; ++i)
		{
			string temp;
			string openFileName = root + inPath + READ_FILE_NAMES[i];
			if (readCode(openFileName, temp))
				myCodes.push_back(temp);
		}
		cout << endl;
	}
	// 打印读到的代码
	showReadCodes(myCodes, myCodes.size());
	cout << endl;

	// 打印SLR
	cout << "SLR(1)分析表" << endl;
	doPrintSLR();
	cout << endl;

	// 判断继续
	cout << "★ 下一步，词法分析 [Y/n]: y" << endl;
	// PAUSE(true);

	// 对每一个代码串进行分析
	int myCodesLength = myCodes.size();
	int startIndex = 0;
	char flag = 'n';
	for (int i = startIndex; i < myCodesLength; ++i)
	{
		ofstream LexOut;
		ofstream GraOut;
		ofstream SemOut;
		// 打开写入文件，等待写入
		if (readFlag == 'Y' || readFlag == 'y')
		{
			LexOut = ofstream(string(root) + outPath + nextDir + getString(i) + "_1_LexicalAnalysis_Result.txt");
			GraOut = ofstream(string(root) + outPath + nextDir + getString(i) + "_2_GrammaticalAnalysis_Result.txt");
			SemOut = ofstream(string(root) + outPath + nextDir + getString(i) + "_3_SemanticAnalysis_Result.txt");
		}
		else
		{
			LexOut = ofstream(string(root) + outPath + OUT_DIR_NAMES[i] + "1 LexicalAnalysis_Result.txt");
			GraOut = ofstream(string(root) + outPath + OUT_DIR_NAMES[i] + "2 GrammaticalAnalysis_Result.txt");
			SemOut = ofstream(string(root) + outPath + OUT_DIR_NAMES[i] + "3 SemanticAnalysis_Result.txt");
		}
		streambuf *oldCout = cout.rdbuf();
		vector<Word> wordsVector;
		vector<int> statesVector;

		// 信息显示
		cout << "★ 当前处理文件 ★" << endl;
		if (readFlag == 'Y' || readFlag == 'y')
		{
			cout << "codeAll.txt -- " << i << endl;
		}
		else
			cout << READ_FILE_NAMES[i] << endl;
		cout << endl;

		/*
			词法分析模块
		*/
		// 是否要重定向输出到文件中
		cout << "-* 词法分析 *- 是否要将计算过程重定向到输出文件 [Y/n]: ";
		flag = getchar();
		if (flag == 'Y' || flag == 'y')
			oldCout = cout.rdbuf(LexOut.rdbuf());
		spaceC = getchar();
		// 读取单词
		wordsVector = doLexicalAnalysis(myCodes[i], READ_FILE_NAMES[i], statesVector);
		// 分析过程
		int wordVectorLength = wordsVector.size();
		cout << "序号\t" << "一级分类\t\t" << "二级分类\t" << "行标记\t" << "字符(串)" << endl;
		for (int j = 0; j < wordVectorLength; ++j)	// 输出分析后的每一个单词
		{
			wordsVector[j].doPrint();
		}
		int errorNum = doFindLexicalErrors(wordsVector, READ_FILE_NAMES[i]);
		// 恢复输出到控制台
		if (flag == 'Y' || flag == 'y')
			cout.rdbuf(oldCout);

		// 本地存储单词
		// output.setDir(OUT_DIR_NAMES[i]);
		// output.doOutputWords("LexicalAnalysis_Result.txt", wordsVector, statesVector);

		// 判断是否需要进行语法分析
		if (errorNum != 0)
		{
			cout << "☆ 词法分析后发现代码串存在错误，是否继续分析下面的文件 [Y/n]: y" << endl;
			// PAUSE(true);
			continue;
		}
		else
		{
			cout << "☆ 词法分析没有错误" << endl;
		}
		// 判断下一步是否进行语法分析
		cout << "★ 下一步，语法分析 [Y/n]: y" << endl;
		// PAUSE(true);

		// 信息显示
		cout << "★ 当前处理文件 ★" << endl;
		if (readFlag == 'Y' || readFlag == 'y')
		{
			cout << "codeAll.txt -- " << i << endl;
		}
		else
			cout << READ_FILE_NAMES[i] << endl;
		cout << endl;

		/*
			语法分析模块
		*/
		// 是否要重定向输出到文件中
		cout << "-* 语法分析 *- 是否要将计算过程重定向到输出文件 [Y/n]: ";
		flag = getchar();
		if (flag == 'Y' || flag == 'y')
			oldCout = cout.rdbuf(GraOut.rdbuf());
		spaceC = getchar();
		// 分析过程
		doSetAllID(wordsVector);	// 重新标记词语ID
		cout << "-* 语法分析 *- 重新标记后的词语ID" << endl;
		doPrintAllWordID(wordsVector);
		cout << "-* 语法分析 *- 词语串如下" << endl;
		doPrintWordsVector(wordsVector);
		cout << endl;
		cout << "-* 语法分析 *- 开始\t\t文件: " << READ_FILE_NAMES[i] << endl;
		bool isGrammaticalOK = doGrammaticalAnalysis(wordsVector, READ_FILE_NAMES[i]);
		if (isGrammaticalOK)
			cout << "☆ 语法分析没有错误" << endl;
		// 恢复输出到控制台
		if (flag == 'Y' || flag == 'y')
			cout.rdbuf(oldCout);

		// 判断出错的情况下是否继续
		if (!isGrammaticalOK)
		{
			cout << "☆ 语法分析后发现该代码串存在错误，是否继续分析下面的文件 [Y/n]: y" << endl;
			// PAUSE(true);
			continue;
		}

		// 判断下一步是否进行语义分析
		cout << "★ 下一步，语义分析 [Y/n]: y" << endl;
		// PAUSE(true);

		// 信息显示
		cout << "★ 当前处理文件 ★" << endl;
		if (readFlag == 'Y' || readFlag == 'y')
		{
			cout << "codeAll.txt -- " << i << endl;
		}
		else
			cout << READ_FILE_NAMES[i] << endl;
		cout << endl;

		/*
			语义分析模块
		*/
		// 是否要重定向输出到文件中
		cout << "-* 语义分析 *- 是否要将计算过程重定向到输出文件 [Y/n]: ";
		flag = getchar();
		if (flag == 'Y' || flag == 'y')
			oldCout = cout.rdbuf(SemOut.rdbuf());
		spaceC = getchar();
		// 重新定义ID
		setWordInSemantic(wordsVector);
		printWordInSemantic(wordsVector);
		// 语义分析过程
		bool result = SemanticAnalysis(wordsVector);
		if (result)
			cout << "布尔表达式值 = true" << endl;
		else
			cout << "布尔表达式值 = false" << endl;

		// 恢复输出到控制台
		if (flag == 'Y' || flag == 'y')
			cout.rdbuf(oldCout);

		// 关闭打开的文件
		LexOut.close();
		GraOut.close();
		SemOut.close();

		// 继续分析下一个代码串
		cout << "★ 继续分析下面的文件 [Y/n]: ";
		PAUSE(true);
	}
	cout << "全部代码串文件处理完成" << endl;
}

// 手动操作分析步骤子程序
void handAnalysis()
{
	// 初始化读文件路径
	char root[MAX_PATH];
	_getcwd(root, MAX_PATH);
	string inPath = "\\input\\";
	string outPath = "\\output\\";
	string nextDir = "codeAll\\";
	// cout << openFileName << endl;
	// 初始化写文件类
	OutFile output = OutFile(root + outPath, "");

	char spaceC = '\n';	// 用于去除做getchar的缓冲

	/*
		读文件
	*/
	vector<string> myCodes;		// 存放读到的代码
	// 判断批量读取还是选择指定文件读取
	char readFlag = 'y';
	cout << "-* 读取文件 *- 是否进行批量读取代码文件" << endl;
	cout << "\ty - 读取codeAll.txt文件内容，读取前请确认文件中代码分割格式是否正确" << endl;
	cout << "\tn - 读取code00.txt - code09.txt文件内容" << endl;
	cout << "[Y/n]: ";
	readFlag = getchar();
	spaceC = getchar();
	if (readFlag == 'Y' || readFlag == 'y')	// 读取 codeAll.txt
	{
		string temp;
		string *myCodesSTR;
		int codeNum = 0;
		string openFileName = root + inPath + "codeAll.txt";
		if (readCode(openFileName, temp))
			codeNum = doCutCode(myCodesSTR, temp);
		else
		{
			cout << "没有找到文件" << endl;
			exit(-1);
		}
		if (codeNum <= 0)
		{
			cout << "文件中没有合法的代码串(查看是否缺少结束符)" << endl;
			exit(-1);
		}
		for (int i = 0; i < codeNum; ++i)
		{
			myCodes.push_back(myCodesSTR[i]);
		}
	}
	else // 读取code00.txt-code09.txt
	{
		for (int i = 0; i < MAX_READ_FILE_NUM; ++i)
		{
			string temp;
			string openFileName = root + inPath + READ_FILE_NAMES[i];
			if (readCode(openFileName, temp))
				myCodes.push_back(temp);
		}
		cout << endl;
	}
	// 打印读到的代码
	showReadCodes(myCodes, myCodes.size());
	cout << endl;

	// 打印SLR
	cout << "SLR(1)分析表" << endl;
	doPrintSLR();
	cout << endl;

	// 判断继续
	cout << "★ 下一步，词法分析 [Y/n]: ";
	PAUSE(true);

	// 对每一个代码串进行分析
	int myCodesLength = myCodes.size();
	int startIndex = 0;
	char flag = 'n';
	for (int i = startIndex; i < myCodesLength; ++i)
	{
		ofstream LexOut;
		ofstream GraOut;
		ofstream SemOut;
		// 打开写入文件，等待写入
		if (readFlag == 'Y' || readFlag == 'y')
		{
			LexOut = ofstream(string(root) + outPath + nextDir + getString(i) + "_1_LexicalAnalysis_Result.txt");
			GraOut = ofstream(string(root) + outPath + nextDir + getString(i) + "_2_GrammaticalAnalysis_Result.txt");
			SemOut = ofstream(string(root) + outPath + nextDir + getString(i) + "_3_SemanticAnalysis_Result.txt");
		}
		else
		{
			LexOut = ofstream(string(root) + outPath + OUT_DIR_NAMES[i] + "1 LexicalAnalysis_Result.txt");
			GraOut = ofstream(string(root) + outPath + OUT_DIR_NAMES[i] + "2 GrammaticalAnalysis_Result.txt");
			SemOut = ofstream(string(root) + outPath + OUT_DIR_NAMES[i] + "3 SemanticAnalysis_Result.txt");
		}
		streambuf *oldCout = cout.rdbuf();
		vector<Word> wordsVector;
		vector<int> statesVector;

		// 信息显示
		cout << "★ 当前处理文件 ★" << endl;
		if (readFlag == 'Y' || readFlag == 'y')
		{
			cout << "codeAll.txt -- " << i << endl;
		}
		else
			cout << READ_FILE_NAMES[i] << endl;
		cout << endl;

		/*
			词法分析模块
		*/
		// 是否要重定向输出到文件中
		cout << "-* 词法分析 *- 是否要将计算过程重定向到输出文件 [Y/n]: ";
		flag = getchar();
		if (flag == 'Y' || flag == 'y')
			oldCout = cout.rdbuf(LexOut.rdbuf());
		spaceC = getchar();
		// 读取单词
		wordsVector = doLexicalAnalysis(myCodes[i], READ_FILE_NAMES[i], statesVector);
		// 分析过程
		int wordVectorLength = wordsVector.size();
		cout << "序号\t" << "一级分类\t\t" << "二级分类\t" << "行标记\t" << "字符(串)" << endl;
		for (int j = 0; j < wordVectorLength; ++j)	// 输出分析后的每一个单词
		{
			wordsVector[j].doPrint();
		}
		int errorNum = doFindLexicalErrors(wordsVector, READ_FILE_NAMES[i]);
		// 恢复输出到控制台
		if (flag == 'Y' || flag == 'y')
			cout.rdbuf(oldCout);

		// 本地存储单词
		// output.setDir(OUT_DIR_NAMES[i]);
		// output.doOutputWords("LexicalAnalysis_Result.txt", wordsVector, statesVector);

		// 判断是否需要进行语法分析
		if (errorNum != 0)
		{
			cout << "☆ 词法分析后发现代码串存在错误，是否继续分析下面的文件 [Y/n]: ";
			PAUSE(true);
			continue;
		}
		else
		{
			cout << "☆ 词法分析没有错误" << endl;
		}
		// 判断下一步是否进行语法分析
		cout << "★ 下一步，语法分析 [Y/n]: ";
		PAUSE(true);

		// 信息显示
		cout << "★ 当前处理文件 ★" << endl;
		if (readFlag == 'Y' || readFlag == 'y')
		{
			cout << "codeAll.txt -- " << i << endl;
		}
		else
			cout << READ_FILE_NAMES[i] << endl;
		cout << endl;

		/*
			语法分析模块
		*/
		// 是否要重定向输出到文件中
		cout << "-* 语法分析 *- 是否要将计算过程重定向到输出文件 [Y/n]: ";
		flag = getchar();
		if (flag == 'Y' || flag == 'y')
			oldCout = cout.rdbuf(GraOut.rdbuf());
		spaceC = getchar();
		// 分析过程
		doSetAllID(wordsVector);	// 重新标记词语ID
		cout << "-* 语法分析 *- 重新标记后的词语ID" << endl;
		doPrintAllWordID(wordsVector);
		cout << "-* 语法分析 *- 词语串如下" << endl;
		doPrintWordsVector(wordsVector);
		cout << endl;
		cout << "-* 语法分析 *- 开始\t\t文件: " << READ_FILE_NAMES[i] << endl;
		bool isGrammaticalOK = doGrammaticalAnalysis(wordsVector, READ_FILE_NAMES[i]);
		if (isGrammaticalOK)
			cout << "☆ 语法分析没有错误" << endl;
		// 恢复输出到控制台
		if (flag == 'Y' || flag == 'y')
			cout.rdbuf(oldCout);

		// 判断出错的情况下是否继续
		if (!isGrammaticalOK)
		{
			cout << "☆ 语法分析后发现该代码串存在错误，是否继续分析下面的文件 [Y/n]: ";
			PAUSE(true);
			continue;
		}

		// 判断下一步是否进行语义分析
		cout << "★ 下一步，语义分析 [Y/n]: ";
		PAUSE(true);

		// 信息显示
		cout << "★ 当前处理文件 ★" << endl;
		if (readFlag == 'Y' || readFlag == 'y')
		{
			cout << "codeAll.txt -- " << i << endl;
		}
		else
			cout << READ_FILE_NAMES[i] << endl;
		cout << endl;

		/*
			语义分析模块
		*/
		// 是否要重定向输出到文件中
		cout << "-* 语义分析 *- 是否要将计算过程重定向到输出文件 [Y/n]: ";
		flag = getchar();
		if (flag == 'Y' || flag == 'y')
			oldCout = cout.rdbuf(SemOut.rdbuf());
		spaceC = getchar();
		// 重新定义ID
		setWordInSemantic(wordsVector);
		printWordInSemantic(wordsVector);
		// 语义分析过程
		bool result = SemanticAnalysis(wordsVector);
		if (result)
			cout << "布尔表达式值 = true" << endl;
		else
			cout << "布尔表达式值 = false" << endl;

		// 恢复输出到控制台
		if (flag == 'Y' || flag == 'y')
			cout.rdbuf(oldCout);

		// 关闭打开的文件
		LexOut.close();
		GraOut.close();
		SemOut.close();

		// 继续分析下一个代码串
		cout << "★ 继续分析下面的文件 [Y/n]: ";
		PAUSE(true);
	}
	cout << "全部代码串文件处理完成" << endl;
}