n = int(input())  # n
blocks = []  # idx, s, h, w

# 높이만 유일하게 같을 수도 있음
# 무게랑 면적은 오름차순 (아래가 제일 넓고 무겁)
for i in range(n):
    s, h, w = map(int, input().split())
    blocks.append((i, s, h, w))

blocks.sort(key=lambda x: -x[1])  # 면적 내림차순, 무게로 승부


dp = [0] * n
dp[0] = blocks[0][2]

for i in range(1, n):
    # i 보다 무거운놈 찾기
    dp[i] = blocks[i][2]
    for j in range(i - 1, -1, -1):
        if blocks[j][3] > blocks[i][3]:
            # 걔랑 max 하기
            if dp[i] < dp[j] + blocks[i][2]:
                dp[i] = dp[j] + blocks[i][2]

# print(dp)
ans = []
val = max(dp)
for i in range(n - 1, -1, -1):
    if val == dp[i]:
        ans.append(blocks[i][0] + 1)
        val -= blocks[i][2]


print(len(ans))
for i in range(len(ans)):
    print(ans[i])
