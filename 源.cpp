#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//void two_to_twox(int num1[], int sz,int x)
//{
//	int n;
//	if (sz % x == 0)
//		n = sz / x;
//	else
//		n = sz / x + 1;
//	int* num2 = (int*)malloc(n * 4);
//	int j = 1;
//	int i = 1;
//	for (; j <= n; i += x)
//	{
//		if (j != n && x == 2)
//			num2[n - j] = num1[sz - i] + num1[sz - i - 1] * 2;
//		else if (j != n && x == 3)
//			num2[n - j] = num1[sz - i] + num1[sz - i - 1] * 2 + num1[sz - i - 2] * 4;
//		else if (j != n && x == 4)
//			num2[n - j] = num1[sz - i] + num1[sz - i - 1] * 2 + num1[sz - i - 2] * 4 + num1[sz - i - 3] * 8;
//		else if (j != n && x == 5)
//			num2[n - j] = num1[sz - i] + num1[sz - i - 1] * 2 + num1[sz - i - 2] * 4 + num1[sz - i - 3] * 8 + num1[sz - i - 4] * 16;
//		else
//		{
//			if ((sz - i) % x == 0)
//				num2[n - j] = num1[sz - i];
//			else if ((sz - i) % x == 1)
//				num2[n - j] = num1[sz - i] + num1[sz - i - 1] * 2;
//			else if ((sz - i) % x == 2)
//				num2[n - j] = num1[sz - i] + num1[sz - i - 1] * 2 + num1[sz - i - 2] * 4;
//			else if ((sz - i) % x == 3)
//				num2[n - j] = num1[sz - i] + num1[sz - i - 1] * 2 + num1[sz - i - 2] * 4 + num1[sz - i - 3] * 8;
//			else if ((sz - i) % x == 4)
//				num2[n - j] = num1[sz - i] + num1[sz - i - 1] * 2 + num1[sz - i - 2] * 4 + num1[sz - i - 3] * 8 + num1[sz - i - 4] * 16;
//		}
//		j++;
//	}
//	int a = 1;;
//	for (int i = 0; i < x; i++)
//	{
//		a *= 2;
//	}
//	printf("%d进制数为：",a);
//	for (int i = 0; i < n; i++)
//	{
//		if (num2[i] >= 10)
//			printf("%c", num2[i] + 55);
//		else
//			printf("%d", num2[i]);
//	}
//	printf("\n");
//}

int division(int num3[], int sz, int y, int x)//大数除法
{
	int remainder = 0;
	for (int i = 0; i < sz; i++)
	{
		if (i + 1 < sz)
			num3[i + 1] += (num3[i] % x) * y;
		else
			remainder = num3[i] % x;
		num3[i] /= x;
	}
	return remainder;
}

void y_to_x(int num1[], int sz, int y,int x)
{
	int n = 0;
	int* num3 = (int*)malloc(sz * 4);
	int* num2 = (int*)malloc(sz * 4 * x);
	for (int i = 0; i < sz; i++)
	{
		num3[i] = num1[i];
	}
	for (int i = 0;; i++)
	{
		num2[i] = division(num3, sz, y, x);
		n++;
		int j;
		for (j = 0; j < sz; j++)
		{
			if (num3[j] > 0)
				break;
		}
		if (j == sz)
			break;
	}
	printf("%d进制为：", x);
	for (int i = n-1; i >=0; i--)
	{
		if (num2[i] >= 10)
			printf("%c", num2[i] + 55);
		else
			printf("%c", num2[i] + 48);
	}
	printf("\n");
}

int main()
{
	printf("请选择进制转换功能:\n");
	printf("代号 输入进制 \n");
	printf("  1    2进制  \n");
	printf("  2    4进制  \n");
	printf("  3    8进制  \n");
	printf("  4   16进制  \n");
	printf("  5   32进制  \n");
	printf("  6   10进制  \n");
	printf("  7 自定义转换\n");
	printf("请输入代号：");
	int mode=1;
back:
	scanf("%d", &mode);
	if (mode != 7)
	{
		printf("请输入想转换的数\n");
		char num[100] = { 0 };
		scanf("%s", &num);
		printf("\n");
		int sz = strlen(num);
		int* num1 = (int*)malloc(sz * 4);
		for (int i = 0; i < sz; i++)
		{
			if (num[i] >= 48 && num[i] <= 57)
				num1[i] = num[i] - 48;
			if (num[i] >= 65 && num[i] <= 90)
				num1[i] = num[i] - 65;
			if (num[i] >= 97 && num[i] <= 122)
				num1[i] = num[i] - 97;
		}
		switch (mode)
		{
		case 1:
			y_to_x(num1, sz, 2, 4);
			y_to_x(num1, sz, 2, 8);
			y_to_x(num1, sz, 2, 16);
			y_to_x(num1, sz, 2, 32);
			y_to_x(num1, sz, 2, 10);
			break;
		case 2:
			y_to_x(num1, sz, 4, 2);
			y_to_x(num1, sz, 4, 8);
			y_to_x(num1, sz, 4, 16);
			y_to_x(num1, sz, 4, 32);
			y_to_x(num1, sz, 4, 10);
			break;
		case 3:
			y_to_x(num1, sz, 8, 2);
			y_to_x(num1, sz, 8, 4);
			y_to_x(num1, sz, 8, 16);
			y_to_x(num1, sz, 8, 32);
			y_to_x(num1, sz, 8, 10);
			break;
		case 4:
			y_to_x(num1, sz, 16, 2);
			y_to_x(num1, sz, 16, 4);
			y_to_x(num1, sz, 16, 8);
			y_to_x(num1, sz, 16, 32);
			y_to_x(num1, sz, 16, 10);
			break;
		case 5:
			y_to_x(num1, sz, 32, 2);
			y_to_x(num1, sz, 32, 4);
			y_to_x(num1, sz, 32, 8);
			y_to_x(num1, sz, 32, 16);
			y_to_x(num1, sz, 32, 10);
			break;
		default:
			printf("请重新选择代号:\n");
			goto back;
		}
	}
	else
	{
		printf("输入的数进制为几，输出的数进制为几？");
		int y, x;
		scanf("%d%d", &y, &x);
		printf("\n");
		printf("请输入想转换的数：");
		scanf("%d");
		char num[100] = { 0 };
		scanf("%s", &num);
		printf("\n");
		int sz = strlen(num);
		int* num1 = (int*)malloc(sz * 4);
		for (int i = 0; i < sz; i++)
		{
			if (num[i] >= 48 && num[i] <= 57)
				num1[i] = num[i] - 48;
			if (num[i] >= 65 && num[i] <= 90)
				num1[i] = num[i] - 65;
			if (num[i] >= 97 && num[i] <= 122)
				num1[i] = num[i] - 97;
		}
		y_to_x(num1, sz, y, x);
	}
	return 0;
}