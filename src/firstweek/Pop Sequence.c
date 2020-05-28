#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxSize 100

typedef struct Node {  //栈基本结构的构造
	int data[MaxSize];
    int top;
}*Stack;

int StackCheck(int indata[], int outdata[], Stack S, int N, int M);
void Pop(Stack S);
void Push(Stack S, int x);



void main()
{
	int i, j;
	int M, N, K;//全局变量 栈容量为M，共有N个数入栈，有K组数据
	Stack S = (Stack)malloc(sizeof(struct Node));
	int flag;//记录出栈序列是否正确
	int outdata[MaxSize];
	int indata[MaxSize];
	scanf("%d%d%d", &M, &N, &K);
	for (j = 0; j < N; j++)//记录栈元素的输入顺序
	{
		scanf("%d", &indata[j]);
	}
	scanf("%d%d%d", &M, &N, &K);
	for (i = 0; i < K; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%d", &outdata[j]);//记录栈元素的输出顺序
		}
		flag = StackCheck(indata, outdata, S, N, M);
		if (flag == 1)
			printf("YES");
		else
			printf("NO");
	}
}

int StackCheck(int indata[], int outdata[], Stack S, int N, int M)
{
	S->top = -1;//初始化栈
	int num = 0;//指向数组outdata下一个将出栈的元素
	int i = 0, j = 0;//i指向入栈
	while (num <= N)//循环，让所有的outdata数组中的元素出栈
	{
		while (S->top = -1 && i != N || S->top != -1 && indata[i] <= outdata[num])//当栈为空或者栈中元素与下一个要出栈元素小于等于时执行入栈操作
		{
			if (S->top >= M - 1)  //判断栈满
			{
				return 0;
			}
			else
			{
				Push(S, indata[i]);
				i++;
			}
			
		}
		if (S->data[S->top] == outdata[num])//栈内元素等于出栈元素时，出栈，出栈元素后移一位
		{
			Pop(S);
			num++;//num自增1，指向下一个要出栈的元素
		}
		else if (S->data[S->top]>outdata[num])  //栈内元素大于输出元素时，说明不符合出栈顺序，返回0
		{
			return 0;
		}
	}
	return 1;

}
void  Pop(Stack S) //出栈
{
	int t = S->top;
	if (t == -1)
		printf("栈已空，出栈失败！");
	else
		S->top--;    //栈顶出栈，栈顶指针自减1
}
void Push(Stack S, int x)  //入栈
{
	if (S->top == MaxSize - 1)
		printf("栈已满，入栈失败！");
	else
	{
		S->data[S->top] = x;
		S->top++;//x入栈，栈顶指针自增1
	}
}