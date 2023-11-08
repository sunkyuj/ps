import sys

arr = list(map(int, sys.stdin.readlines()))
for n in arr:
    i = 1
    while i % n != 0:
        i = i * 10 + 1
    print(len(str(i)))
