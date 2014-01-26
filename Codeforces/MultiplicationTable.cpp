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

string func(int x) {
	string ans = "";

	for ( ; x > 0; ) {
		ans += (char) '0' + (x % N);
		x /= N;
	}

	reverse(ans.begin(), ans.end());

	return ans;
}

int main(void) {
	N = in();

	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			printf("%s ", func(i * j).c_str());
		}
		printf("\n");
	}
    return 0;
}
