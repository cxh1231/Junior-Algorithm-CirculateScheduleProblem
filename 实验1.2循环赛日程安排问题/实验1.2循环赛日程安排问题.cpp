// 实验1.2循环赛日程安排问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include "pch.h"
#include <iostream>
#include <math.h>
using namespace std;

int calendar[100][100];  //日程表数组

void GameTable(int k, int a[100][100]);
void PrintTable(int k, int a[100][100]);

int main()
{
	int k;
	cout << "输入K的值：" ;
	cin >> k;
	cout << "日程表如下" << endl;
	GameTable(k, calendar);
	PrintTable(k, calendar);
	return 0;
}

void GameTable(int k, int a[100][100])
{
	// n=2^k(k≥1)个选手参加比赛
	//二维数组a表示日程安排，数组下标从1开始
	int n = 2;  //k=0，2个选手比赛日程可直接求得
	//求解2个选手比赛日程，得到左上角元素
	a[1][1] = 1; a[1][2] = 2;
	a[2][1] = 2; a[2][2] = 1;
	for (int t = 1; t < k; t++)
		//迭代处理，依次处理2^2, …, 2^k个选手比赛日程
	{
		int temp = n; n = n * 2;
		//填左下角元素
		for (int i = temp + 1; i <= n; i++)
			for (int j = 1; j <= temp; j++)
				a[i][j] = a[i - temp][j] + temp;
		//左下角元素和左上角元素的对应关系
//填右上角元素
		for (int i = 1; i <= temp; i++)
			for (int j = temp + 1; j <= n; j++)
				a[i][j] = a[i + temp][(j + temp) % n];
		//填右下角元素
		for (int i = temp + 1; i <= n; i++)
			for (int j = temp + 1; j <= n; j++)
				a[i][j] = a[i - temp][j - temp];
	}
}

void PrintTable(int k, int a[100][100])
{
	double n = pow((double)2, k);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << a[i][j] << "　 ";
		}
		cout << endl<<endl;
	}
}




// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
