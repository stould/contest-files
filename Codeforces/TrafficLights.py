def fmod(x, m):
    while x >= m:
        x = x - m
    return x

l, d, v, g, r = map(int, input().split(' '))

x = fmod(float(d / v), g + r)

ans = (d / v) + (l - d) / v

if x >= g:
    ans = ans + g + r - x    

print("%.10f" % (ans))

