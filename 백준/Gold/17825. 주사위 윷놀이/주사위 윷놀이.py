orders = list(map(int, input().split()))
basic = list(range(0, 41, 2))
short_path = [
    [10, 13, 16, 19, 25, 30, 35, 40],  # loc == 5
    [20, 22, 24, 25, 30, 35, 40],  # loc == 10
    [30, 28, 27, 26, 25, 30, 35, 40],  # loc == 15
    [40],
]

ans = 0


def copy(state):
    new = [{}, {}, {}, {}]
    for i in range(4):
        new[i]["loc"] = state[i]["loc"]
        new[i]["path"] = state[i]["path"]
    return new


def movable(state, idx, move):
    path = state[idx]["path"]
    goal = state[idx]["loc"] + move
    if path == basic and goal % 5 == 0:  # 파란칸
        path_num = goal // 5
        path = short_path[path_num - 1]
        goal = 0

    for i in range(4):
        if i == idx:
            continue
        other_loc, other_path = state[i]["loc"], state[i]["path"]
        if other_loc == -1:
            continue
        if path == basic:
            if other_path == basic and other_loc == goal:
                return False
        else:
            if goal >= len(path):  # 완주
                continue
            if path[goal] == 30 and other_path[other_loc] == 30:
                if (goal == 0 and other_loc != 0) or (goal != 0 and other_loc == 0):
                    continue
                else:
                    return False
            elif path[goal] in (16, 22, 24, 26, 28):  # 두개씩 있음
                if other_path == path and other_loc == goal:
                    return False
            elif path[goal] == other_path[other_loc]:
                return False
    return True


def f(idx, state, score):
    global ans
    if idx == 10:
        ans = max(ans, score)
        return

    move = orders[idx]
    for i in range(4):
        if state[i]["loc"] == -1 or not movable(state, i, move):  # 이미 완주함
            continue
        new = copy(state)
        new_loc = new[i]["loc"] + move

        if new_loc >= len(new[i]["path"]):  # 완주
            new[i]["loc"] = -1
            f(idx + 1, new, score)
            continue

        if new[i]["path"] == basic and new_loc % 5 == 0:  # 파란칸
            path_num = new_loc // 5
            new[i]["path"] = short_path[path_num - 1]
            new_loc = 0

        new[i]["loc"] = new_loc
        f(idx + 1, new, score + new[i]["path"][new_loc])


state = [{"loc": 0, "path": basic} for _ in range(4)]
f(0, state, 0)

print(ans)
