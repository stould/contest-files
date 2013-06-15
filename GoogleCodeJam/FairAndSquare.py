import sys

#sys.stdin = open("i.in", "r")
#sys.stdout = open("o.ot", "w")

MAXN = pow(10, 10)

buff = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '101', '202', '303', '404', '505', '606', '707', '808', '909']
values = set()

#LIB

def is_square(apositiveint):
  x = apositiveint // 2
  seen = set([x])
  while x * x != apositiveint:
    x = (x + (apositiveint // x)) // 2
    if x in seen: return False
    seen.add(x)
  return True


def func(x):
    y = str(int(x))[::-1]
    return str(int(x)) == str(int(y))

def generateA(s):
    if int(s) * int(s) > MAXN or int(s)* int(s) in values:
        return
    if func(s) and func(int(s)*int(s)) and int(s) * int(s) <= MAXN:
        values.add(int(s)*int(s))
    for _ in buff:
        generateA(_+s+_)
        generateA(s+str(s)[::-1])


def binary_search(a, x, lo=0, hi=None):
    mid = 0
    if hi is None:
        hi = len(a)
    while lo < hi:
        mid = (lo + hi) // 2
        midval = a[mid]
        if midval < x:
            lo = mid + 1
        elif midval > x:
            hi = mid
        else:
            return mid
    return mid

#END LIB

for i in range(1000000000000):
    if func(int(i)) and func(int(i)*int(i)):
        print(i*i)
        
values = list(sorted(values))

T = int(input())

for _ in range(1, T + 1, 1):
    N, M = map(int, input().split(' '))

    low = binary_search(values, N, 0, len(values))
    high = binary_search(values, M, 0, len(values))

    if values[low] < N:
        low += 1
    if values[high] > M:
        high -= 1

    ans = 0

    if low != high:
        ans = high - low + 1
    else:
        if values[low] >= N and values[high] <= M:
            ans = 1

    print("Case #%d: %d" % (_, ans))
