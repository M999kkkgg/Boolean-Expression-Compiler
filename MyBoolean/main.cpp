#include"AnalysisFunctions.h"

int main()
{
	char flag = 'y';
	char tempSpace = 'n';
	cout << "★ 请选择半自动分析模式和全手动分析模式" << endl;
	cout << "\ty - 半自动分析模式：选择选择读取文件类型，是否重定向到文件保存，是否进行下一条布尔表达式分析" << endl;
	cout << "\tn - 全手动分析模式：包括半自动分析模式全部功能，另添加是否进行下一类型分析判断" << endl;
	cout << "[Y/n]: ";
	flag = getchar();
	tempSpace = getchar();
	if (flag == 'Y' || flag == 'y')
	{
		cout << "★ 该模式为半自动模式" << endl;
		autoAnalysis();
	}
	else
	{
		cout << "★ 该模式为全手动模式" << endl;
		handAnalysis();
	}
	return 0;
}