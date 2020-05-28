/*给一组格式为address data next的节点，按要求逆序输出
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

LNode * CreateLNode(int address[], int next[], int data[], int N, int firstadd);//将输入的数据按正确的顺序建立链表
LNode * Attach(int address[], int next[],int data[], int i);//尾插法新建一个链表结点
int Find(int linkedadd, int address[],int data[], int N);//通过下一个结点的地址找出下一个结点
LNode * func(LNode *head, int K);   //将每K个逆置的链表连接起来
LNode * Reverse(LNode *L, int K);//链表逆置函数
LNode * Link(LNode * L);//更新新链表的nextadd字段
void Print(LNode * L);//打印链表



int main()
{
	int address[MaxSize];
	int next[MaxSize];
	int data[MaxSize];
	int firstadd, N=0, K=0;
	int tempadd, tempdata, tempnext; 
	scanf("%d%d%d", &firstadd,&N,&K);//输入第一个节点的地址，节点数以及逆序输出的规则
	for (int i = 0; i < N; i++)
	{
		scanf("%d%d%d", &tempadd, &tempdata, &tempnext);
		address[i] =tempadd;
		next[i] = tempnext;//用两个数组分别储存结点的值和下一个结点的地址
		data[i] = tempdata;
	}
	LNode *head = CreateLNode(address, next,data, N, firstadd);
	//head = func(head, K);
	//Print(head);
	return 0;
}
LNode * CreateLNode(int address[],int next[],int data[],int N,int firstadd)  //创建链表
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
			printf("地址输入错误！");
		else
		{
			r->link = Attach(address, next,data, i);
			r = r->link;
		}
		N--;
		firstadd = next[i];  //firstadd一直指向下一个结点的地址 
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
int Find(int linkedadd, int address[], int data[], int N)    //找到下一个结点
{
	int i = 0;
	for (; i < N; i++)  //找出第一个节点的地址
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
	LNode *r=p->link; //r始终指向一个倒置运算中最后一个结点,q指向下一个运算中第一个结点
	while (r != NULL)
	{
		for (int i = 0; i < K; i++)  //判断语句，不足K个则取消逆置
		{
			if (r == NULL)
				break;
			r = r->link;
		}
		if (r != NULL)
		{
			p->link = Reverse(p, K);
			p = r;
			r = p->link;          //r指向下一轮循环的第一个结点，开启下一轮循环
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
	for (int i = 0; i < K; i++)  //头插法可使链表元素逆置
	{
		q = p->link;
		p->link = L->link;
		L->link = p;
		p = q;
	}
	return L;
}
LNode * Link(LNode * L)   //重新排列的链表中只有nextadd属性需要更新
{
	LNode *pre,*p;
	pre = L->link;
	p = pre->link;
	if (pre == NULL)
		printf("此链表为空");
	while (p != NULL)      //一次遍历，更新nextadd属性
	{
		pre->nextadd = p->add;
		pre = p;
		p = p->link;
	}
	if (p == NULL)
		pre->nextadd = -1;  //最后一个结点的下一个结点地址为-1
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