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

int main(void) {
	cin >> N;

	set<int> now;
	int ans = 0;
	list<pair<char, int> > order;
	list<pair<char, int> >::iterator it;
	
	for (int i = 0; i < N; i++) {
		char C;
		int P;
		
		cin >> C >> P;

		order.push_back(make_pair(C, P));

		if (C == '+') {
			now.insert(P);
		} else {
			if (!now.count(P)) {
				order.push_front(make_pair('+', P));
			}
			now.erase(P);
		}
	}

	now.clear();
	
	for (it = order.begin(); it != order.end(); it++) {		
		if (it->first == '+') {
			now.insert(it->second);
		} else {
			now.erase(it->second);
		}
		ans = max(ans, (int) now.size());
	}

	cout << ans << "\n";
	return 0;
}
