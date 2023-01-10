n = int(input())

arr = list(map(int, input().split()))
op = list(map(int, input().split()))  # (+ - * //)

max_ans = -1000000000
min_ans = 1000000000


def f(i, num):
    global max_ans, min_ans
    if i == n:
        max_ans = max(num, max_ans)
        min_ans = min(num, min_ans)
        return

    if op[0] > 0:
        op[0] -= 1
        f(i + 1, num + arr[i])
        op[0] += 1

    if op[1] > 0:
        op[1] -= 1
        f(i + 1, num - arr[i])
        op[1] += 1

    if op[2] > 0:
        op[2] -= 1
        f(i + 1, num * arr[i])
        op[2] += 1

    if op[3] > 0:
        if num * arr[i] < 0:
            num *= -1
            res = -(num // arr[i])
        else:
            res = num // arr[i]
        op[3] -= 1
        f(i + 1, res)
        op[3] += 1


f(1, arr[0])
print(max_ans)
print(min_ans)
# 1 3 0 0 2
# 0 0 3 1 2
