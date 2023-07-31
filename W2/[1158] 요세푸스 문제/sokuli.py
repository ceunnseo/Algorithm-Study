### 언어 python3, 메모리 KB, 시간 ms  -> 시간초과

# 요세푸스 순열
import sys
n, k = map(int, sys.stdin.readline().strip().split())

people = [i+1 for i in range(n)]

print('<', end='')
while True:
    # 앞의 k-1 개를 뒤로 옮김
    for i in range(k-1): 
        people.append(people[0])
        people.pop(0)
    
    # k번째 출력
    if len(people) == 1:
        print(people[0], end='>')
        break
    else:
        print(people[0], end=', ')
    people.pop(0)
