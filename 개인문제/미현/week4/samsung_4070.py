T = int(input())

for t in range(T):
    n = int(input())
    DP = [0 for i in range(n+1)]
    DP[1] = 1

    if n >= 2:
        DP[2] = 3
    for i in range(3, n+1):
        DP[i] = DP[i-1] + 2*DP[i-2]
    print("#{} {}".format(t+1, DP[n]))