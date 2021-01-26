#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int factorial(int n)//算n!的函数，利用循环
//{
//	for (int i = 1; i <= n; i++)
//	{
//		n *= i;
//	}
//	return n;
//}

int factorial(int n)//算n!的函数，利用函数递归
{
	if (n > 1)
	{
		return n*factorial(n - 1);
	}
	return 1;
}

int main()
{
	int n;
	scanf("%d", &n);
	return factorial(n);
}

//int main()//计算n！
//{
//	int a;
//	int b = 1;
//	printf("n=");
//	scanf_s("%d", &a);
//	for (int i = 1; i <= a; i++)
//	{
//		b *= i;
//	}
//	printf("\nn！=%d\n", b);
//	return 0;
//}

//int main()//计算∑n!
//{
//    int a;
//	int b = 1;
//	int c = 0;
//	printf("n=");
//	scanf_s("%d", &a);
//	for (int i = 1; i <= a; i++)
//	{
//		b *= i;
//		c += b;
//	}
//	printf("\n∑n!=%d\n", c);
//	return 0;
//}

//int main()//计算n!
//{
//	int a;
//	printf("n=");
//	scanf_s("%d", &a);
//	for (int n =a-1; n > 0; n--)
//	{
//		a *= n;
//	}
//	printf("\nn!=%d\n", a);
//	return 0;
//}

//int main()//计算∑n!
//{
//	int a;
//	int c = 0;
//	printf("n=");
//	scanf_s("%d", &a);
//	for (; a > 0; a--)
//	{
//		int b = a;
//		for (int n =a-1; n > 0; n--)
//	    {
//			b *= n;
//	    }
//		printf("\nn!=%d", b);
//		c += b;
//	}
//
//	printf("\n\n∑n!=%d\n", c);
//	return 0;
//}