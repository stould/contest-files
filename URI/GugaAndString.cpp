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

int T, M, O, P;
string S;

bool isvowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cout << "Caso #" << t << ":\n";
		
		cin >> S;

		int N = (int) S.size();
		
		cin >> M;

		int v = 0;
		int c = 0;
		
		vector<int> vow, cos;
		vector<int> nvs, ncs;	

		for (int i = 0; i < N; i++) {
			if (isvowel(S[i])) {
				vow.push_back(i);
				nvs.push_back(i);
			} else {
				cos.push_back(i);
				ncs.push_back(i);
			}					
		}

		int VS = (int) vow.size();
		int CS = (int) cos.size();

		for (int i = 0; i < M; i++) {
			cin >> O;

			if (O == 2) {
				if (v > 0) {
					for (int j = 0; j < VS; j++) {
						nvs[(j + v) % VS] = vow[j];
					}
					for (int j = 0; j < VS; j++) {
						vow[j] = nvs[j];
					}					
				}
				if (c > 0) {
					for (int j = 0; j < CS; j++) {
						ncs[(j + c) % CS] = cos[j];
					}
					for (int j = 0; j < CS; j++) {
						cos[j] = ncs[j];
					}
				}
				int pv = 0;
				int pc = 0;

				for (int j = 0; j < N; j++) {
					if (isvowel(S[j])) {
						cout << S[vow[pv++]];
					} else {
						cout << S[cos[pc++]];
					}
				}
				cout << "\n";
				v = c = 0;
			} else {
				cin >> P;
				
				if (O == 0) {
					v += P;
				} else {
					c += P;
				}
			}
		}
	}
    return 0;
}

