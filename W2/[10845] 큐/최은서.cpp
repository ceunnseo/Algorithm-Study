// 언어 c++, 메모리 1156KB, 시간 4ms
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
int q[10000];
int head = 0, tail = 0;

void push(int x)
{
	q[tail++] = x;
}


int size()
{
	return tail - head;
}
int empty()
{
	if (size() == 0) return 1;
	else return 0;
}
int pop()
{
	if (empty()) return -1;
	return q[head++];
}
int front()
{
	if (empty()) return -1;
	return q[head];
}
int back()
{
	if (empty()) return -1;
	return q[tail - 1];
}


int main(void)
{

	char command[6];
	int n;
	int data;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", command);
		if (strcmp(command, "push") == 0)
		{
			scanf("%d", &data);
			push(data);
		}
		else if (strcmp(command, "pop") == 0)
		{
			printf("%d\n", pop());
		}
		else if (strcmp(command, "size") == 0)
		{
			printf("%d\n", size());
		}
		else if (strcmp(command, "empty") == 0)
		{
			printf("%d\n", empty());
		}
		else if (strcmp(command, "front") == 0)
		{
			printf("%d\n", front());
		}
		else if (strcmp(command, "back") == 0)
		{
			printf("%d\n", back());
		}
	}
}
