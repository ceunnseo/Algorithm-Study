#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000002
int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);
	int queue[MAX][2];
	int visited[MAX] = { 0, };
	int front = 0;
	int rear = 0;
	int time = 0;
	rear = (rear + 1) % MAX;
	queue[rear][0] = n;
	queue[rear][1] = 0;
	visited[n] = 1; //방문처리
	
	while (front != rear)
	{
		front = (front + 1) % MAX;
		n = queue[front][0];
		time = queue[front][1];
		if (n == k) break;

		if (n-1 >= 0 && n-1 < MAX && visited[n - 1] == 0)
		{
			rear = (rear + 1) % MAX;
			queue[rear][0] = n - 1;
			queue[rear][1] = time + 1;
			visited[n - 1] = 1;
		}
		if (n+1 >= 0 && n+1 < MAX && visited[n + 1] == 0)
		{
			rear = (rear + 1) % MAX;
			queue[rear][0] = n + 1;
			queue[rear][1] = time + 1;
			visited[n + 1] = 1;
		}
		if (2*n >= 0 && 2*n < MAX && visited[2 * n] == 0)
		{
			rear = (rear + 1) % MAX;
			queue[rear][0] = 2 * n;
			queue[rear][1] = time + 1;
			visited[2 * n] = 1;
		}
	}
	printf("%d", time);
	
}
