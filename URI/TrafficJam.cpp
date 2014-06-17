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

int A, B, N;

int main(void) {
	for ( ; cin >> N && N != 0; ) {
		double ans = 0.0, vel = 0.0;
		int last = 0;
		
		for (int i = 0; i < N; i++) {
			cin >> A >> B;

			for (int i = last; i < A && vel < 0.0; i++) {
				ans += vel;
				vel -= 2.0;
			}

			for (int i = A; i < B; i++) {
				vel = min(vel + 1.0, 10.0);
				ans += vel;
			}
			last = B;			
		}
		cout << fixed << setprecision(2) << ans << "\n";
	}
    return 0;
}
