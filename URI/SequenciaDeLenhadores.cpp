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
	cout << "Lumberjacks:\n";
	for (int i = 0; i < N; i++) {
		int cur, last;

		int A = 0, B = 0;

		set<int> s;

		for (int j = 0; j < 10; j++) {
			cin >> cur;
			s.insert(cur);
			if (j > 0) {
				if (cur >= last) {
					A += 1;
				} 
				if (cur <= last) {
					B += 1;
				}
			}
			last = cur;
		}

		if (s.size() == 10 && (A == 9 || B == 9)) {
			cout << "Ordered\n";
		} else {
			cout << "Unordered\n";
		}
	}

    return 0;
}
