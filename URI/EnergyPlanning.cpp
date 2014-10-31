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

int N, A, B, C, D;
char buff[505];
int main(void) {
	cin >> N;

	for ( ; N--; ) {
		cin >> A >> B >> C >> D;

		double rate = (D - B) / (double) (C - A);

		sprintf(buff, "%.3lf", rate);

		string ans = string(buff);

		ans[ans.size() - 4] = ',';

		cout << ans.substr(0, ans.size() - 1) << "\n";
	}
    return 0;
}
