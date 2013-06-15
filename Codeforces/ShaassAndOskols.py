n = int(raw_input())

cnt = map(int, raw_input().split(' '))

m = int(raw_input())

for x in xrange(m):
    x, y = map(int, raw_input().split(' '))

    x = x - 1

    go_up = y - 1
    go_down = cnt[x] - y

    if x - 1 >= 0:
        cnt[x-1] = cnt[x-1] + go_up
    if x + 1 < n:
        cnt[x+1] = cnt[x+1] + go_down

    cnt[x] = 0
    
for x in xrange(n):
    print cnt[x]
