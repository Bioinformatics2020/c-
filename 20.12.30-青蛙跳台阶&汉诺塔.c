#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int step(int n)
{
	int a = 1, b = 1, c = 1;
	for (n++;n>2;n--)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

int main()
{
	int n;
	printf("������̨����\n");
	scanf("%d", &n);
	printf("������Ϊ��%d\n", step(n));
	return 0;
}

//int frequency(int n)
//{
//	if (n > 1)
//		return frequency(n - 1) * 2 + 1;
//	else
//		return 1;
//}
//
//int main()
//{
//	int n;
//	printf("����Ϊ��");
//	scanf("%d", &n);
//	printf("���˴���Ϊ��%d\n", frequency(n));
//	return 0;
//}