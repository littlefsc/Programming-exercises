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
SqList * InitList()   //���Ի���
{
	int i = 0, n = 0;
	SqList *L;
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;
	return (L);
}
SqList * CreateList()   //����һ��������������
{
	SqList * L; int i = 1, n;
	L = InitList();
	printf("��������ݣ���0����\n");  //��0��Ϊ����Ľ�����  
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
	printf("��Ϊ%d\n", L->length);
}
int FindX(SqList * L, int x)       //���ұ����Ƿ���Ԫ��X
{
	int i = 0;
	while (i <= L->length&&L->data[i] != x)
		i++;
	if (i < L->length)
		return i;
	else
		return -1;
}
int DataGet(SqList * L, int i)  //��ȡ��I��Ԫ��
{
	if (i >= 0 && i < L->length)
	{
		printf("��%d��Ԫ����%d", i, L->length);
		return(L->data[i]);
	}
	else
		return -1;
}
SqList * ListInsert(SqList * L, int x, int n)
{
	if (n > L->length || n < 1)     //�жϲ��뷶Χ�Ƿ���Ч
		printf("����ķ�Χ��Ч");
	else
	{
		for (int i = L->length - 1; i > n; i++)
		{
			L->data[i + 1] = L->data[i];  //nԪ�غ������Ԫ�غ���һλ
		}
		L->data[n-1] = x;
		L->length++;
	}
	return (L);
}    //ָ��λ�ò���һ��Ԫ��
SqList * ListDelete(SqList * L, int x)
{
	int n = FindX(L, x);    //�ҵ�XԪ�ص�λ��
	if (n >= 0 && n < L->length)
	{
		for (int i = n; i < L->length; i++)
		{
			L->data[i] = L->data[i + 1];   //X֮���Ԫ��ǰ��һλ
			L->length--;
		}
	}
	return (L);
}
