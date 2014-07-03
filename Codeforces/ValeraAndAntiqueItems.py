N, V = map(int, input().split(' '))

L = []

for i in range(N):
    now = list(map(int, input().split(' ')))
    for j in range(1, len(now)):
        if (now[j] < V):
            L.append(str(i + 1))
            break

print(len(L))

print(' '.join(L))
