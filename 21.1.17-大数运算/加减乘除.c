#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void add(int num1[], int num2[], int len1, int len2)//大数加法
{
	int m;
	if (len1 > len2)
		m = len1;
	else
		m = len2;
	int* sum = (int*)malloc((m + 1) * 4);//创建合适长度的sum数组
	for (int i = 0; i < m + 1; i++) //初始化sum数组
		sum[i] = 0;
	for (int i = 0; i < m; i++)//求和
	{
		if (len1 - 1 - i < 0)      //第一个数字加完了就不加第一个数
			sum[m - i] += num2[len2 - 1 - i];
		else if (len2 - 1 - i < 0) //第二个数字加完了就不加第二个数
			sum[m - i] += num1[len1 - 1 - i];
		else                       //第一第二的数字都没加完，就都加
			sum[m - i] += num1[len1 - 1 - i] + num2[len2 - 1 - i];

		if (sum[m - i] >= 10)      //判断是否进位
		{
			sum[m - i - 1] += 1;
			sum[m - i] %= 10;
		}
	}
	printf("\n结果为：\n");
	for (int i = 0; i < m + 1; i++)//输出结果
	{
		if (sum[0] == 0 && i == 0)
			continue;
		printf("%d", sum[i]);
	}
	free(sum);
}

void sub(int num1[], int num2[], int len1, int len2, int m)//已知长度关系后的大数减法
{
	int* different = (int*)malloc((len1) * 4);
	for (int j = 0; j < len1; j++) //初始化different数组
		different[j] = 0;
	for (int j = 0; j < len1; j++)//
	{
		if (len2 - 1 - j < 0)
			different[len1 - 1 - j] += num1[len1 - 1 - j];//考虑进位所以用加等
		else
			different[len1 - 1 - j] += num1[len1 - 1 - j] - num2[len2 - 1 - j];
		if (different[len1 - 1 - j] < 0)//判断借位
		{
			different[len1 - 1 - j] += 10;
			different[len1 - 2 - j] -= 1;
		}
	}
	printf("\n结果为：\n");
	for (int i = 0; i < len1; i++)//输出结果
	{
		if (different[i] != 0)//从第一个不是0的数开始输出
		{
			printf("%d", different[i] * m);
			for (int j = i + 1; j < len1; j++)
				printf("%d", different[j]);
			break;
		}
	}
	free(different);
}
void subtraction(int num1[], int num2[], int len1, int len2)//大数减法的大小关系判断
{
	int i;
	if (len1 == len2)//比较两个数长度,确定谁减谁
	{
		for (i = 0; i < len1;)//若长度相同，比较两个数大小,确定谁减谁
		{
			if (num1[i] > num2[i])
			{
				sub(num1, num2, len1, len2, 1);
				break;
			}
			else if (num1[i] < num2[i])
			{
				sub(num2, num1, len2, len1, -1);//-1表示最后是负数
				break;
			}
			else//若第一个数相同，比较下一个数
			{
				i++;
			}
		}
		if (i == len1)//若最后一个数都相等就输出0
			printf("0");
	}
	else if (len1 > len2)
		sub(num1, num2, len1, len2, 1);
	else
		sub(num2, num1, len2, len1, -1);
}

void product(int num1[], int num2[], int len1, int len2)//大数乘法
{
	int i;
	int len0 = len1 + len2;//确定product数组长度
	int* pr = (int*)malloc((len0) * 4);
	for (i = 0; i < len0; i++)//初始化product数组
		pr[i] = 0;
	for (i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			pr[len0 - 1 - i - j] += num1[len1 - 1 - i] * num2[len2 - 1 - j];//对每一位相乘
			if (pr[len0 - 1 - i - j] >= 10)//判断进位
			{
				pr[len0 - 1 - i - j - 1] += pr[len0 - 1 - i - j] / 10;
				pr[len0 - 1 - i - j] %= 10;
			}
		}
	}
	i = 0;
	if (pr[i] == 0)
		i++;
	printf("\n结果为：\n");
	for (; i < len0; i++)//从不为0的数开始输出
		printf("%d", pr[i]);
	free(pr);
}

int size(int* qu, int* num2, int len2)//大数除法大小关系比较
{
	if (qu[0] > 0)
		return 1;
	for (int i=0;i<len2; i++)
	{
		if (qu[i+1] > num2[i])
			return 1;
		if (qu[i+1] < num2[i])
			return -1;		
	}
	return 0;
}
void qu_move(int* qu,int len2,int a)//移动qu
{
	for (int i = 0; i < len2; i++)
		qu[i] = qu[i + 1];
	qu[len2] = a;
}
void quo_s(int* qu, int* num2, int len2)//求差
{
	for (int i = 0; i < len2; i++)
	{
		if (qu[len2 - i] < num2[len2 - i - 1])
		{
			qu[len2 - i - 1] -= 1;
			qu[len2 - i] += 10;		
		}
		qu[len2 - i] -= num2[len2 - i - 1];
	}
}
void quotient(int num1[], int num2[], int len1, int len2)//大数除法
{
	int count = 0;
	int point;
	printf("小数点后保留位数为：\n");
	scanf("%d", &point);
	int* qu = (int*)malloc((len2+1) * 4); 
	qu[0] = 0;
	for (int i = 0; i < len2; i++)//初始化被除数qu，
		qu[i + 1] = num1[i];
	printf("\n结果为：\n");
	int a = -1;
	for (int i = 0;;i++)
	{
		int j;		
		if(size(qu, num2, len2) == -1)//判断被除数是否要借一位
		{
			if (i + len2 < len1)
				qu_move(qu, len2, num1[i + len2]);			
			else
			{
				if (i + len2 == len1 && point != 0)//确定是否需要小数点以及小数点位置
					printf(".");
				qu_move(qu, len2, 0); 
				count++;
			}
		}
		for (j = 0; size(qu, num2, len2) != -1; j++)//被除数循环减除数
			quo_s(qu, num2, len2);			
		if (count < point||(point==0&&i+len2<len1-1))//判断是否是最后一位数，若是则四舍五入
			printf("%d", j);
		else
		{
			if (a == -1)
				a = j;
			else
			{
				printf("%d", (j >= 5 ? a + 1 : a));
				break;
			}
		}
	}
}