T = int(input())

for _ in range(1, T + 1):
    line = input().split(' ')

    L = line[0]
    N = int(line[1])

    sz = 0
    bf = 0

    ans = ""

    for x in range(1, 50):
        if bf > N:
            break
        bf += pow(len(L), x)
        sz += 1

    for x in range(sz):
        ans += L[(N - 1) % len(L)]
        N = (N - 1) // len(L)

    print("Case #%d: %s" % (_, ans[::-1]))
