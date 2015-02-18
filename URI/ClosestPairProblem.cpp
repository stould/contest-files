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
const double INF = 10010101010010.0;
int N;

pair<int, int> P[MAXN];

int main(void) {
	for ( ; scanf("%d", &N) == 1 && N != 0; ) {
		for (int i = 0; i < N; i++) {
			int x = in(), y = in();

			P[i] = make_pair(x, y);
		}
		sort(P, P + N);

		priority_queue<pair<double, int> > q;
		double d = INF;

		for (int i = 0; i < N; i++) {
			if (i == 0) {
				q.push(make_pair(INF, 0));
			} else {
				vector<pair<double, int> > buff;
				for ( ; !q.empty(); ) {
					double dst = hypot(P[i].first - P[q.top().second].first, P[i].second - P[q.top().second].second);
					d = min(d, dst);
					buff.push_back(make_pair(dst, q.top().second));
					q.pop();
				}
				for (int i = 0; i < (int) buff.size(); i++) {
					q.push(buff[i]);
				}

				for ( ; !q.empty() && q.top().first > d; ) {
					q.pop();
				}
			}
		}

		if (d <= 10000.0) {
			printf("%.4lf\n", d);
		} else {
			printf("INFINITY\n");
		}
	}
    return 0;
}
