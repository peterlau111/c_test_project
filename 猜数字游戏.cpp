#include "pch.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>						//rand函数头文件。
#include <time.h>                     //time函数头文件。
#define PASSWORD 970040

int main()
{
	int Password = 0;
	int Number = 0; 
	//int price = 9;					//谜底，改为随机数更有趣。
	int price;
//time_t time(time_t *timer),timer=NULL时得到当前日历时间（从1970-01-01 00:00:00到现在的秒数），timer=时间数值时，用于设置日历时间，time_t是一个unsigned long类型。
//如果 timer不为空，则返回值也存储在变量 timer中。
//srand函数是随机数发生器的初始化函数(播种)。原型：void srand(unsigned int seed);srand和rand()配合使用产生伪随机数序列。
//srand(unsigned seed)通过参数seed改变系统提供的种子值，从而可以使得每次调用rand函数生成的伪随机数序列不同。
	srand((unsigned)time(NULL));
	price = rand() % 100;                   //随机数取余100，得到一百以内整数。
	int i = 0;
	int bijiao_jieguo;

	while (Password != PASSWORD)
	{
		if (i >= 3)
			return -1;				//密码输入次数超过3次，退出。
		i++;						//记录密码输入次数。
		puts("请输入密码： ");
		scanf("%d", &Password);
	}

	i = 0;
	while (Number != price)
	{
		do {
			puts("请输入一个数字：1~100 ");
			scanf("%d", &Number);
			printf("你输入的是： %d\n", Number);
		} while (!(Number >= 1 && Number <= 100));

		bijiao_jieguo = Number - price;
		
		if (bijiao_jieguo>30)
		{
			printf("太大了，请重新输入!\n");
		}
		else if (bijiao_jieguo>20&&bijiao_jieguo<=30)
		{
			printf("有点大!\n");
		}
		else if (bijiao_jieguo > 10 && bijiao_jieguo <= 20)
		{
			printf("只大一点了!\n");
		}

		else if (bijiao_jieguo<-30)
		{
			printf("太小了，请重新输入!\n");
		}
		else if (bijiao_jieguo < -20 && bijiao_jieguo >= -30)
		{
			printf("有点小!\n");
		}
		else if (bijiao_jieguo < -10 && bijiao_jieguo >= -20)
		{
			printf("只小一点了!\n");
		}
		else
		{
			if (bijiao_jieguo == 0)
			{
				printf("太棒了，你猜对了，再见!\n");
			}
			else if (bijiao_jieguo < 0)
			{
				printf("只差非常小的一点小了，加油!\n");

			}
			else if (bijiao_jieguo>0)
				printf(" 只差非常小的一点大了，加油!\n");
		}
		_getch();
	}
	return 0;
}

