//언어 c++, 메모리 1112KB, 시간 0ms
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main(void)
{
	int n; //피연산자 개수
	scanf("%d", &n);
	int numbers[26] = { 0, };
	char command[101];
	double a = 0;
	double b = 0;
	double res = 0;
	scanf("%s", command);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &numbers[i]);
	}

	double stack[100] = { 0, };
	int pos = 0;
	int idx = 0;

	for (int i = 0; command[i] != NULL ; i++)
	{
		if ('A' <= command[i] && command[i] <= 'Z')
		{
			stack[pos++] = numbers[command[i]-'A'];
		}
		else
		{
			b = stack[--pos];
			a = stack[--pos];
			if (command[i] == '+') res = a + b;
			else if (command[i] == '-') res = a - b;
			else if (command[i] == '*') res = a * b;
			else if (command[i] == '/') res = a / b;
			stack[pos++] = res;
		}
	}
	printf("%.2f", stack[0]);
}
