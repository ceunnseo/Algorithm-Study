### 언어 python3, 메모리 154472KB, 시간 1156ms

# 수의 개수 N (1 ≤ N ≤ 1,000,000)
# 둘째 줄부터 N개의 줄에는 수(1,000,000보다 작거나 같은 정수, 중복되지 않음)
 
import sys

n = int(input())

numbers = [int(sys.stdin.readline()) for i in range(n)]
numbers.sort()

answer = '\n'.join(map(str, numbers))
print(answer)

# 선택정렬: array에서 가장 작은 값을 찾아 맨 앞의 값과 교체
def selection_sort(numbers):
    for i in range(len(numbers)):
        pick = i
        for j in range(i+1, len(numbers)):
            if numbers[pick]>numbers[j]: pick = j
        numbers[pick],  numbers[i] = numbers[i], numbers[pick]

# 삽입정렬: 두 번째 값부터 시작해 앞(왼쪽) 값들과 비교하여 삽입 위치 지정
def insertion_sort(numbers):
    for i in range(1, len(numbers)):
        for j in range(i, 0, -1):
            if numbers[i-1] > numbers[i]:
                numbers[i-1], numbers[i] = numbers[i], arr[i-1]

# 버블정렬: 맨 처음 값부터 시작해 그 다음 값과 비교해서 앞의 값이 뒤의 값보다 클 경우 자리를 바꿈
def bubble_sort(numbers):
    for i in range(len(numbers)-1, 0,-1):
        for j in range(i):
            if numbers[j] > numbers[j+1]:
                numbers[j], numbers[j+1] = numbers[j+1], numbers[j]
