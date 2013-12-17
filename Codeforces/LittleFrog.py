import sys

N = int(input())

id = 0
ans = [0 for _ in range(N) ]

for i in range(0, N - 1, 2):
	ans[i] = id + 1;
	ans[i + 1] = N - id
	id = id + 1

if N % 2 == 1:
	ans[N - 1] = N // 2 + 1

for i in ans:
	sys.stdout.write(str(i) + " ")
print()