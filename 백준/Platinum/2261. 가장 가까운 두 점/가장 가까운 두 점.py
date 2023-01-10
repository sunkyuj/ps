import sys

sys.setrecursionlimit(10 ** 8)
input = lambda: sys.stdin.readline().rstrip()


def dist(p1, p2):
    return (p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2


def cp(start, end):

    if start == end:  # 점 1개
        return 999999
    if end - start == 1:  # 점 2개
        return dist(p_list[start], p_list[end])

    mid = (start + end) // 2
    min_d = min(cp(start, mid), cp(mid, end))

    candidates = []
    for i in range(start, end + 1):  # x축 기준으로 후보 점 찾기
        # if dist(p_list[mid], p_list[i]) < min_d:
        if (p_list[mid][0] - p_list[i][0]) ** 2 < min_d:
            candidates.append(p_list[i])

    candidates.sort(key=lambda x: x[1])  # y축 기준 정렬해서 비교 시작
    for i in range(len(candidates)):
        for j in range(i + 1, len(candidates)):
            if (candidates[i][1] - candidates[j][1]) ** 2 < min_d:
                min_d = min(min_d, dist(candidates[i], candidates[j]))
            else:
                break

    return min_d


def Input():
    global n, p_list
    n = int(input())
    p_list = [list(map(int, input().split())) for i in range(n)]
    p_list.sort()


def solution():
    print(cp(0, len(p_list) - 1))


if __name__ == "__main__":
    Input()
    solution()