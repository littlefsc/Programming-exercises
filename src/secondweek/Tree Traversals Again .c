// 03-��3 Tree Traversals Again 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>
#define ElementType int
#define MaxSize 50
#define ERROR 999

/**************** Stack ******************/

typedef struct SNode *Stack;  //�ṹָ��
struct SNode {
	ElementType *Data;  //����
	int Top; // ջ��λ�õ������±�
};


// ������ջ
Stack CreateStack(void)
{
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Data = (ElementType*)malloc(MaxSize* sizeof(ElementType));
	S->Top = -1;

	return S;
}

// ��ջ
void Push(Stack PtrS, ElementType item)  // stack������͵�ָ��
{
	if (PtrS->Top == MaxSize - 1) // �ж����������� 0 �� MaxSize-1
	{
		printf("��ջ��\n");
		return;
	}
	else
	{
		PtrS->Data[++(PtrS->Top)] = item;
		/* �൱�ڣ�
		(PtrS->Top)++;
		PtrS->Data[PtrS->Top] = item;
		*/
		return;
	}
}

// ��
bool IsStackEmpty(Stack PtrS) {
	if (PtrS->Top == -1)
		return true;
	else return false;
}

// ��ջ
ElementType Pop(Stack PtrS)
{
	if (IsStackEmpty(PtrS)) {
		printf("��ջ��\n");
		return ERROR;
	}
	else
		return (PtrS->Data[(PtrS->Top)--]); // return ���±�Ϊtop�����ֵ��ͬʱTop-1
}
/**************** Stack ******************/

int pre[MaxSize], in[MaxSize], post[MaxSize];  // ȫ�ֱ���
void SolvePost(int preL, int inL, int postL, int n) {  // pre�����, in�����, post�����,�����ܳ���
	int root, i, L, R;
	if (n == 0) return;
	if (n == 1) {
		post[postL] = pre[preL];
		return;
	}
	root = pre[preL];
	post[postL + n - 1] = root;
	for (i = 0; i<n; i++) {
		if (in[inL + i] == root)
			break;
	}
	L = i; // ����������
	R = n - L - 1; // ����������=�ܳ���-������-��
	SolvePost(preL + 1, inL, postL, L);  // �������������
	SolvePost(preL + 1 + L, inL + 1 + L, postL + L, R);  // �������������
}



int main(int argc, char const *argv[])
{
	int N, i, data, flag = 0, pre_i = 0, in_i = 0;
	char catagory[5];
	Stack S;
	scanf("%d", &N);
	S = CreateStack();
	for (i = 0; i<2 * N; i++) {
		scanf("%s", catagory);
		if (!strcmp(catagory, "Push")) {
			scanf("%d", &data);
			pre[pre_i++] = data;
			Push(S, data);
		}
		else if (!strcmp(catagory, "Pop")) {
			in[in_i++] = Pop(S);
		}
	}
	// for(i=0; i<N; i++)
	//     printf("%d ", PostL[i]);
	// printf("\n");
	SolvePost(0, 0, 0, N);
	for (i = 0; i<N; i++) {
		if (flag == 0)
			flag = 1;
		else
			printf(" ");
		printf("%d", post[i]);
	}
	printf("\n");


}