N = int(input(''))

L = list(map(int, input('').split(' ')))

A = sum(L)

L.sort()

for i in range(N):
    if L[i] < 0:
        L[i] = -L[i]
    else:
        if (N - i) % 2 == 0:
            L[i] = -L[i]
        break
        
print(L)
print(max(A, sum(L)))
