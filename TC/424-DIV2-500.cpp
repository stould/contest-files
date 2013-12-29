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

class ProductOfDigits {
public:
	int smallestNumber(int);
};

const int INF = 10010100;
int ans;
bool done;

void rec(int num, int digit, int goal) {
	if (done) return;
	if (num > goal || goal % num != 0) return;
	if (num == goal) {
		ans = min(ans, digit);
		if (goal == 1) ans = 1;
		done = true;
	} else {
		int i;
		for (i = 9; i >= 2; i--) {
			rec(num * i, digit + 1, goal);
		}
	}
}

int ProductOfDigits::smallestNumber(int N) {
	ans = INF;
	done = false;
	rec(1, 0, N);
	
	return ans == INF ? -1 : ans;
}

//Powered by [KawigiEdit] 2.0!