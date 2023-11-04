n = int(input())
s = input()
board = [[0 for _ in range(n)] for _ in range(n)]
idx = 0
for i in range(n):
    for j in range(i, n):
        c = s[idx]
        if c == "+":
            board[i][j] = 1
        elif c == "-":
            board[i][j] = -1
        idx += 1

# 부호와 합이 일치하는지 확인하는 함수
def ck(idx):
    hap = 0
    for i in range(idx, -1, -1):
        hap += seq[i]
        if hap == 0 and board[i][idx] != 0:
            return False
        elif hap < 0 and board[i][idx] >= 0:
            return False
        elif hap > 0 and board[i][idx] <= 0:
            return False
    return True


def solve(idx):
    if idx == n:
        return True

    if board[idx][idx] == 0:
        seq[idx] = 0
        return solve(idx + 1)
    for i in range(1, 11):
        seq[idx] = board[idx][idx] * i # 음수 양수 저절로 곱해짐
        if ck(idx) and solve(idx + 1):
            return True
    return False


seq = [0] * n
solve(0)
for num in seq:
    print(num, end=" ")