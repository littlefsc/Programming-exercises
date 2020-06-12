/*将一系列给定数字插入一个初始为空的小顶堆。
然后对任意给定的下标i,打印从i到根节点的路径
*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>


#define MAXN 1001
#define MINH -10001


int H[MAXN] ,size;


void create()
{
	size = 0;
	H[0] = MINH;
}
void insert(int num)
{
	if (size < MAXN)
	{
		int i = ++size;
		for (; H[i / 2]>num; i /= 2)
		{
			H[i] = H[i / 2];
		}
		H[i] = num;
	}	
}
void main()
{
	int n, m, x, i, j;
	scanf("%d%d\n", &n,&m);
	create();
	for (i = 0; i < n; i++)
	{
		scanf("%d", &x);
		insert(x);
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d", &j);
		printf("%d", H[j]);
		while (j > 1)
		{
			j /= 2;
			printf(" %d", H[j]);
		}
		printf("\n");
	}
	system("pause");

}