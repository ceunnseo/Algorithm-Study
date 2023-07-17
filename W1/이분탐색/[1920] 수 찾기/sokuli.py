### 언어 python3, 메모리 50412KB, 시간 192ms

n = int(input())
A = set(map(int, input().split(' ')))

m = int(input())
numbers = list(map(int, input().split(' ')))

for number in numbers:
    print(1) if number in A else print(0)

