#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string>

//void my_strcpy(char arr1[], char arr2[])//6��
//{
//	for (int i = 0; ; i++)
//	{
//		arr1[i] = arr2[i];
//		if (arr2[i] == '\0')
//			break;
//	}
//}

//void my_strcpy(char* arr1, char* arr2)
//{
//	while (arr2-1 != '\0')
//	{
//		*arr1++ = *arr2++;
//	}
//}

//void my_strcpy(char* arr1, char* arr2)//7��
//{
//	while (*arr1++ = *arr2++);
//}

//#include<assert.h>
//void my_strcpy(char* arr1, char* arr2)//8��
//{
//	assert(arr1 != NULL);
//	assert(arr2 != NULL);
//	if (arr1 != NULL && arr2 != NULL)
//	{
//		while (*arr1++ = *arr2++);
//	}
//}

//#include<assert.h>
//void my_strcpy(char* arr1,const char* arr2)//9��
//{
//	assert(arr1 != NULL);
//	assert(arr2 != NULL);
//	if (arr1 != NULL && arr2 != NULL)
//	{
//		while (*arr1++ = *arr2++);
//	}
//}

#include<assert.h>
char* my_strcpy(char* arr1, const char* arr2)//10��
{
	char* ret = arr1;
	assert(arr1 != NULL);//����
	assert(arr2 != NULL);//����
	if (arr1 != NULL && arr2 != NULL)//��arr2ָ������ݿ�����arr1ָ��Ŀռ���
	{
		while (*arr1++ = *arr2++);
	}
	return ret;
}

int main()
{
	char arr1[] = { "##########" };
	char arr2[] = { "hello" };
	my_strcpy(arr1, arr2);//��arr2������arr1
	printf("%s\n", arr1);
	return 0;
}