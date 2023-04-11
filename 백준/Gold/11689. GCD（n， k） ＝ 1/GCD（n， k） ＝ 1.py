n = int(input())  # 10**12, 1,000,000,000,000, 1조

if n == 1:
    print(1)
    exit()

num = n
contains = []  # 소인수
# 소인수 찾기
for i in range(2, int(n ** (0.5)) + 1):  # 100만
    if num % i == 0:
        contains.append(i)
        while num % i == 0:
            num //= i

if contains == []:  # 소수
    print(n - 1)
    exit()

contains.append(num)

ans = n
for div in contains:
    if div == 1:
        continue
    ans = ans * (div - 1) // div


print(ans)