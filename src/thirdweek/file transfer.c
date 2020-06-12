#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define  ElementType int
#define  SetName int
#define MaxSize 100
typedef ElementType SetType[MaxSize];

void Initialization(SetType S, int n);
void Check_connection(SetType S);
void Input_connection(SetType S);
void Check_network(SetType S, int n);
SetName Find(SetType S, ElementType X);
void Union(SetType S, SetName Root1, SetName Root2);

SetType S;//s作为全局变量

int main()
{
	int n;
	char in;
	scanf("%d\n", &n);
	Initialization(S, n);
	do
	{
		scanf("%c", &in); // 取第一个字符
		switch (in)
		{
		case 'I':
			Input_connection(S);
			break; // Union(Find)
		case 'C':
			Check_connection(S);
			break; // Find
		case 'S':
			Check_network(S, n);
			break; // 数集合的根
		}
	} while (in != 'S');
	return 0;
}

void Initialization(SetType S, int n)
{
	for (int i = 0; i < n; i++)
		S[i] = -1;
}
void Input_connection(SetType S)
{
	ElementType u, v;
	SetName Root1, Root2;
	scanf("%d %d\n", &u, &v);
	Root1 = Find(S, u - 1);
	Root2 = Find(S, v - 1);
	if (Root1 != Root2)
		Union(S, Root1, Root2);
}
void Check_connection(SetType S)
{
	ElementType u, v;
	SetName Root1, Root2;
	scanf("%d %d\n", &u, &v);
	Root1 = Find(S, u - 1);
	Root2 = Find(S, v - 1);
	if (Root1 == Root2)
		printf("yes\n");
	else
		printf("no\n");
}
void Check_network(SetType S, int n)
{
	int i, counter = 0;
	for (i = 0; i < n; i++)
	{
		if (S[i] < 0)
			counter++;
	}
	if (counter == 1)
		printf("The network is connected.\n");
	else
		printf("There are &d components.\n", counter);
}
SetName Find(SetType S, ElementType X)
{ //默认集合元素全部初始化为-1 
	for (; S[X] >= 0; X = S[X]);
	return X;
}
void Union(SetType S, SetName Root1, SetName Root2)
{
	if (S[Root2] < S[Root1])
		S[Root1] = Root2;
	else
	{
		if (S[Root1] == S[Root2])
			S[Root1]--;
		S[Root2] = Root1;
	}
}
