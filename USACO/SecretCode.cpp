#include <string>
#include <set>
#include <iostream>
#include <cstdio>

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
int N;

int func(string P) {
	if (P.size() > N) {
		return 0;
	} else if (P == S) {
		return 1;
	} else {
		string PL = P.substr(1, P.size());
		string PR = P.substr(0, P.size() - 1);

		return func(P + PL) + func(P + PR) + func(PL + P) + func(PR + P);
	}
}

int main(void) {
	freopen("scode.in", "r", stdin);
	freopen("scode.out", "w", stdout);

	cin >> S;
	N = (int) S.size();

	int ans = 0;

	set<string> St;

	for (int i = 0; i < N; i++) {
		for (int j = 2; j <= N - i; j++) {
			St.insert(S.substr(i, j));
		}
	}
	
	for (set<string>::iterator it = St.begin(); it != St.end(); it++) {
		if (*it == S) continue;
		ans += func(*it);
	}

	printf("%d\n", ans);

    return 0;
}
