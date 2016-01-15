N = int(input())

isZero = False
cntZero = 0
other = 1

def isOk(x):
    seen = [ 0 for _ in range(10) ]

    while x > 0:
        seen[int(x % 10)] += 1
        x //= 10

    s = 0

    for i in range(2, 10):
        s += seen[i];

    return s == 0 and seen[1] == 1


def len(x):
    ln = 0

    while x > 0:
        x = x // 10
        ln += 1

    return ln

P = input().split(" ")

for i in range(N):
    P[i] = int(P[i])

    if isOk(P[i]):
        cntZero += len(P[i]) - 1;
    else:
        if P[i] == 0:
            isZero = True
        else:
            other = P[i]

ans = "0"
            
if not isZero:
    for i in range(cntZero - 1):
        ans = ans + "0"
        
    ans = str(other) + ans
        
print(ans)
