#include<string.h>
#include"�Ӽ��˳�.h"

int main()
{
	int a = 0;
	do
	{
		printf("�����ʲô���㣺\n");
		printf("1 �ӷ�	2 ����\n3 �˷�	4 ����\n");
		printf("��������ţ�\n");
		int model = 0;
		for(;;)
		{
			scanf("%d", &model);
			if (model >= 1 && model <= 4)
				break;
			else
				printf("ģʽѡ�����������ѡ��\n");
		}
		char arr1[100] = { 0 };
		char arr2[100] = { 0 };
		printf("�������һ������\n");
		back1:
		scanf("%s", &arr1);
		int len1 = strlen(arr1);
		int* num1 = (int*)malloc(len1 * 4);	
		for (int i = 0; i < len1; i++)//���ַ���1ת��Ϊ����
		{			
			num1[i] = arr1[i] - 48;
			if (num1[i] < 0 || num1[i] > 9)
			{
				printf("��%d�����֡�%c���������\n\n", i+1,arr1[i]);
				printf("�����������һ������\n");
				free(num1);
				goto back1;				
			}
		}
		printf("������ڶ�������\n");
		back2:
		scanf("%s", &arr2);
		int len2 = strlen(arr2);
		int* num2 = (int*)malloc(len2 * 4);
		for (int i = 0; i < len2; i++)//���ַ���2ת��Ϊ����
		{
			num2[i] = arr2[i] - 48;
			if (num2[i] < 0 || num2[i] > 9)
			{
				printf("��%d������%c���������\n\n", i + 1,arr2[i]);
				printf("����������ڶ�������\n");
				free(num2);
				goto back2;
			}
		}
		//����Ϊ���벿��
		void(*p[])(int*, int*, int, int) = { add,subtraction,product,quotient };//ʹ�ú���ָ��������ѡ��ģʽ
		(*p[model - 1])(num1, num2, len1, len2);//�����ø��ֹ��ܵĺ���,ͬʱ��������
		free(num1);//�ͷ�������ڴ�
		free(num2);
		//���ˣ������������
		printf("\n\n����������1 ��  2 ��\n");
		scanf("%d", &a);
	} while (a == 1);
	if (a != 2)
		printf("ѡ�����Ĭ��Ϊ��\n");
	printf("Exit!");
	return 0;
}