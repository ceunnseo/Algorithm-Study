# 1s 128MB (solved 	31256KB 44ms)

# Fn = Fn-1 + Fn-2 (n ≥ 2)
# n이 주어졌을 때, n번째 피보나치 수를 구하는 프로그램

# INPUT
# 첫째 줄에 n이 주어진다. n은 90보다 작거나 같은 자연수이다.

# OUTPUT
# 첫째 줄에 n번째 피보나치 수를 출력한다.

n = int(input())

d = [0]*(n+1)
d[1] = 1 # 첫번째 수 정의

for i in range(2, n+1):
    d[i]=d[i-1]+d[i-2]

print(d[n])
