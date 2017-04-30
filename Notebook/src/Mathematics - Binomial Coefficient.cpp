Int nCr(Int n, Int k) {
	Int res = 1;
	
	if (k > (n >> 1LL)) {
		k = n-k;
	}
	for (Int i = 1; i <= k; i++, n--) {
		res = (res * n) / i;
	}
	
	return res;
}

