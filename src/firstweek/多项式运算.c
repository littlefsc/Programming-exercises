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
	printf("���������ʽ�ĳ��ȣ�\n");
	int n,coef,expon;  
	scanf("%d", &n);
	while (n>0)
	{
		printf("���������ʽ��ϵ���ʹ���\n");
		scanf("%d%d", &coef, &expon);
		r->next= Attach(p, coef, expon);
		r = r->next;                 //β�巨��������rʼ��ָ���β�ڵ�
		n--;
	}
	return head;
}

Polynomial * Add(Polynomial *P1, Polynomial *P2)
{
	Polynomial *head,*p1,*p2,*s,*r;    
	head = (Polynomial*)malloc(sizeof(Polynomial));   //����һ������������������������ʽ��Ӻ�Ķ���ʽ,headΪ�����ͷ�ڵ�
	head->next = NULL;
	r = head;                 
	s = NULL;
	p1 = P1->next;
	p2 = P2->next;
	
	while (p1!= NULL&&p2!= NULL)  
	{
		if(p1->expon=p2->expon)         //���������ϵ�����
		{
			r->next = Attach(s, (p1->coef + p2->coef), p1->expon);  
			r = r->next;
			p1 = p1->next;
			p2 = p2->next;
		}
		else if (p1->expon > p2->expon)  //��������Ƚ������� 
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
Polynomial * Attach(Polynomial *s, int coef, int expon)    //�����ڵ㺯��
{
	s = (Polynomial*)malloc(sizeof(Polynomial));
	s->coef = coef;
	s->expon = expon;
	s->next = NULL;
	return s;
}
void Print(Polynomial *head)  //��ӡ����ʽ
{
	Polynomial *s = head->next;

	while (s!=NULL)
	{
		printf("%d %d ", s->coef, s->expon);
		s = s->next;	
	}
	system("pause");
}
