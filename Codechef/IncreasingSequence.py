n, d = map(int, input().split(" "))
l = list(map(int, input().split(" ")))

count = 0

for i in range(1, n):
   if l[i - 1] >= l[i]:
       outcome = l[i - 1] - l[i] + d
       l[i] = l[i] + int(outcome / d) * d
       count = count + int(outcome / d)
print("%d" % (count))
