//언어 cpp 메모리 1112KB, 시간 1636ms
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

bool isused1[40];
bool isused2[40];
bool isused3[40];
int cnt = 0;
int n;

void func(int cur)
{
	if (cur == n)
	{
		cnt += 1;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (isused1[i] || isused2[i + cur] || isused3[cur - i + n - 1])
		{
			continue;
		}
		isused1[i] = 1;
		isused2[i + cur] = 1;
		isused3[cur - i + n - 1] = 1;
		func(cur + 1);
		isused1[i] = 0;
		isused2[i + cur] = 0;
		isused3[cur - i + n - 1] = 0;
	}
}

int main(void)
{
	scanf("%d", &n);
	func(0);
	printf("%d", cnt);
}
