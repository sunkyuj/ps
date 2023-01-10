import sys

sys.setrecursionlimit(10 ** 8)
input = lambda: sys.stdin.readline().rstrip()

n = int(input())
card = list(map(int, input().split()))
m = int(input())
guess = list(map(int, input().split()))

card.sort()


def bin(key):
    s, e = 0, len(card) - 1

    while s <= e:
        m = (s + e) // 2
        if key == card[m]:
            return m
        elif key > card[m]:
            s = m + 1
        else:
            e = m - 1
    return -1
for k in guess:
    if bin(k)!=-1:
        print(1,end=" ")
    else:
        print(0,end=" ")
        
