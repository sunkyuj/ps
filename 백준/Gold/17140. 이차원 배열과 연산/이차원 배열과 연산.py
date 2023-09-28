from collections import Counter

r, c, k = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(3)]
tarr = [[arr[j][i] for j in range(3)] for i in range(3)]

"""
행이 열보다 많거나 같으면 r연산
열이 행보다 많으면 c연산

연산: [3,1,1] -연산-> [3,1,1,2] -연산-> [2,1,3,1,1,2]  -연산-> [3,1,2,2,1,3]

행이나 열 크기 큰거에 맞춤, 키운 곳에는 0이 들어감 (0은 연산시 무시)
행이나 열 크기 100 넘으면 101개부턴 버림
"""
max_r, max_c = 3, 3
ans = 0
while ans <= 100:
    if r <= len(arr) and c <= len(tarr) and arr[r - 1][c - 1] == k:
        break
    if max_r >= max_c:  # r연산, r 크기 그대로, c 크기 바뀜
        max_c = 0
        for i, row in enumerate(arr):
            counter = Counter(row)
            new_row = []
            items = sorted(counter.items(), key=lambda x: (x[1], x[0]))
            for a, b in items:
                if a == 0:
                    continue
                if len(new_row) == 100:
                    break
                new_row.append(a)
                max_c = max(max_c, len(new_row))
                if len(new_row) == 100:
                    break
                new_row.append(b)
                max_c = max(max_c, len(new_row))
            arr[i] = new_row
        # 0 넣어주기
        for i in range(len(arr)):
            len_r = len(arr[i])
            arr[i] += [0] * (max_c - len_r)
        # tarr 에 반영
        tarr = [[arr[i][j] for i in range(len(arr))] for j in range(max_c)]

    else:  # c연산, c 크기 그대로, r 크기 바뀜
        max_r = 0
        for i, col in enumerate(tarr):
            counter = Counter(col)
            new_col = []
            items = sorted(counter.items(), key=lambda x: (x[1], x[0]))
            for a, b in items:
                if a == 0:
                    continue
                if len(new_col) == 100:
                    break
                new_col.append(a)
                max_r = max(max_r, len(new_col))
                if len(new_col) == 100:
                    break
                new_col.append(b)
                max_r = max(max_r, len(new_col))
            tarr[i] = new_col
        # 0 넣어주기
        for i in range(len(tarr)):
            len_c = len(tarr[i])
            tarr[i] += [0] * (max_r - len_c)
        # arr 에 반영
        arr = [[tarr[i][j] for i in range(len(tarr))] for j in range(max_r)]

    ans += 1

if ans > 100:
    ans = -1
print(ans)
