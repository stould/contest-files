T = int(input())

func = lambda N : N and func(N - 1) * N or 1
    
for _ in range(T):
    K = int(input())
    print(func(K))
