N, S = int(input()), 0

line = str(input()).split()

for i in range(N):
    S = S + int(line[i])

T = int(input())

if T == S:
    print("Acertou")
else:
    print("Errou")
