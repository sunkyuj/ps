import sys

input = lambda: sys.stdin.readline().rstrip()

def get(idx, start, end):
    global cnt, taste
    if taste:  # 맛 찾았으므로 탐색 종료
        return 0

    if cnt + seg[idx] < rank:  # rank순위에 있는 애가 범위 밖이므로 여기까지의 카운트를 다 리턴
        cnt += seg[idx]
        return seg[idx]

    if start == end:  # start번에 있는 놈이 rank순위임
        cnt += seg[idx]
        if cnt >= rank:
            taste = start
            print(taste)
        return seg[idx]  # 리턴 자체는 개수를 해줌

    # 2개로 쪼개서 탐색
    mid = (start + end) // 2
    left = get(idx * 2, start, mid)
    right = get(idx * 2 + 1, mid + 1, end)

    return left + right


def update(idx, start, end):
    seg[idx] += diff

    if start == end:
        return

    mid = (start + end) // 2

    if taste <= mid:
        update(idx * 2, start, mid)
    else:
        update(idx * 2 + 1, mid + 1, end)


n = int(input())  # 10만
candies = [0] * 1000001  # candies[i] : 맛 i인 사탕의 개수
seg = [0] * (1000001 * 4)  # 개수

for _ in range(n):
    q = input().split()

    if q[0] == "1":
        a, b = map(int, q)

        rank = b
        # b순위의 사탕 꺼내기 -> return 그 사탕의 맛
        cnt = 0
        taste = 0
        get(1, 1, 1000000)  # taste 찾아줌
        diff = -1
        candies[taste] -= 1

    else:
        a, b, c = map(int, q)

        # b 맛, c 개수(양수면 더하고 음수면 빼기)
        taste = b
        diff = c
        candies[b] += c

    update(1, 1, 1000000)