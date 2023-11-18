for _ in range(int(input())):
    a, b = map(int, input().split())
    li = [a % 10]
    for i in range(1, b):
        if (li[i - 1] * a) % 10 == li[0]:
            break
        li.append((li[i - 1] * a) % 10)
    ans = li[b % len(li) - 1]
    print(ans if ans != 0 else 10)
