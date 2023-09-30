from collections import deque

s = input()
t = input()
len_s = len(s)

q = deque()
q.append(t)

while q:
    x = q.popleft()
    if x == [] or len(x) < len_s:
        continue
    if x == s:
        print(1)
        exit()

    if x[-1] == "A":
        q.append(x[:-1])
    elif x[-1] == "B":
        new = x[:-1]
        q.append(new[::-1])
    else:
        continue
print(0)
