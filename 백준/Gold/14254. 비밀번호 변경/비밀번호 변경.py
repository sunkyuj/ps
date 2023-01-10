from collections import Counter

s = input()
k = int(input())
diff = len(s) - k
if diff == 0:
    print(0)
    exit()
cnt = 0
visit = [0 for _ in s]

for i in range(k):
    if visit[i]:
        break
    ct = Counter()
    for j in range(i, len(s), diff):
        visit[j] = 1
        ct.update(s[j])
    best = ct.most_common(1)[0][0]

    for j in range(i, len(s), diff):
        if s[j] != best:
            cnt += 1
print(cnt)

#   amavckdkz
# amavckdkz


# amavckdkz
#   amavckdkz

"""

# amavckdkz
#   amavckdkz
  
aabbccdd
      aabbccdd
  
diff = 2 <-- (len(s)-k)


loool
  loool


asasdds
  asasdds

abcabcabc
   abcabcabc
  
"""
