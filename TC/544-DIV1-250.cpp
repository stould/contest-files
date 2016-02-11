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

class TheBrickTowerEasyDivOne {
public:
	int find(int, int, int, int);
};

int TheBrickTowerEasyDivOne::find(int redCount, int redHeight, int blueCount, int blueHeight) {
	int mx = min(redCount + 1, blueCount + 1);
	
	chmin(redCount,  mx);
	chmin(blueCount, mx);
	
	if (blueCount > redCount) {
		swap(blueCount,  redCount);
		swap(blueHeight, redHeight);
	}
	
	int ans = (blueCount + 1) * 3 - 2;
	
	if (redCount == blueCount) {
		ans -= 1;
	}
	
	if (redHeight == blueHeight) {
		ans -= min(redCount, blueCount);
	}
	
	return ans;
}

//Powered by [KawigiEdit] 2.0!
