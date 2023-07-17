### 언어 python3, 시간초과

n, s = map(int, input().split())
numbers = list(map(int, input().split()))

sum = 0
for num in range(n):
    for i in range(n-num):
        init = numbers[i]
        for j in range(1, num+1):
            init += numbers[i+j]

        if init >= s:
            sum = init
            break;

    if sum != 0:
        print(num+1)
        break;

if sum == 0 :
    print(0)
