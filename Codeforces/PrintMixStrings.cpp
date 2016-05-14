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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

int T;
string A, B;
set<string> st;

void func(int l, int r, string arg) {
	if (l == (int) A.size() && r == (int) B.size()) {
		st.insert(arg);
	} else {
		if (l + 1 <= (int) A.size()) {
			func(l + 1, r, arg + A[l]);
		}
		if (r + 1 <= (int) B.size()) {
			func(l, r + 1, arg + B[r]);
		}
	}
}
int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> A >> B;

		st.clear();

		func(0, 0, "");

		for (const auto& c: st) {
			cout << c << "\n";
		}
		cout << "\n";
	}

	return 0;
}
