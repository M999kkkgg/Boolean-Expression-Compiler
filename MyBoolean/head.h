#pragma once
#include<string>
#include<math.h>
#include<iostream>
#include<vector>
#include<stack>
#include<iomanip>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<fstream>
using namespace std;
//ȫ���ĵ�������
const string WORD_TYPE[] = { "Reserved symbol", "Operator symbol", "Number symbol", "Letter symbol", "Boundary symbol", "Other symbol" , "End symbol"};
const int TYPE_NUM = 6;
//ȫ���ı�����
const string RESERVED_ALL[] = { "or", "and", "not", "true", "false" };
const int RESERVED_NUM = 5;
//ȫ���������
const string OPERATOR_ALL[] = { "<",">","<=",">=","==","!=" };
const int OPERATOR_NUM = 6;
//ȫ����ʶ�����������
const string NUMBER_ALL[] = { "-Int", "-Double", "+Int", "+Double" };
const int NUMBER_NUM = 4;
//��Լ���ʽ���Ҳ��ĵ�����
const int WORD_NUM_IN_STATUTE[] = { 1, 3, 3, 2, 3, 3, 1, 1 };
const string LEFT_WORD_IN_STATUTE[] = { "S", "E", "E", "E", "E", "E", "E", "E" };
//�����
const string WORD_LIST[] = { "or", "and", "not", "(", ")", "id", "rop", "true", "false", "#", "E", "S" };
//SLR ������������Ϊ״̬��������Ϊ�����Ӧ��ID
const int SLR[16][11] = {
	{-1, -1, 2, 3, -1, 4, -1, 5, 6, -1, 1},
	{7, 8, -1, -1, -1, -1, -1, -1, -1, 0, -1},
	{-1, -1, 2, 3, -1, 4, -1, 5, 6, -1, 9},
	{-1, -1, 2, 3, -1, 4, -1, 5, 6, -1, 10},
	{-1, -1, -1, -1, -1, -1, 11, -1, -1, -1, -1},
	{6, 6, -1, -1, 6, -1, -1, -1, -1, 6, -1},
	{7, 7, -1, -1, 7, -1, -1, -1, -1, 7, -1},
	{-1, -1, 2, 3, -1, 4, -1, 5, 6, -1, 13},
	{-1, -1, 2, 3, -1, 4, -1, 5, 6, -1, 14},
	{3, 3, -1, -1, 3, -1, -1, -1, -1, 3, -1},
	{7, 8, -1, -1, 15, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1, 12, -1, -1, -1, -1, -1},
	{5, 5, -1, -1, 5, -1, -1, -1, -1, 5, -1},
	{1, 8, -1, -1, 1, -1, -1, -1, -1, 1, -1},
	{2, 2, -1, -1, 2, -1, -1, -1, -1, 2, -1},
	{4, 4, -1, -1, 4, -1, -1, -1, -1, 4, -1}
};
// 0��ʾ�ƽ���1��ʾgoto��-1��ʾ��Լ
const int SLR_S[16][11] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1},
	{-1, -1, 0, 0, -1, 0, 0, 0, 0, -1, 1},
	{-1, -1, 0, 0, -1, 0, 0, 0, 0, -1, 1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1},
	{-1, -1, 0, 0, -1, 0, 0, 0, 0, -1, 1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1},
	{-1, -1, 0, 0, -1, 0, 0, 0, 0, -1, 1},
	{-1, 0, 0, 0, -1, 0, 0, 0, 0, -1, 1},
	{-1, -1, 0, 0, -1, 0, 0, 0, 0, -1, 1},
	{-1, -1, 0, 0, -1, 0, 0, 0, 0, -1, 1}
};
// ���ļ�ʱ���ļ���
const string READ_FILE_NAMES[10] = { "code00.txt","code01.txt","code02.txt","code03.txt","code04.txt","code05.txt",
									"code06.txt","code07.txt","code08.txt","code09.txt" };
const string OUT_DIR_NAMES[10] = { "code00\\","code01\\","code02\\","code03\\","code04\\","code05\\",
								"code06\\","code07\\","code08\\","code09\\" };
const int MAX_READ_FILE_NUM = 10;
const int STATE_NUM = 16;
const int WORD_NUM = 11;
// �������ʱ���ض���ID
// �±�ΪID��ֵΪ��Ӧ�ĵ��ʷ���
const string WORD_TYPE_SEM[] = { "or", "and", "not", "(", ")", ">", ">=", "<", "<=", "==", "!=", "id", "true", "false", "#" };
// �������ʱ�����ȼ�
// �±��ӦID��ֵ��Ӧ���ȼ�
const int PRIORITY[] = { 1, 2, 3, 0, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0 };