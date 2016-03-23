import sys

sys.stdin = open("i.in", "r")
s1 = str(input())
s2 = str(input())

N = len(s1)
M = len(s2)

dp = [ [0 for j in range(M+5)] for i in range(N+5) ]

for i in range(1, N):
  for j in range(1, M):
    if i == 0 or j == 0:
      dp[i][j] = 0
    elif s1[i] == s2[j]:
      dp[i][j] = dp[i-1][j-1] + 1
    else:
      dp[i][j] = max(dp[i-1][j], dp[i][j-1])
print("%d" % (dp[N-1][M-1]))
