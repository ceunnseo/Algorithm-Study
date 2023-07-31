// 언어 c, 메모리 1388KB, 시간 4ms
// 23.7.27 변경사항 큐를 원형큐로 & 구조체 타입으로 구현
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100000
typedef struct queue
{
	int front;
	int rear;
	int arr[SIZE];
};

void queueInit(struct queue* q)
{
	q->front = 0;
	q->rear = 0;
}

void push(struct queue* q, int x)
{
	q->rear = (q->rear + 1) % SIZE;
	q->arr[q->rear] = x;
}

int pop(struct queue* q)
{
	if (q->front == q->rear) return -1;
	q->front = (q->front + 1) % SIZE;
	return q->arr[q->front];
}

int size(struct queue* q)
{
	return (q->rear - q->front);
}

int empty(struct queue* q)
{
	if (q->front == q->rear) return 1;
	return 0;
}

int front(struct queue* q)
{
	if (q->front == q->rear) return -1;
	return q->arr[q->front+1];
}
int back(struct queue* q)
{
	if (q->front == q->rear) return -1;
	return q->arr[q->rear];
}


int main(void)
{
	struct queue myqueue;
	queueInit(&myqueue);


	int n;
	int num;
	char command[6];

	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%s", command);
		if (strcmp(command, "push") == 0)
		{
			scanf("%d", &num);
			push(&myqueue, num);
		}
		else if (strcmp(command, "pop") == 0)
		{
			printf("%d\n", pop(&myqueue));
		}
		else if (strcmp(command, "size") == 0)
		{
			printf("%d\n", size(&myqueue));
		}
		else if (strcmp(command, "empty") == 0)
		{
			printf("%d\n", empty(&myqueue));
		}
		else if (strcmp(command, "front") == 0)
		{
			printf("%d\n", front(&myqueue));
		}
		else if (strcmp(command, "back") == 0)
		{
			printf("%d\n", back(&myqueue));
		}
	}

}
