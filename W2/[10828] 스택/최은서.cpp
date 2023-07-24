//언어 C++, 메모리 1156KB, 시간 4ms
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
using namespace std;

int myStack[10000];
int cur = 0;

void push(int num)
{
	myStack[cur++] = num;
}
int pop()
{
	if (cur <= 0) return -1;
	return myStack[--cur];
}
int top()
{
	if (cur <= 0) return -1;
	return myStack[cur-1];
}
int size()
{
	return cur;
}
int empty()
{
	if (cur == 0) return 1;
	else return 0;
}


int main(void)
{
	int n;
	int number;
	char option[6];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", option);
		fgetc(stdin); //버퍼 지우기
		if (strcmp(option, "push") == 0)
		{
			scanf("%d", &number);
			fgetc(stdin); //버퍼 지우기
			push(number);
		}
		else if (strcmp(option, "pop") == 0)
		{
			printf("%d\n", pop());
		}
		else if (strcmp(option, "size") == 0)
		{
			printf("%d\n", size());
		}
		else if (strcmp(option, "empty") == 0)
		{
			printf("%d\n", empty());
		}
		else if (strcmp(option, "top") == 0)
		{
			printf("%d\n", top());
		}
	}
}
