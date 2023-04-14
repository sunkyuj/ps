from itertools import combinations

n, k = map(int, input().split())
# antic은 항상 포함해야함, k 는 5 이상이어야 함, 아니면 항상 0 나옴
if k < 5:
    print(0)
    exit()

words = []  # 각 단어 길이 8~15
alps = set()
must = set("antic")

for i in range(n):
    s = set(input())
    if len(s) > k:
        continue
    alps.update(s)
    s -= must
    words.append(s)


before = len(alps)
alps -= must
after = len(alps)
sub = before - after
k -= sub
if k > len(alps):
    k = len(alps)

ans = 0
for comb in combinations(alps, k):  # 최대 21C10 == 30만
    comb = set(comb)
    cnt = 0
    for word in words:  # 50
        all_in = True
        for c in word:  # 15
            if c not in comb:
                all_in = False
                break
        if all_in:
            cnt += 1
    ans = max(ans, cnt)
print(ans)
