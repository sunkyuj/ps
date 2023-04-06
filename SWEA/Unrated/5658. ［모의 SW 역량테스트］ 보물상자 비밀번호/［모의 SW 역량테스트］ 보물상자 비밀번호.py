for tc in range(int(input())):
    ans = 0
    n, k = map(int, input().split())
    arr = input()
    div = n // 4  # 12면 한 변에 3개씩, 16이면 한 변에 4개씩

    nums = set()
    for rotate in range(div):
        nums.add(arr[:div])
        nums.add(arr[div : div * 2])
        nums.add(arr[div * 2 : div * 3])
        nums.add(arr[div * 3 : div * 4])

        arr = arr[-1] + arr[:-1]

    nums = list(nums)
    nums.sort(reverse=1)
    x = nums[k - 1]
    for i in range(len(x)):
        c = x[len(x) - i - 1]
        if "0" <= c <= "9":
            ans += (16**i) * int(c)
        else:
            ans += (16**i) * int(10 + ord(c) - ord("A"))

    print(f"#{tc+1} {ans}")
