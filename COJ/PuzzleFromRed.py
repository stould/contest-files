while True:
	D, K = map(int, raw_input().split(" "))
    
	if D == 0 and K == 0:
		break

	digit = D
	soma = 0

	for i in range(K):
	    D = 10 * D + digit

#	D = pow(D, 2)

#	while D > 0:
#		soma = soma + D % 10
#		D = D // 10

	print(soma)
