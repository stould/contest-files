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

const int INF = 10101010;

int test;
string S, T;
int N;

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> test;
	
	for (int t = 1; t <= test; t++) {
		cin >> S >> T;
		N = (int) S.size();

		int ans = 0, ones = 0;
		
		for (int i = 0; i < N; i++) {
			if (S[i] == T[i]) {
				continue;
			}
			for (int j = 0; j < N; j++) {				
				if (S[i] == T[j] && S[j] == T[i]) {
					swap(S[i], S[j]);
					ans += 1;
					break;
				}
			}
		}

		for (int i = 0; i < N; i++) {
			if (T[i] == '1') {
				ones += 1;
			}
			if (S[i] == '1') {
				ones -= 1;
			}
		}
		for (int i = 0; i < N; i++) {
			if (ones > 0 && S[i] == '0' && T[i] == '1') {
				ones -= 1;
				ans += 1;
				S[i] = '1';
			}
		}
		for (int i = 0; i < N; i++) {
			if (ones > 0 && S[i] != '1' && T[i] == '1') {
				ones -= 1;
				ans += 1;
				S[i] = '1';
			}
		}

		for (int i = 0; i < N; i++) {
			if (S[i] == '?') {
				ans += 1;
				S[i] = '0';				
			}
		}
		for (int i = 0; i < N; i++) {
			if (S[i] == T[i]) {
				continue;
			}
			for (int j = 0; j < N; j++) {				
				if (S[i] == T[j] && S[j] == T[i]) {
					swap(S[i], S[j]);
					ans += 1;
					break;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			if (S[i] != T[i]) {
				ans = -1;
				break;
			}
		}
		cout << "Case " << t << ": " << ans << "\n";
	}
    return 0;
}
