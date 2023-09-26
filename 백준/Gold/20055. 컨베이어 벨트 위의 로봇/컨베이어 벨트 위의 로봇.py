n, k = map(int, input().split())
n2 = n * 2
belt = list(map(int, input().split()))
robots = [0] * n2  # 로봇이 현재 있는지
ans = 0
cnt = 0

while 1:
    ans += 1
    # 회전
    belt = [belt[-1]] + belt[:-1]
    robots = [robots[-1]] + robots[:-1]

    # 내리는 위치 로봇 삭제
    if robots[n - 1]:
        robots[n - 1] = 0

    # 움직이기
    for i in range(n - 2, -1, -1):
        if robots[i] and robots[i + 1] == 0 and belt[i + 1]:
            robots[i] = 0
            robots[i + 1] = 1 if i + 1 != n - 1 else 0
            belt[i + 1] -= 1
            if belt[i + 1] == 0:
                cnt += 1

    # 올리기
    if belt[0] > 0 and robots[0] == 0:
        belt[0] -= 1
        if belt[0] == 0:
            cnt += 1
        robots[0] = 1

    if cnt >= k:
        break

print(ans)
