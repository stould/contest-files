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

string A, B;

int func(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	} else {
		return c - 'A' + 10;
	}
}

Int to10(string x) {
	int N = (int) x.size(); 
	Int ans = 0;
	Int base = 1LL;

	for (int i = N - 1; i >= 0; i--) {
		int v = func(x[i]);
		ans += base * v;

		base *= 36LL;
	}

	return ans;
}

string to36(Int x) {
	string ans = "";

	while (x > 0) {
		int v = x % 36;
		
		if (v <= 9) {
			ans += '0' + v; 
		} else {
			ans += 'A' + v - 10;
		}
		
		x /= 36;		   
	}

	reverse(ans.begin(), ans.end());

	return ans;
}

int main(void) {
	for ( ; cin >> A >> B && A != "0" && B != "0"; ) {
		Int aa = to10(A), bb = to10(B);
		
		cout << to36(aa + bb) << "\n";
	}

    return 0;
}
