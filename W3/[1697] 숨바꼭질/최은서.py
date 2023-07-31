# 언어 python 메모리 35240KB, 시간 132ms
from collections import deque

MAX = 10 ** 5
dist = [0] * (MAX+1)
n, k = map(int, input().split())

queue = deque()
queue.append(n)

while queue:
    x = queue.popleft()
    if x == k: #목적지에 왓으면
        print(dist[x])
        break
    for nx in (x-1, x+1, x*2):
        if 0<=nx<=MAX and dist[nx] == 0: 
            dist[nx] = dist[x] + 1
            queue.append(nx)
