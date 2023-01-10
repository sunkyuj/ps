n, m = map(int, input().split())
money_comp = [[] for _ in range(n + 1)]  # money_comp[money][c]
money_comp[0] = [0] * m

for i in range(1, n + 1):
    money_comp[i] = list(map(int, input().split()))[1:]

memo = [[0 for _ in range(n + 1)] for _ in range(m)]  # memo[comp][money]
path_memo = [[[] for _ in range(n + 1)] for _ in range(m)]


def f(comp, budget):
    if memo[comp][budget]:
        return memo[comp][budget]

    if comp == m - 1:
        memo[comp][budget] = money_comp[budget][comp]
        path_memo[comp][budget].append(budget)
        return memo[comp][budget]

    for cost in range(budget + 1):
        if budget >= cost:
            memo[comp + 1][budget - cost] = f(comp + 1, budget - cost)

            if (
                memo[comp][budget]
                < money_comp[cost][comp] + memo[comp + 1][budget - cost]
            ):
                memo[comp][budget] = (
                    money_comp[cost][comp] + memo[comp + 1][budget - cost]
                )
                path_memo[comp][budget] = [cost] + path_memo[comp + 1][budget - cost]

            """memo[comp][budget] = max(
                memo[comp][budget],
                money_comp[cost][comp] + memo[comp + 1][budget - cost],
            )"""
    return memo[comp][budget]


print(f(0, n))

for i in range(m):
    print(path_memo[0][n][i], end=" ")

# 1 2 1

"""
4 3
1 5 1 7
2 6 5 8
3 7 9 9
4 10 15 13


"""
