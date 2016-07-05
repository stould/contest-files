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
typedef unsigned uint;

int T, R;
string trump;
string C[5][5];

int main(void) {
	cin >> T;

	while (T--) {
		cin >> trump >> R;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < R; j++) {
				cin >> C[i][j];
			}
		}
	}
	
	return 0;
}
