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

int N, K;

struct event {
	int t, id;
	bool in;

	event(){}
	event(int tt, int iid, bool iin) {
		t = tt;
		id = iid;
		in = iin;
	}

	bool operator<(const event& e) const {
		return t < e.t;
	}
};

int main(void) {
	for ( ; cin >> N >> K && N + K != 0; ) {
		vector<event> ev;
		for (int i = 0; i < N; i++) {
			int e, s;
			cin >> e >> s;
			event a(e, i, true);
			event b(s, i, false);

			ev.push_back(a);
			ev.push_back(b);
		}
		sort(ev.begin(), ev.end());
		bool ok = true;
		int in_queue = 0, on_top = -1;
		stack<int> st;

		for (int i = 0; ok && i < (int) ev.size(); i++) {
			if (ev[i].in) {					
				if (in_queue + 1 > K) {
					ok = false;
				} else {
					in_queue += 1;
					on_top = ev[i].id;
					st.push(ev[i].id);
				}
			} else {
				if (on_top != ev[i].id) {
					ok = false;
				} else {
					if (in_queue) {
						in_queue -= 1;
						st.pop();
					}
					if (in_queue) {
						on_top = st.top();
					}
				}
			}
		}
	
		if (ok) {
			cout << "Sim\n";
		} else {
			cout << "Nao\n";
		}
	}
    return 0;
}
