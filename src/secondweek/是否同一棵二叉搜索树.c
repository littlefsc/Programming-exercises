#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode *Tree;
struct TreeNode {
	int v;
	Tree Left;
	Tree Right;
	int flag;
};

Tree MakeTree(int N);
Tree NewNode(int V);
Tree Insert(Tree T, int V);
int check(Tree T, int V);
int Judge(Tree T, int N);
void  ResetT(Tree T);
void FreeTree(Tree T);

int main() {
	int N, L, i;
	Tree T;

	scanf("%d", &N);
	while (N) {
		scanf("%d", &L);
		T = MakeTree(N);
		for (i = 0; i<L; i++) {
			if (Judge(T, N))
				printf("Yes\n");
			else
				printf("No\n");
			ResetT(T);  // ���T�е�flag
		}
		FreeTree(T);
		scanf("%d", &N);
	} // whileѭ������
	return 0;
}

Tree MakeTree(int N)
{
	Tree T;
	int i, V;
	scanf("%d", &V);
	T = NewNode(V);
	for (i = 1; i<N; i++) //i��1��ʼ,��Ϊ��һ�����Ѿ�������
	{
		scanf("%d", &V);
		T = Insert(T, V);
	}
	return T;
}


// �����½��,���ؽṹָ��
Tree NewNode(int V) {
	Tree T = (Tree)malloc(sizeof(struct TreeNode));
	T->v = V;
	T->Left = T->Right = NULL;
	T->flag = 0;
	return T;
}


// �ݹ�����µĽ��
Tree Insert(Tree T, int V) {
	if (!T)
		T = NewNode(V);
	else {
		if (V > T->v)
			T->Right = Insert(T->Right, V);
		else
			T->Left = Insert(T->Left, V);
	}
	return T;
}


/*����T�а�˳����������3 2 4 1�е�ÿ����
���ÿ�������������Ľ����ǰ������ֹ�����һ��
����(ĳ������������ǰ��δ���ֵĽ��)����һ��*/
int check(Tree T, int V) {
	if (T->flag)
	{//flag������0�����
		if (V < T->v)
			return check(T->Left, V);
		else if (V > T->v)
			return check(T->Right, V);
		else
			return 0;
	}
	else
	{// T->flag = 0 �����
		if (V == T->v)
		{
			T->flag = 1;
			return 1;
		}
		else
			return 0;
	}
}


int Judge(Tree T, int N) {
	int V, Tflag = 1;

	scanf("%d", &V);
	// �Ⱥ͸�����
	if (T->v != V)
		Tflag = 0;  // ���ﲻҪֱ��return 0,��Ȼ֮������Ͳ�����
	else
		T->flag = 1;

	// ���αȽϽ�����N-1����
	for (int i = 1; i<N; i++) {
		scanf("%d", &V);
		if ((Tflag) && (check(T, V)))
			Tflag = 1;
		else Tflag = 0;
	}
	return Tflag;
}

// ����flag, ���T�и�����flag
void  ResetT(Tree T) {
	if (T->Left)
		ResetT(T->Left);
	if (T->Right)
		ResetT(T->Right);
	T->flag = 0;
}

void FreeTree(Tree T) {
	if (T->Left)
		FreeTree(T->Left);
	if (T->Right)
		FreeTree(T->Right);
	free(T);
}
