N, M = map(int, raw_input().split(' '))

state_b = [ 0 for i in range(N) ]
state_g = [ 0 for i in range(M) ]

B = list(map(int, raw_input().split(' ')))
G = list(map(int, raw_input().split(' ')))

for i in range(B[0]):
    state_b[B[i+1]] = 1;

for i in range(G[0]):
    state_g[G[i+1]] = 1;

for i in range(100 * 100 + 10):
    pos_b = i % N
    pos_g = i % M

    if state_b[pos_b] == 1 or state_g[pos_g] == 1:
        state_b[pos_b] = 1
        state_g[pos_g] = 1

ok = True

for i in range(N):
    if state_b[i] == 0:
        ok = False

for i in range(M):
    if state_g[i] == 0:
        ok = False

if ok:
    print("Yes")
else:
    print("No")
