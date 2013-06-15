n = int(input())
mem = {}
mx = 0
ans = ''

for i in range(n):
    ls = list(map(str, input().split(" ")))
    if ls[0] not in mem:
        mem[ls[0]] = int(ls[1])
    else:
        mem[ls[0]] = int(mem[ls[0]]) + int(ls[1])
    if mem[ls[0]] > mx:
        mx = mem[ls[0]]
        ans = ls[0]
print("%s" % (ans))
    
