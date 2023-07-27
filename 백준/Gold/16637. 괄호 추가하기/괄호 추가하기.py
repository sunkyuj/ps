n = int(input())
exp = input()

ans = -(2**31)


def cal(num1, op, num2):
    if op == "+":
        return num1 + num2
    elif op == "-":
        return num1 - num2
    else:
        return num1 * num2


def f(sum, op, exp):
    global ans
    if len(exp) == 0:
        ans = max(ans, sum)
        return
    if len(exp) == 1:
        ans = max(ans, cal(sum, op, int(exp)))
        return
    
    # 그냥
    f(cal(sum, op, int(exp[0])), exp[1], exp[2:])
    
    # 괄호 치기
    brac = cal(int(exp[0]), exp[1], int(exp[2]))

    if len(exp) == 3:
        f(cal(sum, op, brac), "", "")
    else:
        f(cal(sum, op, brac), exp[3], exp[4:])


f(0,"+",exp)
print(ans)