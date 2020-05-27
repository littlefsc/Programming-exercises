#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include <stdbool.h>
#define MaxSize 100

typedef struct {               
	int data[MaxSize];
	int top;
}SqStack;//顺序栈结构体

typedef struct LinkNode {
	int data;
	struct LinkNode *next;
}LinkNode;//链栈结构体

SqStack * InitStack(SqStack *S);
bool StackIsEmpty(SqStack *S);
SqStack * Push(SqStack *S, int x);
SqStack * Pop(SqStack *S, int x);
LinkNode * InitLiStack(LinkNode * head);
bool LiStackIsEmpty(LinkNode * head);
LinkNode * PushLiStack(LinkNode * head, int x);
LinkNode * PopLiStack(LinkNode * head, int x);

int main()
{

	return 0;
}

SqStack * InitStack(SqStack *S)  //初始化栈
{
	S->top = -1;     
	return S;
}
bool StackIsEmpty(SqStack *S)  //判断栈空
{
	if (S->top == -1)
		return true;
	else
		return false;
}
SqStack * Push(SqStack *S,int x)  //入栈
{
	if (S->top == MaxSize - 1)
		printf("栈已满，入栈失败！");
	else
	{
		S->data[++S->top]=x;      //x入栈，栈顶指针自增1
	}
	return S;
}
SqStack * Pop(SqStack *S, int x)
{
	bool t;
	t = StackIsEmpty(S);
	if (t)
		printf("栈已空，出栈失败！");
	else
		x = S->data[S->top--];    //栈顶出栈，栈顶指针自减1
	return S;
}

LinkNode * InitLiStack(LinkNode * head)
{
	head = NULL;
	return head;
}
bool LiStackIsEmpty(LinkNode * head)
{
	if (!head)
		return true;
	else
		return false;
}
LinkNode * PushLiStack(LinkNode * head,int x)     //链栈入栈
{
	LinkNode * L = (LinkNode*)malloc(sizeof(LinkNode));
	L->data = x;
	L->next = head->next;
	head->next = L;                            //头插法入栈
	return head;
}

LinkNode * PopLiStack(LinkNode * head, int x)  //链栈出栈
{
	if (head->next == NULL)
		printf("栈已空，出栈失败！");   //安全性检查，若栈空则出栈失败
	else
	{
		LinkNode *s;                 
		x = head->next->data;
		s = head->next;
		head->next = s->next;          //x记录出栈元素
		free(s);
	}
	return head;
}