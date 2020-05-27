#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include <stdbool.h>
#define MaxSize 10

typedef struct {
	int front;
	int rear;
	int data[MaxSize];
}Queue;    //˳����нṹ��

Queue * InitQueue(Queue * Q);
bool QueueIsEmpty(Queue * Q);
Queue * InQueue(Queue * Q, int x);
Queue * OutQueue(Queue * Q, int x);
int main() {
	return 0;
}

Queue * InitQueue(Queue * Q) {          //��ʼ������
	Q->front = Q->rear = 0;
	return Q;
}
bool QueueIsEmpty(Queue * Q) {         //�ж��Ƿ�ӿ� 
	if (Q->front == Q->rear)
		return true;
	return false;
}
Queue * InQueue(Queue * Q, int x) {     //��Ӻ���
	if ((Q->rear + 1) % MaxSize == Q->front)
		printf("�������������ʧ�ܣ�");      //�������޷����
	else
	{
		Q->data[Q->rear]= x;
		Q->rear=(Q->rear+1)%MaxSize;     //��βָ���һȡ��
	}
	return Q;
}
Queue * OutQueue(Queue * Q, int x)  //���Ӻ���
{
	if (QueueIsEmpty(Q))
		printf("�����ѿգ�����ʧ�ܣ�");  //�ӿ����޷�����
	else
	{
		x = Q->data[Q->front];
		Q->front = (Q->front + 1) % MaxSize;//��ͷָ���һȡ��
	}
	return Q;
}