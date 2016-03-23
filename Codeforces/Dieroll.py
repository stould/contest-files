n, m = map(int, raw_input().split(" "))

upper = 7 - max(n, m)

base = 6

for i in range(6, 1, -1):
  while upper % i == 0 and base % i == 0:
    upper /= i
    base /= i
print("%d/%d" % (upper, base))


