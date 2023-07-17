### 언어 python3, 메모리 312640KB, 시간 1148ms

# (1 ≤ N, M ≤ 1,000,000)
# 배열에 들어있는 수는 절댓값이 109보다 작거나 같은 정수

n, m = map(int, input().split())
n_list = list(map(int, input().split()))
m_list = list(map(int, input().split()))

total = n_list + m_list
total = sorted(total)

answer = ' '.join(map(str, total))
print(answer)