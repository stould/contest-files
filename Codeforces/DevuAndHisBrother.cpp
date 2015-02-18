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

int N, M, C;
int P[MAXN];

int main(void) {
	cin >> N >> M;

	priority_queue<int, vector<int>, greater<int> > q;

	for (int i = 0; i < N; i++) {
		cin >> C;
		q.push(C);
	}

	for (int i = 0; i < M; i++) {
		cin >> P[i];
	}

	sort(P, P + M);

	Int ans = 0LL;

	for (int i = 0; i < M; i++) {
		int now = q.top();
		q.pop();



		if (P[i] > now) {
			ans += (Int) (P[i] - now);			
			now += P[i] - now;
		}

		q.push(now);
	}

	cout << ans << "\n";

    return 0;
}
