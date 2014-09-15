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

int C, N;
int P[100005], T[100005];

int main(void) {
	for ( ; cin >> C >> N; ) {
		bool ok = true;

		int p = C / N;

		memset(P, 0, sizeof(P));

		for (int i = 0; i < N; i++) {
			cin >> T[i];
			P[T[i]] += 1;
		}

		for (double i = T[0] + 0.5, cnt = 0; cnt < N; cnt += 1) {			
			int seen = 0;
			for (int j = 0; j < p; j++) {
				if (i >= C) {
					i = (i - C);
				}
				seen += P[(int) floor(i)];									
				i += 1;
			}

			if (seen != 1) {
				ok = false;
				break;
			} 
		}
		
		if (ok) {
			cout << "S\n";
		} else {
			cout << "N\n";
		}
	}
	
    return 0;
}
