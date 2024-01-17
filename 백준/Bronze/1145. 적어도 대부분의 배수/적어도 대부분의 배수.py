arr = list(map(int, input().split()))
ans = 100**3


def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


def lcm(a, b):
    return a * b // gcd(a, b)


for i in range(5):
    for j in range(i + 1, 5):
        for k in range(j + 1, 5):
            a, b, c = arr[i], arr[j], arr[k]
            abc_lcm = lcm(lcm(a, b), c)
            ans = min(ans, abc_lcm)

print(ans)
