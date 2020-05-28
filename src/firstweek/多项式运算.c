#define  _CRT_SECURE_NO_WARNINGS
#define elemtype int

#include<stdio.h>
#include<stdlib.h>
#include<math.h>


typedef struct Polynomial {
	elemtype coef;
	elemtype expon;
	struct Polynomial * next;

}Polynomial;


Polynomial * Attach(Polynomial *s, int coef, int expon);
Polynomial * ReadPoly();
Polynomial * Add(Polynomial *P1, Polynomial *P2);
void Print(Polynomial *head);

int main()           
{
	Polynomial *p1,*p2,*sum;
	p1=ReadPoly();
	p2=ReadPoly();
	sum = Add(p1, p2);
	Print(sum);
	return 0;
}

Polynomial * ReadPoly()
{
	Polynomial *head;
	head = (Polynomial*)malloc(sizeof(Polynomial));
	head->next = NULL;
	Polynomial * p=NULL,*r;
	r = head;
	printf("请输入多项式的长度：\n");
	int n,coef,expon;  
	scanf("%d", &n);
	while (n>0)
	{
		printf("请输入多项式的系数和次数\n");
		scanf("%d%d", &coef, &expon);
		r->next= Attach(p, coef, expon);
		r = r->next;                 //尾插法建立链表，r始终指向表尾节点
		n--;
	}
	return head;
}

Polynomial * Add(Polynomial *P1, Polynomial *P2)
{
	Polynomial *head,*p1,*p2,*s,*r;    
	head = (Polynomial*)malloc(sizeof(Polynomial));   //创建一个新链表用来储存两个多项式相加后的多项式,head为链表的头节点
	head->next = NULL;
	r = head;                 
	s = NULL;
	p1 = P1->next;
	p2 = P2->next;
	
	while (p1!= NULL&&p2!= NULL)  
	{
		if(p1->expon=p2->expon)         //次数相等则系数相加
		{
			r->next = Attach(s, (p1->coef + p2->coef), p1->expon);  
			r = r->next;
			p1 = p1->next;
			p2 = p2->next;
		}
		else if (p1->expon > p2->expon)  //次数大的先进入链表 
		{
			r->next = Attach(s, p1->coef, p1->expon);
			r = r->next;
			p1 = p1->next;
		}
		else
		{
			r->next = Attach(s, p2->coef, p2->expon);
			r = r->next;
			p2 = p2->next;
		}

			
	}
	while (p1!= NULL )   
	{
		{
			r->next = Attach(s, p1->coef, p1->expon);
			r = r->next;
			p1 = p1->next;
		}
	}

	while (p2!= NULL)
	{
		{
			r->next = Attach(s, p2->coef, p2->expon);
			r = r->next;
			p2 = p2->next;
		}
	}
	return head;
}
Polynomial * Attach(Polynomial *s, int coef, int expon)    //新增节点函数
{
	s = (Polynomial*)malloc(sizeof(Polynomial));
	s->coef = coef;
	s->expon = expon;
	s->next = NULL;
	return s;
}
void Print(Polynomial *head)  //打印多项式
{
	Polynomial *s = head->next;

	while (s!=NULL)
	{
		printf("%d %d ", s->coef, s->expon);
		s = s->next;	
	}
	system("pause");
}
