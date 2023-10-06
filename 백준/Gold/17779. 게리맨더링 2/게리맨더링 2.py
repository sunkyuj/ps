n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]

ans = 100000000

# 구역 나누기
# d1, d2 ≥ 1,
# 1 ≤ x < x+d1+d2 (x끝) ≤ N,
# 1 ≤ y-d1(위) < y < y+d2(아래) ≤ N

in_range = lambda y, x: 0 <= y < n and 0 <= x < n

for y in range(1, n - 1):  # 20
    for x in range(1, n - 1):  # 400
        # y,x는 끝 칸이 될 수 없음
        for d1 in range(1, n - 1):  # 8000
            uy, ux = y - d1, x + d1  # 위쪽 꼭짓점
            if not in_range(uy, ux):
                break
            for d2 in range(1, n - 1):  # 16만
                dy, dx = y + d2, x + d2  # 아래쪽 꼭짓점
                ry, rx = y - d1 + d2, x + d1 + d2  # 오른쪽 꼭짓점
                if not in_range(dy, dx) or not in_range(ry, rx):
                    break

                area = [0, 0, 0, 0, 0]

                # 5번 선거구 경계
                area5 = set()
                for i in range(d1 + 1):
                    area5.add((y - i, x + i))
                for i in range(d2 + 1):
                    area5.add((y + i, x + i))
                for i in range(d1 + 1):
                    area5.add((dy - i, dx + i))
                for i in range(d2 + 1):
                    area5.add((uy + i, ux + i))

                is_a5 = False
                for i in range(n):  # 320만
                    for j in range(n):  # 6400만

                        if (is_a5 and (i, j) in area5) or (i, j) in [(uy, ux), (dy, dx)]:  # 나옴
                            is_a5 = False
                            area[4] += board[i][j]
                            continue

                        if not is_a5 and (i, j) in area5:  # 진입
                            is_a5 = True

                        if is_a5:
                            area[4] += board[i][j]
                            continue

                        if (0 <= i < y) and (0 <= j <= ux):  # 1
                            anum = 0
                        elif (0 <= i <= ry) and (ux < j < n):  # 2
                            anum = 1
                        elif (y <= i < n) and (0 <= j < dx):  # 3
                            anum = 2
                        elif (ry < i < n) and (dx <= j < n):  # 4
                            anum = 3

                        area[anum] += board[i][j]
                diff = max(area) - min(area)
                ans = min(ans, diff)


# 각 구역 계산

# ans = min(ans, 최대구역 - 최소구역)

print(ans)


"""

5 5 5 5 5 
5 1 5 5 5
5 5 5 5 5
5 5 5 5 5 
5 5 5 5 5 


1 25
2 36
3 18
4 35
5 25

"""
