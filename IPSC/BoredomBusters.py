import sys

sys.stdin = open("b1.in", "r")
#sys.stdout = open("b1.out", "w")
T = int(input())

#B1
def rec(N):
    if N == 1:
        return 0
    if N % 3 == 0:
        Y, Z = N / 3, 2 * N / 3
        return int(Y * Z) + rec(Y) + rec(Z)
    elif N % 2 == 0:
        return int((N/2)**2) + rec(N/2)
    else:
        return int(N - 1) + int(rec(N - 1))

for _ in range(T):
    input()
    N = int(input())
    print(rec(N))
