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

const int MAXN = 200005;

Int N, K;
Int P[MAXN];
map<Int, Int> seenF, seenS;
Int bin[MAXN][5];

int main(void) {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	bin[0][0] = 1;
	
	for (int n = 1; n < MAXN; n++) {
		bin[n][0] = 1;
		if (n < 5) {
			bin[n][n] = 1;
		}
		
		for (int k = 1; k < 3; k++) {
			bin[n][k] = bin[n - 1][k] + bin[n - 1][k - 1];
		}
	}


	Int ans = 0LL;

	if (K == 1) {		
		for (int i = N - 1; i >= 0; i--) {
			ans += bin[seenF[P[i]]][2];							
			seenF[P[i]] += 1;
		}
	} else {
		for (int i = N - 1; i >= 0; i--) {
		    if (P[i] == 0) continue;
			if (seenF[P[i] * K]) {
				seenS[P[i]] += seenF[P[i] * K];
			}
			seenF[P[i]] += 1;
			ans += seenS[P[i] * K];
			//cout << i << " " << ans << "\n";
		}
		seenF.clear();
		for (int i = N - 1; i >= 0; i--) {
		    if (P[i] == 0) {
    			ans += bin[seenF[P[i]]][2];							
	    		seenF[P[i]] += 1;
	    	}
		}
	}

	cout << ans << "\n";
	
	return 0;
}
