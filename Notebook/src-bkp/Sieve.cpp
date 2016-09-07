//Crivo de Erastotenes Comum - (Todos os numeros primes <= N)
bool sieve(int n) {
	bool prime[n+1];
	fill(prime, prime + n + 1,true);
	prime[0] = false;
	prime[1] = false;

	int m = (int) sqrt(n);

	for(int i = 2; i <= m; i++) {
		if(prime[i]) {
			for (int k=i*i; k<=n; k+=i) {
				prime[k]=false;
			}
		}
	}
	return prime;
}
