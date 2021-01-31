#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void add(int num1[], int num2[], int len1, int len2)//�����ӷ�
{
	int m;
	if (len1 > len2)
		m = len1;
	else
		m = len2;
	int* sum = (int*)malloc((m + 1) * 4);//�������ʳ��ȵ�sum����
	for (int i = 0; i < m + 1; i++) //��ʼ��sum����
		sum[i] = 0;
	for (int i = 0; i < m; i++)//���
	{
		if (len1 - 1 - i < 0)      //��һ�����ּ����˾Ͳ��ӵ�һ����
			sum[m - i] += num2[len2 - 1 - i];
		else if (len2 - 1 - i < 0) //�ڶ������ּ����˾Ͳ��ӵڶ�����
			sum[m - i] += num1[len1 - 1 - i];
		else                       //��һ�ڶ������ֶ�û���꣬�Ͷ���
			sum[m - i] += num1[len1 - 1 - i] + num2[len2 - 1 - i];

		if (sum[m - i] >= 10)      //�ж��Ƿ��λ
		{
			sum[m - i - 1] += 1;
			sum[m - i] %= 10;
		}
	}
	printf("\n���Ϊ��\n");
	for (int i = 0; i < m + 1; i++)//������
	{
		if (sum[0] == 0 && i == 0)
			continue;
		printf("%d", sum[i]);
	}
	free(sum);
}

void sub(int num1[], int num2[], int len1, int len2, int m)//��֪���ȹ�ϵ��Ĵ�������
{
	int* different = (int*)malloc((len1) * 4);
	for (int j = 0; j < len1; j++) //��ʼ��different����
		different[j] = 0;
	for (int j = 0; j < len1; j++)//
	{
		if (len2 - 1 - j < 0)
			different[len1 - 1 - j] += num1[len1 - 1 - j];//���ǽ�λ�����üӵ�
		else
			different[len1 - 1 - j] += num1[len1 - 1 - j] - num2[len2 - 1 - j];
		if (different[len1 - 1 - j] < 0)//�жϽ�λ
		{
			different[len1 - 1 - j] += 10;
			different[len1 - 2 - j] -= 1;
		}
	}
	printf("\n���Ϊ��\n");
	for (int i = 0; i < len1; i++)//������
	{
		if (different[i] != 0)//�ӵ�һ������0������ʼ���
		{
			printf("%d", different[i] * m);
			for (int j = i + 1; j < len1; j++)
				printf("%d", different[j]);
			break;
		}
	}
	free(different);
}
void subtraction(int num1[], int num2[], int len1, int len2)//���������Ĵ�С��ϵ�ж�
{
	int i;
	if (len1 == len2)//�Ƚ�����������,ȷ��˭��˭
	{
		for (i = 0; i < len1;)//��������ͬ���Ƚ���������С,ȷ��˭��˭
		{
			if (num1[i] > num2[i])
			{
				sub(num1, num2, len1, len2, 1);
				break;
			}
			else if (num1[i] < num2[i])
			{
				sub(num2, num1, len2, len1, -1);//-1��ʾ����Ǹ���
				break;
			}
			else//����һ������ͬ���Ƚ���һ����
			{
				i++;
			}
		}
		if (i == len1)//�����һ��������Ⱦ����0
			printf("0");
	}
	else if (len1 > len2)
		sub(num1, num2, len1, len2, 1);
	else
		sub(num2, num1, len2, len1, -1);
}

void product(int num1[], int num2[], int len1, int len2)//�����˷�
{
	int i;
	int len0 = len1 + len2;//ȷ��product���鳤��
	int* pr = (int*)malloc((len0) * 4);
	for (i = 0; i < len0; i++)//��ʼ��product����
		pr[i] = 0;
	for (i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			pr[len0 - 1 - i - j] += num1[len1 - 1 - i] * num2[len2 - 1 - j];//��ÿһλ���
			if (pr[len0 - 1 - i - j] >= 10)//�жϽ�λ
			{
				pr[len0 - 1 - i - j - 1] += pr[len0 - 1 - i - j] / 10;
				pr[len0 - 1 - i - j] %= 10;
			}
		}
	}
	i = 0;
	if (pr[i] == 0)
		i++;
	printf("\n���Ϊ��\n");
	for (; i < len0; i++)//�Ӳ�Ϊ0������ʼ���
		printf("%d", pr[i]);
	free(pr);
}

int size(int* qu, int* num2, int len2)//����������С��ϵ�Ƚ�
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
void qu_move(int* qu,int len2,int a)//�ƶ�qu
{
	for (int i = 0; i < len2; i++)
		qu[i] = qu[i + 1];
	qu[len2] = a;
}
void quo_s(int* qu, int* num2, int len2)//���
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
void quotient(int num1[], int num2[], int len1, int len2)//��������
{
	int count = 0;
	int point;
	printf("С�������λ��Ϊ��\n");
	scanf("%d", &point);
	int* qu = (int*)malloc((len2+1) * 4); 
	qu[0] = 0;
	for (int i = 0; i < len2; i++)//��ʼ��������qu��
		qu[i + 1] = num1[i];
	printf("\n���Ϊ��\n");
	int a = -1;
	for (int i = 0;;i++)
	{
		int j;		
		if(size(qu, num2, len2) == -1)//�жϱ������Ƿ�Ҫ��һλ
		{
			if (i + len2 < len1)
				qu_move(qu, len2, num1[i + len2]);			
			else
			{
				if (i + len2 == len1 && point != 0)//ȷ���Ƿ���ҪС�����Լ�С����λ��
					printf(".");
				qu_move(qu, len2, 0); 
				count++;
			}
		}
		for (j = 0; size(qu, num2, len2) != -1; j++)//������ѭ��������
			quo_s(qu, num2, len2);			
		if (count < point||(point==0&&i+len2<len1-1))//�ж��Ƿ������һλ������������������
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