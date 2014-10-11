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

const int MAXN = 100005;

int N;
pair<Int, Int> P[MAXN];
Int wait[MAXN];

int main(void) {
	for ( ; cin >> N; ) {
		for (int i = 0; i < N; i++) {
			cin >> P[i].first >> P[i].second;
			wait[i] = 0LL;
		}
		sort(P, P + N);

		Int sum = 0LL;
		Int ans = 0LL;

		for (int i = 0; i < N; i++) {
			wait[i] = P[i].first + sum;
			sum += P[i].second;

			printf("%lld %lld\n", wait[i], sum);

			ans += sum - wait[i];
		}

		cout << ans << "\n";

		
	}
    return 0;
}
