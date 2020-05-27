#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
typedef struct
{
	int data[MaxSize];
	int length;
}SqList;
SqList * InitList();
SqList * CreateList();
void PrintLength(SqList * L);
int FindX(SqList * L, int x);
int DataGet(SqList * L, int i);
SqList * ListInsert(SqList * L, int x, int n);
SqList * ListDelete(SqList * L, int x);
int main()
{
	SqList *L = CreateList();
	return 1;
}
SqList * InitList()   //初试化表
{
	int i = 0, n = 0;
	SqList *L;
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;
	return (L);
}
SqList * CreateList()   //创建一个表，并输入数据
{
	SqList * L; int i = 1, n;
	L = InitList();
	printf("请插入数据，以0结束\n");  //用0作为输入的结束符  
	scanf("%d", &n);
	while (i < MaxSize)
	{
		if (n == 0)
			break;
		scanf("%d", &n);
		L->data[i++] = n;
		L->length++;
		
	}
	return(L);
}
void PrintLength(SqList * L)
{
	printf("表长为%d\n", L->length);
}
int FindX(SqList * L, int x)       //查找表中是否有元素X
{
	int i = 0;
	while (i <= L->length&&L->data[i] != x)
		i++;
	if (i < L->length)
		return i;
	else
		return -1;
}
int DataGet(SqList * L, int i)  //读取第I个元素
{
	if (i >= 0 && i < L->length)
	{
		printf("第%d个元素是%d", i, L->length);
		return(L->data[i]);
	}
	else
		return -1;
}
SqList * ListInsert(SqList * L, int x, int n)
{
	if (n > L->length || n < 1)     //判断插入范围是否有效
		printf("插入的范围无效");
	else
	{
		for (int i = L->length - 1; i > n; i++)
		{
			L->data[i + 1] = L->data[i];  //n元素后的所有元素后移一位
		}
		L->data[n-1] = x;
		L->length++;
	}
	return (L);
}    //指定位置插入一个元素
SqList * ListDelete(SqList * L, int x)
{
	int n = FindX(L, x);    //找到X元素的位置
	if (n >= 0 && n < L->length)
	{
		for (int i = n; i < L->length; i++)
		{
			L->data[i] = L->data[i + 1];   //X之后的元素前移一位
			L->length--;
		}
	}
	return (L);
}
