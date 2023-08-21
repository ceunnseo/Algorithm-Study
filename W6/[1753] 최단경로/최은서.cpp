//언어 cpp, 메모리 14872KB, 시간 172ms
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#define MAX 20001
#define INF 1000000
using namespace std;
priority_queue<pair<int, int>> pq; //우선순위큐 {시작번호, 가중치}
vector <pair<int, int>> nodes[MAX]; //{연결노드, 가중치}
int dist[MAX]; //최단거리테이블
int main(void)
{
	int V, E; //정점 개수, 간선 개수
	int k; //시작 정점의 번호
	int u, v, w; // u->v (가중치 w)
	scanf("%d %d", &V, &E); //정점 개수 V, 간선 개수 E
	scanf("%d", &k);
	for (int i = 1; i <= V; i++)
	{
		dist[i] = INF;
	}
	pq.push({ 0, k }); //시작노드 우선순위큐에 삽입
	dist[k] = 0;
	while (E--)
	{
		scanf("%d %d %d", &u, &v, &w);
		nodes[u].push_back({ w, v });
	}
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dist[cur] < cost) continue; //이미 최단거리 정보 있으면
		for (int i = 0; i < nodes[cur].size(); i++)
		{
			int next = nodes[cur][i].second;
			int via_cost = cost + nodes[cur][i].first;
			if (via_cost <= dist[next])
			{
				dist[next] = via_cost;
				pq.push({ -via_cost, next });
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == INF)
		{
			printf("INF\n");
		}
		else
		{
			printf("%d\n", dist[i]);
		}
	}

}
