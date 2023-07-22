// 언어 c++, 메모리 1228KB, 시간 144ms
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;


int main(void)
{
	queue<int> q;
	int n, k;
	int idx = 0;
	int number;
	int res[5000];
	int i = 0;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}

	while (q.size() != 0)
	{
		idx += 1;
		number = q.front();
		q.pop();
		if (idx % k == 0)
		{
			res[i++] = number;
		}
		else
		{
			q.push(number);
		}
	}
	printf("<");
	for (int i = 0; i < n-1; i++)
	{
		printf("%d, ", res[i]);
	}
	printf("%d>", res[n - 1]);
}
