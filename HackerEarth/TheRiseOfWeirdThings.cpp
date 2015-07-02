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

	vector<int> od, ev;
	
	for (int i = 0; i < N; i++) {
		int c;
		cin >> c;

		if (c % 2 == 0) {
			ev.push_back(c);
		} else {
			od.push_back(c);
		}
	}
	sort(ev.begin(), ev.end());
	sort(od.begin(), od.end());
	
	for (int i = 0; i < (int) ev.size(); i++) {
		cout << ev[i] << " ";
	}
	cout << accumulate(ev.begin(), ev.end(), 0) << " ";
	for (int i = 0; i < (int) od.size(); i++) {
		cout << od[i] << " ";
	}
	cout << accumulate(od.begin(), od.end(), 0) << "\n";
	
	return 0;
}
