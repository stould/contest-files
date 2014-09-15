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

string S;
int d;

int main(void) {
	cin >> S >> d;

	int ans = 0;
	int iter = 0;

	double s = 0.0;

	for (int i = 0; i < S.size(); i++) {
		if (i < 10) {
			s = (s * 10) + (S[i] - 1);
		} else {

		}
	}
	
	while (true) {
		int N = (int) S.size();

		if (iter == 0) {
			if ((S[N-1] - '0') % 2 == 0) {
				ans = 1 - ans;
			}
			for (int i = N - 1; i >= 0; i--) {
				num = (num * 10) + (S[i] - '0');
				num = (num % d);
			}
		} else {
			if (num % 2 == 0) {
				ans = 1 - ans;
			}
			num = num % d;
		}
		cout << num << "\n";
		if (num <= 0) break;
		iter++;
	}
	
	if (ans == 1) {
		puts("desce sobe");
	} else {
		puts("sobe desce");
	}
		
    return 0;
}
