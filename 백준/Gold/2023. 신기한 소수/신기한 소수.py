n = int(input())
# 99999999 <- 9999만


def check(num):
    if num <= 1:
        return 0
    elif num == 2:
        return 1

    for i in range(2, int(num ** (0.5)) + 1):
        if num % i == 0:
            return 0
    return 1


def f(length):
    if length == 1:
        return ["2", "3", "5", "7"]

    result = []
    front_nums = f(length - 1)
    for front in front_nums:
        for i in range(10):
            si = str(i)
            snum = front + si
            if check(int(snum)):
                result.append(snum)

    return result


ans = f(n)
for a in ans:
    print(a)