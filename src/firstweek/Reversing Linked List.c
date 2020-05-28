/*��һ���ʽΪaddress data next�Ľڵ㣬��Ҫ���������
*/
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100005

typedef struct LNode {
	int add;
	int nextadd;
	int data;
	struct LNode * link;
}LNode;

LNode * CreateLNode(int address[], int next[], int data[], int N, int firstadd);//����������ݰ���ȷ��˳��������
LNode * Attach(int address[], int next[],int data[], int i);//β�巨�½�һ��������
int Find(int linkedadd, int address[],int data[], int N);//ͨ����һ�����ĵ�ַ�ҳ���һ�����
LNode * func(LNode *head, int K);   //��ÿK�����õ�������������
LNode * Reverse(LNode *L, int K);//�������ú���
LNode * Link(LNode * L);//�����������nextadd�ֶ�
void Print(LNode * L);//��ӡ����



int main()
{
	int address[MaxSize];
	int next[MaxSize];
	int data[MaxSize];
	int firstadd, N=0, K=0;
	int tempadd, tempdata, tempnext; 
	scanf("%d%d%d", &firstadd,&N,&K);//�����һ���ڵ�ĵ�ַ���ڵ����Լ���������Ĺ���
	for (int i = 0; i < N; i++)
	{
		scanf("%d%d%d", &tempadd, &tempdata, &tempnext);
		address[i] =tempadd;
		next[i] = tempnext;//����������ֱ𴢴����ֵ����һ�����ĵ�ַ
		data[i] = tempdata;
	}
	LNode *head = CreateLNode(address, next,data, N, firstadd);
	//head = func(head, K);
	//Print(head);
	return 0;
}
LNode * CreateLNode(int address[],int next[],int data[],int N,int firstadd)  //��������
{
	LNode * head, *r;
	head = (LNode*)malloc(sizeof(LNode));
	head->link = NULL;
	r = head;
	int i;
	while (N > 0)
	{
		i = Find(firstadd, address,data, N);
		if (i < 0)
			printf("��ַ�������");
		else
		{
			r->link = Attach(address, next,data, i);
			r = r->link;
		}
		N--;
		firstadd = next[i];  //firstaddһֱָ����һ�����ĵ�ַ 
	}
	return head;
}
LNode * Attach(int address[], int next[],int data[],int i)
{
	LNode  *p = NULL;
	p->link = NULL;
	p = (LNode*)malloc(sizeof(LNode));
	p->add = address[i];
	p->data = (data[i]);
	p->nextadd = next[i];
	return p;
}
int Find(int linkedadd, int address[], int data[], int N)    //�ҵ���һ�����
{
	int i = 0;
	for (; i < N; i++)  //�ҳ���һ���ڵ�ĵ�ַ
	{
		if (address[i] == linkedadd)
			break;
		else
			i++;
	}
	if (address[i] != linkedadd)
		return -1;
	else
		return i;
}
LNode * func(LNode *head, int K)
{
	LNode *p = head;
	LNode *r=p->link; //rʼ��ָ��һ���������������һ�����,qָ����һ�������е�һ�����
	while (r != NULL)
	{
		for (int i = 0; i < K; i++)  //�ж���䣬����K����ȡ������
		{
			if (r == NULL)
				break;
			r = r->link;
		}
		if (r != NULL)
		{
			p->link = Reverse(p, K);
			p = r;
			r = p->link;          //rָ����һ��ѭ���ĵ�һ����㣬������һ��ѭ��
		}
	}
	head = Link(head);
	return head;
}
LNode * Reverse(LNode *L, int K)
{
	LNode *p, *q;
	p = L->link;
	L->link = NULL;
	for (int i = 0; i < K; i++)  //ͷ�巨��ʹ����Ԫ������
	{
		q = p->link;
		p->link = L->link;
		L->link = p;
		p = q;
	}
	return L;
}
LNode * Link(LNode * L)   //�������е�������ֻ��nextadd������Ҫ����
{
	LNode *pre,*p;
	pre = L->link;
	p = pre->link;
	if (pre == NULL)
		printf("������Ϊ��");
	while (p != NULL)      //һ�α���������nextadd����
	{
		pre->nextadd = p->add;
		pre = p;
		p = p->link;
	}
	if (p == NULL)
		pre->nextadd = -1;  //���һ��������һ������ַΪ-1
	return L;
}
void Print(LNode * L)
{
	LNode * p=L->link;
	while (p != NULL)
	{
		printf("%d %d %d\n", p->add, p->data, p->nextadd);
	}
}