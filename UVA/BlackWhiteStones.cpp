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

const Int INF = 10100101010010100LL;

int A, B, N;
string S;

int main(void) {
	for ( ; cin >> A >> B >> S; ) {
		N = S.size();
		
		Int ans = 0;
		
		for (int i = 0; i < N; i++) {
			if (S[i] != 'B') {
				int close = -1;
				for (int j = i + 1; j < N; j++) {
					if (S[j] == 'B') {
						close = j;
						break;
					}
				}
				if (close == -1) {
					break;					
				}
				//cout << i << " " << close << "\n";
				ans += min(A, (A - B) * (close - i));
				swap(S[i], S[close]);
			}
			cout << S << " " << ans << endl;
		}
		
		cout << ans << "\n";
	}
    return 0;
}
