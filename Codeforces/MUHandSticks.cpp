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

int P[10];

int main(void) {
	int t;
	for (int i = 0; i < 6; i++) {
		cin >> t;
		P[t] += 1;
	}

	for (int i = 1; i <= 9; i++) {
		if (P[i] >= 4) {
			P[i] -= 4;
			vector<int> s;
			for (int j = 1; j <= 9; j++) {
				while (P[j] > 0) {
					s.push_back(j);
					P[j] -= 1;
				}				
			}
			if (s[0] < s[1]) {
				cout << "Bear\n";
			} else {
				cout << "Elephant\n";
			}
			return 0;
		}
	}

	cout << "Alien\n";

    return 0;
}
