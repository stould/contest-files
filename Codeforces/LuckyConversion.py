A = input()
B = input()

mis_a, mis_b = 0, 0

for i in range(len(A)):
    if A[i] != B[i]:
        if A[i] == '4':
            mis_a += 1
        else:
            mis_b += 1
print("%d" % max(mis_a, mis_b))
