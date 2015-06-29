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
string S;

int func(string arg, int p) {
	int cnt = 0;
	for (int i = 0; i < (int) arg.size() - 1; i++) {
		if (arg[i] != arg[i + 1]) {
			cnt += 1;

			if (cnt == p) {
				int x = i, y = i + 1;
				int len = (int) arg.size();
				
				while (x >= 0 && y < (int) arg.size()) {
					if (arg[x] == arg[y]) {
						break;
					}
					len -= 2;
					x -= 1;
					y += 1;
				}
				return len;
			}
		}
	}
	return INT_MAX;
}

int main(void) {	
	cin >> N >> S;

	cout << min(func(S, 0), func(S, 1)) << endl;
	return 0;
}
