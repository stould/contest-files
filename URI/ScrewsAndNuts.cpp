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

int N;
int K;

int main(void) {
	for ( ; cin >> N; ) {
		vector<int> pos;
		for (int i = 0; i < N; i++) {
			int x, y;
			cin >> x >> y;

			for (int j = x; j <= y; j++) {
				pos.push_back(j);
			}
		}
		sort(pos.begin(), pos.end());
		cin >> K;
		int s = 10101010, e = -1;
		for (int i = 0; i < (int) pos.size(); i++) {
			if (pos[i] == K) {
				s = min(s, i);
				e = max(e, i);
			}
		}
		if (e == -1) {
			cout << K << " not found\n";
		} else {
			cout << K << " found from " << s << " to " << e << "\n";
		}
	}
    return 0;
}
