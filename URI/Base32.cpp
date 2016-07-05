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

uInt N;

string to32(uInt x) {
	string ans = "";

	if (x == 0) {
		ans = "0";
	} else {	
		while (x > 0) {
			int dg = (x % 32);
			x /= 32;
			
			if (dg < 10) {
			ans += char('0' + dg);
			} else {
				ans += char('A' + (dg - 10));
			}
		}
	}
	
	reverse(ans.begin(), ans.end());
	
	return ans;
}

int main(void) {
	while (cin >> N) {
		cout << to32(N) << "\n";

		if (N == 0) break;
	}
	return 0;
}
