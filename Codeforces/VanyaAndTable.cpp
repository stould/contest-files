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
int X0[MAXN], Y0[MAXN], X1[MAXN], Y1[MAXN];

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {		
		cin >> X0[i] >> Y0[i] >> X1[i] >> Y1[i];		
	}

	int ans = 0;

	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			int sum = 0;
			for (int k = 0; k < N; k++) {
				if (X0[k] <= i && X1[k] >= i && Y0[k] <= j && Y1[k] >= j) {
					sum += 1;
				}
			}
			ans += sum;
		}
	}
	
	cout << ans << "\n";
	return 0;
}
