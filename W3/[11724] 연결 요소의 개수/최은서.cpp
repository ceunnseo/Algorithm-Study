//언어 cpp, 메모리 5028KB, 시간 156ms
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1001
int main(void)
{
	int n, m;
	int *visited;
	int** graph;
	int* arr;
	int stack[MAX];
	int pos = -1;
	int node1, node2;
	int cnt = 0;
	int top;
	int flag = 0;
	scanf("%d %d", &n, &m);
	visited = (int*)malloc((n + 1) * sizeof(int));
	memset(visited, 0, (n + 1) * sizeof(int));
	graph = (int**)malloc((n + 1) * sizeof(int*));
	arr = (int*)malloc((n+1) * (n + 1) * sizeof(int));
	memset(arr, 0, (n+1)* (n + 1) * sizeof(int));
	for (int i = 0; i <= n; i++)
	{
		graph[i] = &arr[i*(n+1)];
	}

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &node1, &node2);
		graph[node1][node2] = 1;
		graph[node2][node1] = 1; //노드 연결 표현 (1 : node1-node2가 연결됨)
	}


	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == 0) //방문한 적 없으면 -> 스택에 push
		{
			pos += 1;
			stack[pos] = i;
			visited[i] = 1;
		}
		while (pos != -1) //스택이 빌 때 까지
		{
			flag = 1;
			top = stack[pos];
			pos = pos - 1;
			for (int j = 1; j <= n; j++)
			{
				if (graph[top][j] == 1 && visited[j] == 0) //연결되어있고 방문한 적 없는 경우 -> 스택에 push
				{
					pos = pos + 1;
					stack[pos] = j;
					visited[j] = 1;
				}
			}
		}
		if (flag) //스택에 쌓아뒀다가 빌 때까지 탐색한 적 있으면 -> 카운트 1 증가
		{
			//printf("i : %d\n", i);
			cnt += 1;
			flag = 0;
		}
	}
	printf("%d", cnt);

}
