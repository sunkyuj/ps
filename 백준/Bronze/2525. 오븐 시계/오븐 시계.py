h, m = map(int, input().split())
x = int(input())

a = (m + x) % 60
b = (m + x) // 60

if (h + b) > 23:
    print(h + b - 24, a)
else:
    print(h + b, a)
