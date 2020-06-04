#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define ElementType int

typedef struct AVLNode *Position;
typedef Position AVLTree;
struct AVLNode
{
	ElementType Data;
	AVLTree Left;
	AVLTree Right;
	int Height;
};

int Max(int a, int b);
AVLTree Insert(AVLTree T, ElementType X);
AVLTree LL(AVLTree A);
AVLTree LR(AVLTree A);
AVLTree RR(AVLTree A);
AVLTree RL(AVLTree A);
int GetHeight(AVLTree T);


int main(int argc, char const *argv[])
{
	int N, V;
	AVLTree T = NULL;
	scanf("%d", &N);
	if (N) {
		for (int i = 0; i<N; i++) {
			scanf("%d", &V);
			T = Insert(T, V);
		}
		printf("%d\n", T->Data);
	}
	else
		printf("0\n");

	return 0;
}


int Max(int a, int b) {
	return a>b ? a : b;
}

//��X����AVL����,���ҷ��ص������ƽ����
AVLTree Insert(AVLTree T, ElementType X) {
	if (!T)
	{  //���������,���½�����һ��������
		T = (AVLTree)malloc(sizeof(struct AVLNode));
		T->Data = X;
		T->Left = T->Right = NULL;
		T->Height = 1;
	}

	else if (X < T->Data)
	{
		T->Left = Insert(T->Left, X);  // ����������
		if ((GetHeight(T->Left) - GetHeight(T->Right)) == 2) //��Ҫ��LL��ת��LR
		{
			if (X < T->Left->Data) // �½�������A(Root)�����ӵ���������
				T = LL(T);
			else        // �½�����A������������������
				T = LR(T);
		}
	}

	else if (X > T->Data)
	{
		T->Right = Insert(T->Right, X);  // ����������
		if ((GetHeight(T->Right) - GetHeight(T->Left)) == 2) //��Ҫ��RR��ת����RL
		{
			if (X > T->Right->Data)
				T = RR(T);  // �½�������A(Root)���Һ���B����������
			else        // �½�������A(Root)���Һ���B����������
				T = RL(T);
		}
	}

	// else T->Data == X �������

	T->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;  // �������ĸ߶�,���Ҹ߶ȵ����ֵ+1

	return T;
}


// ��������LL
AVLTree LL(AVLTree A) {
	// �½�������A(Root)������B����������
	AVLTree B = A->Left;  // �����A������B
	A->Left = B->Right;  // A�����ӱ��B���Һ���
	B->Right = A;   //B���Һ��ӱ��A
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(GetHeight(B->Left), A->Height) + 1;

	return B;
}


// ����˫������LR
AVLTree LR(AVLTree A) {
	// �½�����A��������B��������C��
	A->Left = RR(A->Left);  // ��A��������B��һ���ҵ���RR
	return LL(A);  //�ٶ�A��һ������LL,���ظ��ڵ�C
}


// �ҵ�������RR
AVLTree RR(AVLTree A) {
	// �½�������A(Root)���Һ���B����������
	AVLTree B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(GetHeight(B->Right), A->Height) + 1;

	return B;
}


// ����˫������RL
AVLTree RL(AVLTree A) {
	// �½�������A(Root)���Һ���B����������
	A->Right = LL(A->Right);   // ��A���Һ���B��һ������RR
	return RR(A); //�ٶ�A��һ���ҵ���LL,���ظ��ڵ�C
}


// �߶Ⱥ���
int GetHeight(AVLTree T) {
	int HL, HR;
	if (T) {
		HL = GetHeight(T->Left);
		HR = GetHeight(T->Right);
		T->Height = Max(HL, HR) + 1;
	}
	else return 0;
	return T->Height;
}
