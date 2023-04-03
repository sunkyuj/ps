n = int(input())
par = {i: 0 for i in range(n)}
a, b = map(int, input().split())
m = int(input())
for _ in range(m):
    x, y = map(int, input().split())  # x: parent / y: child
    par[y] = x
# 7 2 1 / 3 1 --> 3
# 7 2 1 / 8 2 1 --> 2
# 7 2 1 / 2 1 --> 1
a_anc, b_anc = set(), set()
aa, bb = a, b
while par[aa]:
    a_anc.add(aa)
    aa = par[aa]
while par[bb]:
    b_anc.add(bb)
    bb = par[bb]

if aa != bb:
    print(-1)
else:
    rel = len(a_anc - b_anc) + len(b_anc - a_anc)
    print(rel)


"""
1
2       3
7 8 9


4
5 6





"""
