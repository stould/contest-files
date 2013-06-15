import math
import sys

#sys.stdin = open("i.in", "r")
#sys.stdout = open("o.ot", "w")

T = int(input())

for _ in range(1, T + 1):
    r, t = map(int, input().split(" " ))


    low, mid, high = 1, 1, 100000000000000000000000
    best = 1

    while high - low > 1:
        mid = float((low + high) // 2)
        ok = True

        a1 = float(r)
        an = float(a1 + (mid - 1) * 1.0)

        acc = float(((mid * (a1 + an)) / 2.0) * math.pi)
        
        if acc <= float(t):
            low = mid + 1
            best = max(best, int(mid))
        else:
            high = mid - 1
    print("Case #%d: %d" % (_, best))
            
