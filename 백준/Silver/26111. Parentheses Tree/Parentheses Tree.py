s = input()
ans = 0
st = []
cur = 0

for i in range(len(s)):
    if s[i] == "(":
        st.append([s[i], cur])
        cur += 1
    else:
        brac, lv = st.pop()
        if s[i - 1] == "(":  # leaf
            ans += lv
        cur -= 1

print(ans)
