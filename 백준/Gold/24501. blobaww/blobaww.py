import sys

#sys.setrecursionlimit(10 ** 8)  # pypy 제출시 삭제!
input = lambda: sys.stdin.readline().rstrip()
# in_range = lambda y,x: 0<=y<n and 0<=x<m

MOD = (10 ** 9) + 7


n, m = map(int, input().split())
board = [list(input()) for _ in range(n)]

e_sum = [[0 for _ in range(m + 1)] for _ in range(n)]
for j in range(m):
    add = 1 if board[0][j] == "E" else 0
    e_sum[0][j] = add + e_sum[0][j - 1]
for i in range(1, n):
    for j in range(m):
        add = 1 if board[i][j] == "E" else 0
        e_sum[i][j] = add + e_sum[i][j - 1]
    for j in range(m):
        e_sum[i][j] += e_sum[i - 1][j]


m_sum = [[0 for _ in range(m + 1)] for _ in range(n)]
for j in reversed(range(m)):
    add = 1 if board[n - 1][j] == "M" else 0
    m_sum[n - 1][j] = add + m_sum[n - 1][j + 1]
for i in reversed(range(n - 1)):
    for j in reversed(range(m)):
        add = 1 if board[i][j] == "M" else 0
        m_sum[i][j] = add + m_sum[i][j + 1]
    for j in reversed(range(m)):
        m_sum[i][j] += m_sum[i + 1][j]


ans = 0
for i in range(n):
    for j in range(m):
        if board[i][j] == "S":
            ans += e_sum[i][j] * m_sum[i][j]

print(ans % MOD)
