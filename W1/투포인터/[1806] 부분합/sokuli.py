### 언어 python3, 메모리 42340KB, 시간 120ms

n, s = map(int, input().split())
numbers = list(map(int, input().split()))

sum = numbers[0]
left, right = 0, 0
answer = 100001 # 답이 될 수 없느 값

while True:
    if sum < s:
        right += 1
        if right == n: break
        sum += numbers[right]
    else:
        sum -= numbers[left]
        answer = min(answer, right-left+1)
        left += 1

print(answer if answer != 100001 else 0)


# sum = 0
# for num in range(n):
#     for i in range(n-num):
#         init = numbers[i]
#         for j in range(1, num+1):
#             init += numbers[i+j]

#         if init >= s:
#             sum = init
#             break;

#     if sum != 0:
#         print(num+1)
#         break;

# if sum == 0 :
#     print(0)
