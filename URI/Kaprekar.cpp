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

int T, N;

int hi(int x) {
	string s = to_string(x);

	while (s.size() != 4) {
		s += "0";
	}
	
	sort(s.rbegin(), s.rend());

	return stoi(s);
}

int lo(int x) {
	string s = to_string(x);

	while (s.size() != 4) {
		s += "0";
	}

	sort(s.begin(), s.end());

	return stoi(s);
}

int func(int X) {
	int cnt = 0;

	while (X != 6174) {
		int h = hi(X);
		int l = lo(X);
		
		if (X == h - l) {
			cnt = -1;
			break;
		}
		
		X = h - l;		
		cnt = cnt + 1;
	}
	return cnt;
}

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;

		cout << "Caso #" << t << ": " << func(N) << "\n";
	}
    return 0;
}
