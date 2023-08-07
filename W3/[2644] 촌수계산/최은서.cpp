// 언어 c++ 메모리 1116KB, 시간 0ms
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	scanf("%d", &n); //사람 수

	int graph[100][100] = { 0, };

	int* visited;
	visited = (int*)malloc((n + 1) * sizeof(int)); //방문처리 배열
	memset(visited, 0, sizeof(int) * (n + 1));

	int a, b;
	scanf("%d %d", &a, &b);
	int m; // 관계 개수
	scanf("%d", &m);
	int x, y;
	while (m--)
	{
		scanf("%d %d", &x, &y);
		graph[x][y] = 1;
		graph[y][x] = 1; //1촌 연결처리
	}
	
	int stack[10000][2] = { 0, };
	int pos = -1; 
	stack[++pos][0] = a; //스택에 넣고
	stack[pos][1] = 0;
	visited[a] = 1; //방문처리
	int flag = 0;
	int res;
	int X;

	while (pos != -1)
	{
		X = stack[pos][0];
		res = stack[pos--][1];
		if (X == b)
		{
			flag = 1;
			break;
		}
		for (int i = 0; i <= n; i++)
		{
			if (graph[X][i] == 1 && visited[i] == 0)
			{
				stack[++pos][0] = i;
				stack[pos][1] = res + 1;
				visited[i] = 1;
			}
		}
	}
	if (!flag) printf("-1");
	else printf("%d", res);
	//printf("%d", flag);

}
