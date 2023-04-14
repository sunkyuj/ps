n = int(input())
cnt = -1


def f(length, s):
    global cnt
    if len(s) == length:
        cnt += 1
        # print(s, cnt)  # test
        if cnt == n:
            print(s)
            exit()
        return
    for i in range(int(s[-1])):
        f(length, s + str(i))


for length in range(1, 11):
    for i in range(length - 1, 10):
        f(length, str(i))

print(-1)