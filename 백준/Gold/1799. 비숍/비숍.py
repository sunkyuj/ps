import sys

sys.setrecursionlimit(10 ** 8)
input = lambda: sys.stdin.readline().rstrip()

in_range = lambda y, x: 0 <= y < n and 0 <= x < n

n = int(input())
board = [[] for _ in range(n)]
for i in range(n):
    board[i] = list(map(int, input().split()))

rd = {}  # 우하향(right down) 대각선
# 중앙 기준으로 쁠마
# (y,x) -> rd[x-y], 왼쪽 아래가 -(n-1), 오른쪽 위가 (n-1)
for i in range(-n + 1, n):
    rd[i] = 0


ans = 0

def upper_bound(diag):  # 현재 대각선(우상향) 위치에서부터 끝 대각선까지 뽑힐 가능성이 있는 애들의 갯수 반환
    able_rus = 0  # 가능한 우상향 대각선들의 개수, 실제 가능하다기보단 단순히 가능할수도 있는 애들
    for d in range(diag, 2 * n - 1):
        for y in range(d + 1):
            x = d - y
            if in_range(y, x) and board[y][x] and rd[x - y] == 0:
                able_rus += 1
                break
    return able_rus


def f(diag, cnt):
    global ans
    if diag == 2 * n:
        ans = max(ans, cnt)
        return

    ub = upper_bound(diag)  # 상한, 이번 대각선부터 끝까지 갔을 때 최대로 더 가질 수 있는 값
    if ub + cnt <= ans:
        return

    for y in range(diag + 1):
        x = diag - y
        if in_range(y, x) and board[y][x] and rd[x - y] == 0:
            rd[x - y] = 1
            f(diag + 1, cnt + 1)
            rd[x - y] = 0

    f(diag + 1, cnt)  # 이번 대각선에서 선택 x


f(0, 0)
print(ans)

"""
10
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
"""
