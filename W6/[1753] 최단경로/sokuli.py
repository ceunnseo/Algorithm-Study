# python 	68356KB 676ms

import sys
import heapq

input = sys.stdin.readline # input 함수 새로 정의
INF = int(1e9) # 무한대 정의

def dijkstra(start):
  q = [] # 우선순위 큐 정의
  
  heapq.heappush(q, (0, start))
  distance[start] = 0 # 시작 정점의 거리를 0으로 정의

  while q:
    dist, now = heapq.heappop(q) # 시작점 선택

    if distance[now] < dist: # 현재 노드 거리 비교
      continue
  
    for i in graph[now]: # 이웃 노드 확인
      cost = dist + i[1] 
      if cost < distance[i[0]]:
        distance[i[0]] = cost
        heapq.heappush(q, (cost, i[0]))

V, E = map(int, input().split())

snode = int(input()) # 시작 정점

graph = [[] for _ in range(V+1)]
distance = [INF] * (V+1) # 시작 정점에서 각 정점까지의 거리를 무한대로 설정

for _ in range(E):
  u, v, w = map(int, input().split())
  graph[u].append((v, w)) # u에서 v로 가는 가중치 w인 간선
    
dijkstra(snode)
for i in range(1, V+1):
  if distance[i] == INF:
    print("INF")
  else:
    print(distance[i])
