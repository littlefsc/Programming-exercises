#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxSize 100

typedef struct Node {  //ջ�����ṹ�Ĺ���
	int data[MaxSize];
    int top;
}*Stack;

int StackCheck(int indata[], int outdata[], Stack S, int N, int M);
void Pop(Stack S);
void Push(Stack S, int x);



void main()
{
	int i, j;
	int M, N, K;//ȫ�ֱ��� ջ����ΪM������N������ջ����K������
	Stack S = (Stack)malloc(sizeof(struct Node));
	int flag;//��¼��ջ�����Ƿ���ȷ
	int outdata[MaxSize];
	int indata[MaxSize];
	scanf("%d%d%d", &M, &N, &K);
	for (j = 0; j < N; j++)//��¼ջԪ�ص�����˳��
	{
		scanf("%d", &indata[j]);
	}
	scanf("%d%d%d", &M, &N, &K);
	for (i = 0; i < K; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%d", &outdata[j]);//��¼ջԪ�ص����˳��
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
	S->top = -1;//��ʼ��ջ
	int num = 0;//ָ������outdata��һ������ջ��Ԫ��
	int i = 0, j = 0;//iָ����ջ
	while (num <= N)//ѭ���������е�outdata�����е�Ԫ�س�ջ
	{
		while (S->top = -1 && i != N || S->top != -1 && indata[i] <= outdata[num])//��ջΪ�ջ���ջ��Ԫ������һ��Ҫ��ջԪ��С�ڵ���ʱִ����ջ����
		{
			if (S->top >= M - 1)  //�ж�ջ��
			{
				return 0;
			}
			else
			{
				Push(S, indata[i]);
				i++;
			}
			
		}
		if (S->data[S->top] == outdata[num])//ջ��Ԫ�ص��ڳ�ջԪ��ʱ����ջ����ջԪ�غ���һλ
		{
			Pop(S);
			num++;//num����1��ָ����һ��Ҫ��ջ��Ԫ��
		}
		else if (S->data[S->top]>outdata[num])  //ջ��Ԫ�ش������Ԫ��ʱ��˵�������ϳ�ջ˳�򣬷���0
		{
			return 0;
		}
	}
	return 1;

}
void  Pop(Stack S) //��ջ
{
	int t = S->top;
	if (t == -1)
		printf("ջ�ѿգ���ջʧ�ܣ�");
	else
		S->top--;    //ջ����ջ��ջ��ָ���Լ�1
}
void Push(Stack S, int x)  //��ջ
{
	if (S->top == MaxSize - 1)
		printf("ջ��������ջʧ�ܣ�");
	else
	{
		S->data[S->top] = x;
		S->top++;//x��ջ��ջ��ָ������1
	}
}