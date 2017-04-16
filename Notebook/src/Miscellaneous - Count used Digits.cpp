Int func(int val) {
	int digitCount = (int) log10(val) + 1;
	Int ans = 0LL;
	Int p = 1LL;

	for (int i = 0; i < digitCount - 1; i++) {
		ans += p * 9 * (i + 1);
		p *= 10;
	}
	
	ans += (val - p + 1) * digitCount;
	
	return ans;
}
