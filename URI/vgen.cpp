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

void gen() {
	srand(time(NULL));

	for (int x = 0; x < 30; x++) {
		int n = 1 + rand() % 7;
		int t = 1 + rand() % 10000;
		
		cout << n << " " << t << "\n";
		for (int i = 0; i < n; i++) {
			cout << 1 + rand() % 15 << " ";
		}
		cout << "\n";
	}
	cout << "0 0\n";
}

int main(void) {
	gen(); return 0;
}
