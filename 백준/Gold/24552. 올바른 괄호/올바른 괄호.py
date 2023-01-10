s = input()
l = len(s)


def f(s):

    st = []
    for i in range(l):
        st.append((i, s[i]))
        if len(st) >= 2 and st[-2][1] == "(" and st[-1][1] == ")":
            del st[-2:]

    if st[0][1] == "(":
        return list(s)[st[0][0] :].count("(")
    else:
        return list(s)[: st[0][0] + 1].count(")")


print(f(s))