import sys

sys.setrecursionlimit(10**8)  # pypy 제출시 삭제!
input = lambda: sys.stdin.readline().rstrip()
# in_range = lambda y,x: 0<=y<n and 0<=x<m

n, l = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
ans = 0

for i in range(n):
    success = 1
    same_streak = 1
    j = 1
    while j < n:  # go right
        if board[i][j - 1] == board[i][j]:
            same_streak += 1
        elif board[i][j - 1] + 1 == board[i][j]:  # 1 높아짐
            if same_streak >= l:  # 여태 평평해서 경사로 놓을 수 있음
                same_streak = 1
            else:  # 못 놓음
                success = 0
                break
        elif board[i][j - 1] - 1 == board[i][j]:  # 1 낮아짐
            cnt = 1
            for k in range(1, l):
                if j + k < n and board[i][j] == board[i][j + k]:
                    cnt += 1
            if cnt == l:  # 경사로 설치 가능
                j += l - 1
                same_streak = 0
            else:
                success = 0
                break

        else:  # 2 이상 차이나서 무조건 실패
            success = 0
            break
        j += 1
    ans += success

for j in range(n):
    success = 1
    same_streak = 1
    i = 1
    while i < n:  # go down
        if board[i - 1][j] == board[i][j]:
            same_streak += 1
        elif board[i - 1][j] + 1 == board[i][j]:  # 1 높아짐
            if same_streak >= l:  # 여태 평평해서 경사로 놓을 수 있음
                same_streak = 1
            else:  # 못 놓음
                success = 0
                break
        elif board[i - 1][j] - 1 == board[i][j]:  # 1 낮아짐
            cnt = 1
            for k in range(1, l):
                if i + k < n and board[i][j] == board[i + k][j]:
                    cnt += 1
            if cnt == l:  # 경사로 설치 가능
                i += l - 1
                same_streak = 0
            else:
                success = 0
                break

        else:  # 2 이상 차이나서 무조건 실패
            success = 0
            break
        i += 1
    ans += success

print(ans)
