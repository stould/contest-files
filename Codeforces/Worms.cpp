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

const int MAXN = 100005;

int N, M;
Int Q;
int A[MAXN];
Int S[MAXN];

int main(void) {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		S[i] = A[i];
		if (i > 0) S[i] += S[i - 1];
	}
	cin >> M;
	
	for ( ; M--; ) {
		cin >> Q;
		int l = 0, h = N, m;
		int ans = -1;
		
		for ( ; l <= h; ) {
			m = (l + h) / 2;
			
			Int Lb = S[m] - A[m] + 1;
			
			if (Q >= Lb) {
				if (S[m] >= Q) {
					ans = m;
				}
				l = m + 1;  
			} else {
				h = m - 1;
			}
		} 
		cout << ans + 1 << "\n";
	}
	
	return 0;
}
