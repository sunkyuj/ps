import sys

sys.setrecursionlimit(10 ** 8)
input = lambda: sys.stdin.readline().rstrip()

s1 = "0" + input()
s2 = "0" + input()

lcs = [[0 for _ in range(len(s2))] for _ in range(len(s1))]

for i in range(len(s1)):
    lcs[i][0] = 0
for j in range(len(s2)):
    lcs[0][j] = 0

for i in range(1, len(s1)):
    for j in range(1, len(s2)):
        if s1[i] == s2[j]:
            lcs[i][j] = lcs[i - 1][j - 1] + 1
        else:
            lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j])

print(lcs[len(s1) - 1][len(s2) - 1])

ans = ""
i, j = len(s1) - 1, len(s2) - 1
while lcs[i][j] != 0:
    while lcs[i][j] == lcs[i - 1][j]:
        i -= 1
    while lcs[i][j] == lcs[i][j - 1]:
        j -= 1
    ans += s1[i]
    i -= 1
    j -= 1
print(ans[::-1])


"""



    C A P C A K
  0 0 0 0 0 0 0
A 0 0 1 1 1 1 1            
C 0 1 1 1 2 2 2            
A 0 1 2 2 2 3 3             
Y 0 1 2 2 2 3 3             
K 0 1 2 2 2 3 4            
P 0 1 2 3 3 3 4            

"""
