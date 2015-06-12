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

int main(void) {
	while (cin >> S) {
		double sum = 0.0;
		double cnt = 0.0;

		int curr = 0;
		
		for (int i = 0; i < (int) S.size(); i++) {
			curr = curr * 10 + (S[i] - '0');

			if (i + 1 < (int) S.size() && S[i + 1] == '0') continue;
			
			if (curr >= 1 && curr <= 10) {
				sum += curr;
				cnt += 1;
				curr = 0;
			}
		}
		cout << fixed << setprecision(2) << sum / cnt << "\n";
	}
	return 0;
}
