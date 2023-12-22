res = 0
while (line := input()) != "exit":
    l = line.split()
    blocks = ((l[0] + "?") * 5)[:-1]
    nums = list(map(int, l[1].split(","))) * 5
    n = len(blocks)
    m = len(nums)
    p = max(*nums)
    dp = []
    for i in range(n + 2):
        row = []
        for j in range(m + 2):
            inner_row = [0] * (p + 2)
            row.append(inner_row)
        dp.append(row)
    dp[0][0][0] = 1
    c = 0
    for i in range(1, n + 1):
        if blocks[i - 1] == "#":
            c += 1
        else:
            c = 0
        if c > 0:
            dp[i][0][c] = 1
    for i in range(1, n + 1):
        if blocks[i - 1] == "#":
            break
        dp[i][0][0] = 1
    for i in range(1, n + 1):
        if blocks[i - 1] == ".":
            for j in range(1, m + 1):
                dp[i][j][0] = dp[i - 1][j - 1][nums[j - 1]] + dp[i - 1][j][0]
        elif blocks[i - 1] == "#":
            for j in range(m + 1):
                for k in range(p):
                    dp[i][j][k + 1] = dp[i - 1][j][k]
        else:
            for j in range(1, m + 1):
                dp[i][j][0] = dp[i - 1][j - 1][nums[j - 1]] + dp[i - 1][j][0]
            for j in range(m + 1):
                for k in range(p):
                    dp[i][j][k + 1] = dp[i - 1][j][k]
    res += dp[n][m][0] + dp[n][m - 1][nums[m - 1]]
print(res)
