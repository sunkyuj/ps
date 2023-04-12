n = int(input())  # 100
switch = [0] + list(map(int, input().split()))
stu_n = int(input())  # 100
for stu in range(stu_n):
    sex, switch_number = map(int, input().split())
    if sex == 1:
        for i in range(switch_number, n + 1, switch_number):
            switch[i] = int(not switch[i])
    else:
        switch[switch_number] = int(not switch[switch_number])
        l, r = switch_number - 1, switch_number + 1
        while 1 <= l and r <= n:
            if switch[l] != switch[r]:
                break

            switch[l] = int(not switch[l])
            switch[r] = int(not switch[r])
            l -= 1
            r += 1

for i in range(1, n + 1):
    print(switch[i], end=" ")
    if i % 20 == 0:
        print()
