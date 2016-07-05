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

using namespace std;

typedef long long Int;
typedef unsigned uint;

class MarbleDecoration {
public:

	int maxLength(int, int, int);
};

int func(int A, int B) {
	if (A == B) {
		return A + B;
	} else  if (A < B) {
		return 2 * A + 1;
	} else {
		return 2 * B + 1;
	}
}

int MarbleDecoration::maxLength(int R, int G, int B) {
	return max(func(R, G), max(func(R, B), func(G, B)));
}

//Powered by [KawigiEdit] 2.0!
