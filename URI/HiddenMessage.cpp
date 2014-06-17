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

int N;
string S;

int main(void) {
	cin >> N;

	cin.ignore();
	for ( ; N--; ) {
		getline(cin, S);

		string ans = "";

		for (int i = 0; i < (int) S.size(); i++) {
			if (S[i] >= 'a' && S[i] <= 'z') {
				ans += S[i];

				bool ok = false;

				while (i < (int) S.size()) {
					//					cout << S[i] << " ";
					if (S[i] >= 'a' && S[i] <= 'z') {
						if (ok) {
							break;
						}
					} else {
						ok = true;
					}	
					i += 1;
				}
				i--;
				//				cout << "\n";
			}
		}

		cout << ans << "\n";
	}
    return 0;
}
