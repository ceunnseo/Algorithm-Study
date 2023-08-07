//언어 cpp, 메모리 1112KB, 시간 0ms
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
int main(void)
{
	int n, m;
	int** graph; //연결 여부를 체크할 2차원 배열
	int* arr; 
	int stack[MAX]; //스택
	int pos = -1;
	int node1, node2; // 연결된 컴퓨터의 번호를 입력받는 변수
	int cnt = 0; //1번 컴퓨터와 연결된 컴퓨터 개수
	int* visited; //방문 여부 배열
	int top; //스택 최상단 노드
	scanf("%d", &n); //컴퓨터의 수
	scanf("%d", &m); //연결 수
	graph = (int**)malloc((n + 1) * sizeof(int*));
	arr = (int*)malloc((n + 1) * (n + 1) * sizeof(int));
	visited = (int*)malloc((n + 1) * sizeof(int));
	memset(arr, 0, (n + 1) * (n + 1) * sizeof(int));
	memset(visited, 0, (n + 1) * sizeof(int));
	for (int i = 0; i <= n; i++)
	{
		graph[i] = &arr[i * (n + 1)];
	} //2차원 배열 생성

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &node1, &node2);
		graph[node1][node2] = 1;
		graph[node2][node1] = 1; //연결된 node1-node2는 배열에서 1로 표현, 연결 안 되어있으면 0
	}

	pos = pos + 1;
	stack[pos] = 1; //스택에 1번 컴퓨터 push하고
	visited[1] = 1; //방문처리하고 
	while (pos != -1) //스택이 빌 때 까지 판단(1과 연결된 컴퓨터들을 stack에 push)
	{
		top = stack[pos];
		pos = pos - 1; //최상단노드를 꺼내고 
		for (int j = 1; j <= n; j++) //1번부터 n번까지 컴퓨터를 확인해가면서 
		{
			if (graph[top][j] == 1 && visited[j] == 0) //연결된 컴퓨터인지 & 이전에 스택에 넣은 적 있는지 판단 후
      {
				pos = pos + 1;
				stack[pos] = j;
				visited[j] = 1; ///방문한 적 없으면 스택에 push & 방문처리
				cnt += 1; //연결된 컴퓨터 개수 1 증가
			}
		}
	}
	printf("%d\n", cnt);

	free(arr);
	free(graph);
}
