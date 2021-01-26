#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string>

//void my_strcpy(char arr1[], char arr2[])//6分
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

//void my_strcpy(char* arr1, char* arr2)//7分
//{
//	while (*arr1++ = *arr2++);
//}

//#include<assert.h>
//void my_strcpy(char* arr1, char* arr2)//8分
//{
//	assert(arr1 != NULL);
//	assert(arr2 != NULL);
//	if (arr1 != NULL && arr2 != NULL)
//	{
//		while (*arr1++ = *arr2++);
//	}
//}

//#include<assert.h>
//void my_strcpy(char* arr1,const char* arr2)//9分
//{
//	assert(arr1 != NULL);
//	assert(arr2 != NULL);
//	if (arr1 != NULL && arr2 != NULL)
//	{
//		while (*arr1++ = *arr2++);
//	}
//}

#include<assert.h>
char* my_strcpy(char* arr1, const char* arr2)//10分
{
	char* ret = arr1;
	assert(arr1 != NULL);//断言
	assert(arr2 != NULL);//断言
	if (arr1 != NULL && arr2 != NULL)//将arr2指向的内容拷贝到arr1指向的空间中
	{
		while (*arr1++ = *arr2++);
	}
	return ret;
}

int main()
{
	char arr1[] = { "##########" };
	char arr2[] = { "hello" };
	my_strcpy(arr1, arr2);//将arr2拷贝给arr1
	printf("%s\n", arr1);
	return 0;
}