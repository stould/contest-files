
N, M = map(int, input().split(' '))

ln = list(map(int, input().split(' ')))
lm = list(map(int, input().split(' ')))

dc = {}

for _ in range(1, 2**N):
    s = 1
    msk = _
    for i in range(N):
        if _ & (1 << i):
            s = s * ln[i]
    dc[s] = msk

for _ in range(1, 2**M):
    s = 1
    msk = _

    for i in range(M):
        if _ & (1 << i):
            s = s * lm[i]

    if s in dc:
        an = []
        am = []

        for i in range(N):
            if dc[s] & (1 << i):
                an.append(str(ln[i]))
    
        for i in range(M):
            if _ & (1 << i):
                am.append(str(lm[i]))
        print("Y")
        print("{0} {1}".format(len(an), len(am)))
        print(" ".join(an))        
        print(" ".join(am))

        exit(0)
print("N")
