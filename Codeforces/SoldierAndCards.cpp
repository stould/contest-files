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

int N, K1, K2;
list<int> p1, p2;

int main(void) {
	cin >> N;

	cin >> K1;

	for (int i = 0; i < K1; i++) {
		int A;
		cin >> A;
		p1.push_back(A);
	}
	
	cin >> K2;

	for (int i = 0; i < K2; i++) {
		int A;
		cin >> A;
		p2.push_back(A);		
	}

	set<pair<list<int>, list<int> > > game_state;

	int round = 0, w = 0, done = 1;

	for ( ; ; ) {		
		int c1 = p1.front();
		int c2 = p2.front();

		if (c1 > c2) {
			p1.pop_front();
			p2.pop_front();
			p1.push_back(c2);
			p1.push_back(c1);
		} else {
			p1.pop_front();
			p2.pop_front();
			p2.push_back(c1);
			p2.push_back(c2);
		}

		round += 1;
		
		if (p1.empty()) {
			w = 2;
			break;
		}
		if (p2.empty()) {
			w = 1;
			break;
		}
		if (game_state.count(make_pair(p1, p2))) {
			done = false;
			break;
		} else {
			game_state.insert(make_pair(p1, p2));
		}
	}

	if (done) {
		cout << round << " " << w << "\n";
	} else {
		cout << "-1\n";
	}
	
    return 0;
}
