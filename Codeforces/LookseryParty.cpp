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

const int MAXN = 110;

int N;
string S[MAXN];
int P[MAXN];

int main(void) {
	cin >> N;

	bool zero = true;
	
	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> P[i];
		if (P[i] != 0) {
			zero = false;
		}
	}

	if (zero) {
		cout << "0\n";
	} else {
		bool ok = false;
		int vs[MAXN];

		memset(vs, 0, sizeof(vs));
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (S[i][j] == '1') {
					vs[j] -= 1;
				}
			}
			for (int j = 0; j < N; j++) {
				if (P[j] != vs[j]) {
					ok = true;

					cout << i + 1 << "\n";
					
					for (int j = 0; j < i; j++) {
						cout << j << " ";
					}
					goto end;
				}
			}
		}
	end:;
		if (!ok) {
			cout << -1 << "\n";
		}
	}


	return 0;
}
