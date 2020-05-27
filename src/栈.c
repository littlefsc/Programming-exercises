#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include <stdbool.h>
#define MaxSize 100

typedef struct {               
	int data[MaxSize];
	int top;
}SqStack;//˳��ջ�ṹ��

typedef struct LinkNode {
	int data;
	struct LinkNode *next;
}LinkNode;//��ջ�ṹ��

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

SqStack * InitStack(SqStack *S)  //��ʼ��ջ
{
	S->top = -1;     
	return S;
}
bool StackIsEmpty(SqStack *S)  //�ж�ջ��
{
	if (S->top == -1)
		return true;
	else
		return false;
}
SqStack * Push(SqStack *S,int x)  //��ջ
{
	if (S->top == MaxSize - 1)
		printf("ջ��������ջʧ�ܣ�");
	else
	{
		S->data[++S->top]=x;      //x��ջ��ջ��ָ������1
	}
	return S;
}
SqStack * Pop(SqStack *S, int x)
{
	bool t;
	t = StackIsEmpty(S);
	if (t)
		printf("ջ�ѿգ���ջʧ�ܣ�");
	else
		x = S->data[S->top--];    //ջ����ջ��ջ��ָ���Լ�1
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
LinkNode * PushLiStack(LinkNode * head,int x)     //��ջ��ջ
{
	LinkNode * L = (LinkNode*)malloc(sizeof(LinkNode));
	L->data = x;
	L->next = head->next;
	head->next = L;                            //ͷ�巨��ջ
	return head;
}

LinkNode * PopLiStack(LinkNode * head, int x)  //��ջ��ջ
{
	if (head->next == NULL)
		printf("ջ�ѿգ���ջʧ�ܣ�");   //��ȫ�Լ�飬��ջ�����ջʧ��
	else
	{
		LinkNode *s;                 
		x = head->next->data;
		s = head->next;
		head->next = s->next;          //x��¼��ջԪ��
		free(s);
	}
	return head;
}