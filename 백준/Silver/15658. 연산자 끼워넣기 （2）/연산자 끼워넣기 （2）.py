n = int(input())
arr = list(map(int, input().split()))
ops = list(map(int, input().split()))

max_ans = -1000000001
min_ans = 1000000001


def f(idx, res):
    global min_ans, max_ans
    if idx == n:
        min_ans = min(min_ans, res)
        max_ans = max(max_ans, res)
        return

    if ops[0]:
        ops[0] -= 1
        f(idx + 1, res + arr[idx])
        ops[0] += 1

    if ops[1]:
        ops[1] -= 1
        f(idx + 1, res - arr[idx])
        ops[1] += 1

    if ops[2]:
        ops[2] -= 1
        f(idx + 1, res * arr[idx])
        ops[2] += 1

    if ops[3]:
        ops[3] -= 1
        if res >= 0:
            f(idx + 1, res // arr[idx])
        else:
            f(idx + 1, -((-res) // arr[idx]))
        ops[3] += 1


f(1, arr[0])
print(max_ans)
print(min_ans)
