bool p[MAXN];
vector<int> primes;

void build(void) {
	memset(p, true, sizeof(p));

	for (int i = 2; i <= MAXN; i++) {
		if (p[i]) {
			primes.push_back(i);
			for (int j = i * i; j <= MAXN; j += i) {
				p[j] = false;
			}
		}
	}
}

int func(Int x) {
	int ans = 1;

	for (int i = 0; i < (int) primes.size() && x > 1; i++) {
		if (x % primes[i] == 0) {
			int curr = 0;
			while (x % primes[i] == 0) {
				x /= primes[i];
				curr += 1;
			}
			ans *= (curr + 1);
		}
	}
	return ans;
}

set<Int> st;

void go(int id, Int v, int last) {
	Int base = primes[id];
	if (v > MAXV) return;
	st.insert(v);

	for (int i = 0; i <= last; i++) {
		v *= (Int) base;
		if (v > MAXV) break;
		go(id + 1, v, i);
	}
}
vector<Int> ans;

for (set<Int>::iterator it = st.begin(); it != st.end(); it++) {
	int s = func(*it);
		if (s > curr) {
		ans.push_back(*it);
		curr = s;
	}
}

