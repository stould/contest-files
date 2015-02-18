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

int N, P[1010];

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}
	
	int ans = 0;
	bool first = true;
	
	int block = 0;

	for (int i = 0; i < N; i++) {
		if (P[i] == 1) {
			block += 1;
			ans += 1;
			int j = i + 1;

			while (j < N && P[j] == 1) {
				j += 1;
				ans += 1;
			}			

			i = j - 1;
		}
	}

	ans += max(0, block - 1);

	cout << ans << "\n";
	
    return 0;
}
