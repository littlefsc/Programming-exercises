#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include <stdbool.h>
#define MaxSize 10

typedef struct {
	int front;
	int rear;
	int data[MaxSize];
}Queue;    //顺序队列结构体

Queue * InitQueue(Queue * Q);
bool QueueIsEmpty(Queue * Q);
Queue * InQueue(Queue * Q, int x);
Queue * OutQueue(Queue * Q, int x);
int main() {
	return 0;
}

Queue * InitQueue(Queue * Q) {          //初始化队列
	Q->front = Q->rear = 0;
	return Q;
}
bool QueueIsEmpty(Queue * Q) {         //判断是否队空 
	if (Q->front == Q->rear)
		return true;
	return false;
}
Queue * InQueue(Queue * Q, int x) {     //入队函数
	if ((Q->rear + 1) % MaxSize == Q->front)
		printf("队列已满，入队失败！");      //队满则无法入队
	else
	{
		Q->data[Q->rear]= x;
		Q->rear=(Q->rear+1)%MaxSize;     //队尾指针加一取余
	}
	return Q;
}
Queue * OutQueue(Queue * Q, int x)  //出队函数
{
	if (QueueIsEmpty(Q))
		printf("队列已空，出队失败！");  //队空则无法出队
	else
	{
		x = Q->data[Q->front];
		Q->front = (Q->front + 1) % MaxSize;//队头指针加一取余
	}
	return Q;
}