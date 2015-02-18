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

int P;
string S;

int main(void) {
	for ( ; scanf("%d", &P) == 1 && P != 0; ) {
		cin >> S;

		int ans = 0, in = 0;
		set<char> s;
		for (int i = 0; i < (int) S.size(); i++) {
			if (s.count(S[i])) {
				in -= 1;
			} else {
				if (in < P) {
					s.insert(S[i]);
					in += 1;
				} else {
					ans += 1;
				}	
			}
		}
		if (ans == 0) {
			puts("All customers tanned successfully.");
		} else {
			printf("%d customer(s) walked away.\n", ans / 2);
		}
	}
    return 0;
}
