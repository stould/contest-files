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

int N, Q, A;
int P[110];

int main(void) {
	scanf("%d%d%d", &N, &Q, &A);

	for (int i = 0; i < N; i++) {
		scanf("%d", &P[i]);
	}

	sort(P, P + N);
	reverse(P, P + N);
	
	priority_queue<int, vector<int>, greater<int> > q;
	
	for (int i = 0; i < N; i++) {
		if (q.size() < 3) {
			q.push(P[i]);
		} else {
			int s = q.top();
			q.pop();
			q.push(s + P[i]);
		}
		cout << i << " "<< q.top() << endl;
	}

	double ans = 0.0;
	
	while (!q.empty()) {
		int s = q.top();
		q.pop();

		if (s > Q) {
			ans += A * (s - Q) / 100.0;
		}
	}

	printf("%.2lf\n", ans);

	
    return 0;
}
