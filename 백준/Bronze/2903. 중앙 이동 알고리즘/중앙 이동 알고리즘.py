n = int(input())

dp = [2]

for i in range(1,16) :
    dp.append(dp[i-1]+(dp[i-1]-1))


print(dp[n]*dp[n])

# 0 = 4     2
# 1 = 9     3
# 2 = 25    5
# 3 = 81    9 (5+5-1)