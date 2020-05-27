 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct LNode {
	int data;
	struct LNode *next;
}LNode ;

LNode * ListHeadInsert(LNode * head);
void ListPrient(LNode * head);
LNode *GetElem(LNode * head, int n);
LNode *ListInsert(LNode * head, int n, int x);
LNode *ListDelete(LNode * head, int x);


int main() {
	LNode *head = NULL;
	LNode *p=ListHeadInsert(head);  
	ListPrient(p);
	system("pause");
	return 0;
}

LNode * ListHeadInsert(LNode * head) {
	LNode *s; int x;
	head = (LNode*)malloc(sizeof(LNode));
	head->next = NULL;
	printf("����������Ԫ�ص�ֵ����0��Ϊ������");
	scanf("%d", &x);
	while (x != 0)//��0��Ϊ������
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = head->next;
		head->next = s;
		scanf("%d", &x);
	}
	return(head);
}
void ListPrient(LNode * head)
{
	LNode *L = head->next;
	while (L != NULL)
	{
		printf("%d", L->data);
		L = L->next;
	}
}
LNode *GetElem(LNode * head,int n)//���ҵ�i��λ�õ�Ԫ��
{
	int i = 1;
	LNode *p = head->next;
	if (i <= 0)
		return NULL;
	while (p&&i < n) {
		p = p->next;
		i++;
	}
	return p;             //���ص�i��Ԫ�ص�ָ�룬���i���ڱ���p=null
}
LNode *ListInsert(LNode * head, int n,int x)  //��X������i��Ԫ��
{
	LNode *p = GetElem(head,n-1);    //�ҵ���i��Ԫ�ص�ָ��
	LNode *s;
	s = (LNode*)malloc(sizeof(LNode));  //Ϊ�½ڵ���������ռ�
	s->data = x;
	s->next = NULL;

	s->next = p->next;
	p->next = s;
	return head;                   //����ͷ�ڵ�
}
LNode *ListDelete(LNode * head, int x)   //ɾ��Ԫ��ΪX�Ľڵ�
{
	LNode *p = head->next,*q;  //ָ��C����������Ҫɾ���Ľڵ�
	q = head;
	while (!p&&p->data != x)
	{
		q = p;      //qָ��ʼ��ָ��p��ǰһλ
		p = p->next;
	}
	if (p)         //����ҵ���Ԫ��Ϊx�Ľڵ�P��ִ��ɾ������
	{
		q->next = p->next;    
		free(p);
	}
	return(head);
}