n = int(input())  # 10만
nums = list(map(int, input().split()))
scores = [0] * n
exists = [-1] * (1000001)  # idx가 들어감
for i in range(n):
    exists[nums[i]] = i

for i in range(n): 
    num = nums[i]
    for x in range(num * 2, 1000001, num):
        if exists[x] != -1:
            scores[exists[x]] -= 1
            scores[i] += 1
for score in scores:
    print(score, end=" ")
