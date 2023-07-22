//언어 c++, 메모리 1112KB, 시간 0ms
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main(void)
{
	char command[100000] = { 0, };
	scanf("%s", command);
	int n = strlen(command);
	
	char stack[100000];
	int pos = 0;

	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		if (command[i] == '(')
		{
			stack[pos++] = command[i]; //스택에 추가
		}
		else //닫는 괄호
		{
			if (command[i - 1] == '(') //레이저
			{
				pos--;
				cnt += pos;
			}
			else //쇠막대기
			{
				pos--;
				cnt += 1;
			}
		}
	}
	printf("%d", cnt);
}
