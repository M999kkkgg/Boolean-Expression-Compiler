#include"AnalysisFunctions.h"

int main()
{
	char flag = 'y';
	char tempSpace = 'n';
	cout << "�� ��ѡ����Զ�����ģʽ��ȫ�ֶ�����ģʽ" << endl;
	cout << "\ty - ���Զ�����ģʽ��ѡ��ѡ���ȡ�ļ����ͣ��Ƿ��ض����ļ����棬�Ƿ������һ���������ʽ����" << endl;
	cout << "\tn - ȫ�ֶ�����ģʽ���������Զ�����ģʽȫ�����ܣ�������Ƿ������һ���ͷ����ж�" << endl;
	cout << "[Y/n]: ";
	flag = getchar();
	tempSpace = getchar();
	if (flag == 'Y' || flag == 'y')
	{
		cout << "�� ��ģʽΪ���Զ�ģʽ" << endl;
		autoAnalysis();
	}
	else
	{
		cout << "�� ��ģʽΪȫ�ֶ�ģʽ" << endl;
		handAnalysis();
	}
	return 0;
}