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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned uint;

int T;
Int N, A, B;

int main(void) {
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N >> A >> B;

		Int base = 1;

		for (int i = 0; i < N; i++) {
			base *= 2LL;
		}

		int ans = 0;

		queue<deque<Int> > q;

		deque<Int> dq;
		dq.push_back(base);

		q.push(dq);

		while (!q.empty()) {
			deque<Int> now = q.front();
			q.pop();

			while (!now.empty() && now.back() <= A) {
				A -= now.back();
				now.pop_back();
			}
			while (!now.empty() && now.back() <= B) {
				B -= now.back();
				now.pop_back();
			}
			if (!now.empty()) {
				Int curr = now.back();
				now.pop_back();

				if (curr / 2 != 0) {
					now.push_back(curr / 2);
					now.push_back(curr / 2);
				}
				ans += 1;
				q.push(now);
			}
		}

		cout << ans << "\n";
	}
	return 0;
}
