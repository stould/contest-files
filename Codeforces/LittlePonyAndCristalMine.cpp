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

int main(void) {
	cin >> N;

	
	for (int i = 0; i < N; i++) {
		int now = min((i + 1), N - i) * 2 - 1;		
		int start = (N - 1) / 2 - min(i, N - i - 1);
		//cout << now << " " << start << "\n";
		for (int j = 0; j < N; j++) {
			if (now > 0) {
				if (j > start - 1) {
					cout << "D";
					now -= 1;
				} else {
					cout << "*";
				}
			} else {
				cout << "*";
			}
		}
		cout << "\n";
	}
	return 0;
}
