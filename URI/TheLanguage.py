import math
import sys

while True:
    N, Q = map(int, sys.stdin.readline().split(' '))

    if N == 0 and Q == 0:
        break

    T = int(sys.stdin.readline())
    A = math.factorial(N - Q + 1)

    if (A <= T):
        print("%d" % A)
    else:
        print("descartado")
