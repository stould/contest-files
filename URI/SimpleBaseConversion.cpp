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

string S;

int pos(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	} else if (c >= 'A' && c <= 'F') {
		return c - 'A' + 10;
	} else {
		return c - 'a' + 10;
	}
}

int fromHex(string s) {
	int ans = 0;
	int base = 1;

	for (int i = s.size() - 1; i >= 0; i--) {
		ans += base * pos(s[i]);
		base *= 16;
	}
	return ans;
}

int toInt(string s) {
	int ans = 0;
	int base = 1;

	for (int i = s.size() - 1; i >= 0; i--) {
		ans += base * pos(s[i]);
		base *= 10;
	}
	return ans;
}

int main(void) {
	for ( ; cin >> S; ) {
		if (S.size() > 2 && S[1] == 'x') {
			printf("%d\n", fromHex(S.substr(2, S.size() - 2)));
		} else {
			int ans = toInt(S);
			if (ans < 0) {
				break;
			}
			printf("0x%X\n", ans);
		}
	}
    return 0;
}
