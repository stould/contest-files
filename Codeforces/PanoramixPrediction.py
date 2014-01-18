N, M = map(int, input().split(" "))

primes = [x for x in range(2,100) if not [t for t in range(2,x) if not x % t]]

is_next = False

for i in range(N + 1, 70):
    if i in primes:
        if i == M:
            is_next = True
        break

if is_next:
    print("YES")
else:
    print("NO")
