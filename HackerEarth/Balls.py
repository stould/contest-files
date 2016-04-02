N = int(raw_input())
L = list(map(int, raw_input().split(" ")))

ans = 0

L.sort()

for i in range(1, N + 1):
    iv = i * i

    l = 0
    h = len(L) - 1
    best = 0
    
    while l <= h:
        m = (l + h) // 2

        if L[m] < iv:
            l = m + 1
        else:
            h = m - 1

            best = m

    ans = ans + max(0, i * i - L[best])

    del L[best]

print(ans)
