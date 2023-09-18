brac = list(input())
new_brac = []

# () [] 지우기
for br in brac:
    new_brac.append(br)
    if len(new_brac) >= 2:
        if new_brac[-2:] == ["(", ")"]:
            new_brac.pop()
            new_brac.pop()
            new_brac.append(2)
        if new_brac[-2:] == ["[", "]"]:
            new_brac.pop()
            new_brac.pop()
            new_brac.append(3)

brac = new_brac
new_brac = []

while len(brac) > 1:
    changed = False
    # XX 찾기
    i = 0
    while i < len(brac) - 1:
        if type(brac[i]) == int and type(brac[i + 1]) == int:
            brac = brac[:i] + [brac[i] + brac[i + 1]] + brac[i + 2 :]
            changed = True
        i += 1

    # [X], (X) 찾기
    i = 0
    while i < len(brac) - 2:
        if brac[i] == "(" and type(brac[i + 1]) == int and brac[i + 2] == ")":
            brac = brac[:i] + [2 * brac[i + 1]] + brac[i + 3 :]
            changed = True

        elif brac[i] == "[" and type(brac[i + 1]) == int and brac[i + 2] == "]":
            brac = brac[:i] + [3 * brac[i + 1]] + brac[i + 3 :]
            changed = True

        i += 1

    if not changed:
        print(0)
        exit()

if len(brac) == 1 and type(brac[0]) == int:
    print(brac[0])
else:
    print(0)
