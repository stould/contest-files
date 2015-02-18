//Accepted
#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;
typedef unsigned long long uInt;

const int MAXN = 50001;

const uInt MOD = 1000000007ULL;
const uInt BASE = 29ULL;

int T, N;
char S[MAXN];
uInt hA[MAXN], pA[MAXN], invA[MAXN];

void fix(uInt& value, uInt mod) {
	if (value < 0LL) value += mod;
	value %= mod;
}

uInt modPow(uInt a, uInt n, uInt mod) {
	uInt res = 1ULL;
	
	while (n > 0ULL) {
		if (n & 1) {
			res = (res * a) % mod;
		}
		a = (a * a) % mod;
		n >>= 1;
	}
	
	return res;
}

uInt inv(uInt x, uInt mod) {
	return modPow(x, mod - 2, mod);
}
 
void hash(string s) {
	hA[0] = 0UL;

	for (int i = 0; i < N; i++) {
		int val = S[i] - 'A' + 1;

		if (i == 0) {
			hA[i] = (hA[i] + (pA[i] * val)) % MOD;
		} else {
			hA[i] = (hA[i - 1] + (pA[i] * val)) % MOD;
		}
	}
}

uInt hashL(int l, int r) {
	uInt ans_a = hA[r];

	if (l > 0) {
		ans_a -= hA[l - 1];
	}
	
	ans_a = (ans_a + MOD) % MOD;

	if (l > 0) {
		ans_a = (ans_a * invA[l]) % MOD;
	}

	return ans_a;
}

void gen(void) {
	freopen("i.in", "w", stdout);
	int t = 100;
	cout << t << endl;
	srand(time(NULL));
	for (int x = 0; x < t; x++) {
		int len = 50000;
		for (int j = 0; j < len; j++) {
			cout << char('A' + (rand() % 2));
		}
		cout << endl;
	}	
}

int main(void) {
	scanf("%d", &T);

	pA[0] = 1LL;
	
	for (int i = 0; i < MAXN; i++) {
		if (i > 0) {
			pA[i] = (pA[i - 1] * BASE) % MOD;
		}		
		invA[i] = inv(pA[i], MOD) % MOD;
	}

	for (int t = 1; t <= T; t++) {
		scanf("%s", S);
		N = strlen(S);

		hash(S);

		int ans = 0;	   
	
		int L = 0, R = N - 1;
		int pL = 0, pR = N - 1;
		
		bool reach = false;
		
		for ( ; L < R; ) {
			//cout << S.substr(pL, L - pL + 1) << " " << hashL(pL, L) << " " << S.substr(R, pR - R + 1) << " " << hashL(R, pR) << "\n";
			uInt ha = hashL(pL, L);
			uInt hb = hashL(R, pR);

			if (ha == hb) {
				ans += 2;
				pL = L + 1;
				pR = R - 1;

				if (L + 1 == R) {
					reach = true;
				}
			}
			L += 1;
			R -= 1;
		}

		if (!reach) ans += 1;
		printf("Case #%d: %d\n", t, ans);
		//cout << "Case #" << t << ": " << ans << endl;
	}
    return 0;
}
