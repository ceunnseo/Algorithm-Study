### 언어 python3, 메모리 42340KB, 시간 120ms

import sys

n, m = map(int, sys.stdin.readline().split())
numbers=[]
for i in range(n):
    number = int(sys.stdin.readline())
    numbers.append(number)
numbers.sort()

left, right = 0, 0
answer = int(2e9) # M 이상이므로 (0 ≤ M ≤ 2,000,000,000)

while left <=right and right < n:
    if numbers[right]-numbers[left] < m:
        right +=1
    
    else:
        answer = min(answer, numbers[right]-numbers[left])
        left +=1

print(answer)

