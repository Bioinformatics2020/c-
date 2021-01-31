#include<string.h>
#include"加减乘除.h"

int main()
{
	int a = 0;
	do
	{
		printf("想进行什么运算：\n");
		printf("1 加法	2 减法\n3 乘法	4 除法\n");
		printf("请输入代号：\n");
		int model = 0;
		for(;;)
		{
			scanf("%d", &model);
			if (model >= 1 && model <= 4)
				break;
			else
				printf("模式选择错误，请重新选择：\n");
		}
		char arr1[100] = { 0 };
		char arr2[100] = { 0 };
		printf("请输入第一个数字\n");
		back1:
		scanf("%s", &arr1);
		int len1 = strlen(arr1);
		int* num1 = (int*)malloc(len1 * 4);	
		for (int i = 0; i < len1; i++)//将字符串1转换为数组
		{			
			num1[i] = arr1[i] - 48;
			if (num1[i] < 0 || num1[i] > 9)
			{
				printf("第%d个数字“%c”输入错误\n\n", i+1,arr1[i]);
				printf("请重新输入第一个数字\n");
				free(num1);
				goto back1;				
			}
		}
		printf("请输入第二个数字\n");
		back2:
		scanf("%s", &arr2);
		int len2 = strlen(arr2);
		int* num2 = (int*)malloc(len2 * 4);
		for (int i = 0; i < len2; i++)//将字符串2转换为数组
		{
			num2[i] = arr2[i] - 48;
			if (num2[i] < 0 || num2[i] > 9)
			{
				printf("第%d个数“%c”输入错误\n\n", i + 1,arr2[i]);
				printf("请重新输入第二个数字\n");
				free(num2);
				goto back2;
			}
		}
		//以上为输入部分
		void(*p[])(int*, int*, int, int) = { add,subtraction,product,quotient };//使用函数指针数组来选择模式
		(*p[model - 1])(num1, num2, len1, len2);//解引用各种功能的函数,同时会输出结果
		free(num1);//释放申请的内存
		free(num2);
		//到此，单次运算完成
		printf("\n\n继续运算吗？1 是  2 否\n");
		scanf("%d", &a);
	} while (a == 1);
	if (a != 2)
		printf("选择错误，默认为否\n");
	printf("Exit!");
	return 0;
}