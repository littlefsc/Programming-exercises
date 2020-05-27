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
	printf("请输入链表元素的值，以0作为结束符");
	scanf("%d", &x);
	while (x != 0)//以0作为结束符
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
LNode *GetElem(LNode * head,int n)//查找第i个位置的元素
{
	int i = 1;
	LNode *p = head->next;
	if (i <= 0)
		return NULL;
	while (p&&i < n) {
		p = p->next;
		i++;
	}
	return p;             //返回第i个元素的指针，如果i大于表长，p=null
}
LNode *ListInsert(LNode * head, int n,int x)  //将X插入表第i个元素
{
	LNode *p = GetElem(head,n-1);    //找到第i个元素的指针
	LNode *s;
	s = (LNode*)malloc(sizeof(LNode));  //为新节点新增储存空间
	s->data = x;
	s->next = NULL;

	s->next = p->next;
	p->next = s;
	return head;                   //返回头节点
}
LNode *ListDelete(LNode * head, int x)   //删除元素为X的节点
{
	LNode *p = head->next,*q;  //指针C用来储存需要删除的节点
	q = head;
	while (!p&&p->data != x)
	{
		q = p;      //q指针始终指向p的前一位
		p = p->next;
	}
	if (p)         //如果找到了元素为x的节点P则执行删除操作
	{
		q->next = p->next;    
		free(p);
	}
	return(head);
}