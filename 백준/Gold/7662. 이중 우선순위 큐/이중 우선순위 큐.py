import sys
from heapq import heappop, heappush
from collections import defaultdict

input = lambda: sys.stdin.readline().rstrip()

for tc in range(int(input())):
    k = int(input())
    minh, maxh = [], []
    cnt = 0
    num_dict = defaultdict(int)
    for i in range(k):  # 100만
        cmd, num = input().split()
        num = int(num)

        if cmd == "I":
            # insert
            heappush(minh, num)
            heappush(maxh, -num)
            cnt += 1
            num_dict[num] += 1
        else:
            if cnt == 0:
                continue

            if num == 1:
                # get max
                x = -heappop(maxh)
                while maxh and num_dict[x] == 0:
                    x = -heappop(maxh)

            else:
                # get min
                x = heappop(minh)
                while minh and num_dict[x] == 0:
                    x = heappop(minh)

            if num_dict[x] == 0:
                continue

            num_dict[x] -= 1
            cnt -= 1

        while maxh and num_dict[-maxh[0]] == 0:
            heappop(maxh)
        while minh and num_dict[minh[0]] == 0:
            heappop(minh)

    if minh and maxh:
        print(-maxh[0], minh[0])
    else:
        print("EMPTY")