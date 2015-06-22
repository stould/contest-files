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

const int INF = INT_MAX / 4;
const int MAXN = 105;
const int MAX_VAL = 59;
const int LEN = 17;

int N;
int A[MAXN], P[MAXN];
vector<int> primes;
vector<int> ans;
int bits[MAXN];

int dp[MAXN][1 << LEN];

int func(int pos, int mask) {
	if (pos >= N) {
		return 0;
	} else {
		int& ans = dp[pos][mask];
		
		if (ans == -1) {
			ans = INF;
			
			for (int i = 1; i <= MAX_VAL; i++) {
				if ((bits[i] & mask) == 0) {
					chmin(ans, abs(A[pos] - i) + func(pos + 1, mask | bits[i]));
				}
			}
		}
		
		return ans;
	}
}

void rec(int pos, int mask) {
	if (pos == N) {
		return;
	} else {
		int best = 0, val = INF;
		
		for (int i = 1; i <= MAX_VAL; i++) {
			if ((bits[i] & mask) == 0) {
				int now = abs(A[pos] - i) + func(pos + 1, mask | bits[i]);

				if (val > now) {
					val = now;
					best = i;
				}
			}
		}
		ans.push_back(best);
		rec(pos + 1, mask | bits[best]);
	}	
}

int main(void) {
	cin >> N;

	memset(P, true, sizeof(P));
	
	for (int i = 2; i <= MAX_VAL; i++) {
		if (P[i]) {
			for (int j = i * i; j <= MAX_VAL; j += i) {
				P[j] = false;
			}			
			primes.push_back(i);
		}
	}

	for (int i = 2; i <= MAX_VAL; i++) {
		int val = i;
		for (int j = 0; j < (int) primes.size(); j++) {
			if (val % primes[j] == 0) {
				bits[i] |= (1 << j);
				
				while (val % primes[j] == 0) {
					val /= primes[j];
				}
			}
		}		
	}
	
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	
	memset(dp, -1, sizeof(dp));
	
	int sf = func(0, 0);
	rec(0, 0);

	int ed = 0;
	
	for (int i = 0; i < (int) ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	
	return 0;
}
