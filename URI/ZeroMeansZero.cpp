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

Int A, B;

int main(void) {
	while (cin >> A >> B) {
		if (A == 0 && B == 0) break;
		
		Int ans = A + B;
		string st = "";
		
		while (ans > 0) {
			char dg = char('0' + (ans % 10));
			ans /= 10;

			if (dg != '0') {
				st = dg + st;
			}			
		}
		cout << st << "\n";
	}
	return 0;
}
