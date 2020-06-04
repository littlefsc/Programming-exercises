#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define ElementType int
#define MaxSize 1001

int A[MaxSize], T[MaxSize];

int compare(const void* a, const void* b);
void Solve(int Aleft, int Aright, int TRoot);
int GetLeftLength(int n);
int minfind(int a, int b);

int main(int argc, char const *argv[])
{
	int N, V;
	scanf("%d", &N);
	for (int i = 0; i<N; i++) {
		scanf("%d", &V);
		A[i] = V;
	}

	qsort(A, N, sizeof(int), compare);  // �����д�С��������

	Solve(0, N - 1, 0);

	int flag = 0;
	for (int i = 0; i<N; i++) {
		if (flag == 0) flag = 1;
		else printf(" ");
		printf("%d", T[i]);
	}
	printf("\n");


	return 0;
}

int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

void Solve(int ALeft, int ARight, int TRoot) {
	int n = ARight - ALeft + 1;
	if (n == 0) return;
	else {
		int L = GetLeftLength(n);  //�����������Ҷ��ٸ����
		T[TRoot] = A[ALeft + L];
		int LeftTRoot = TRoot * 2 + 1;
		int RightTRoot = LeftTRoot + 1;
		Solve(ALeft, ALeft + L - 1, LeftTRoot);
		Solve(ALeft + L + 1, ARight, RightTRoot);
	}
}

int GetLeftLength(int n) {
	int H = log(n + 1) / log(2);
	int X = n - pow(2, (double)H) + 1;
	int LeftLength = (int)pow(2, (double)(H - 1)) - 1 + minfind(X, (int)pow(2, (double)(H - 1)));
	return LeftLength;
}

int minfind(int a, int b) 
{
	return a < b ? a : b;
}
