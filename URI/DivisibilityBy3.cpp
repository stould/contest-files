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

int N, V;

int main(void) {
	while (cin >> N >> V) {
		int s = 0;

		for (int i = 0; i < N; i++) {
			s += (V % 10);
			V /= 10;
		}

		cout << s << " " << ((s % 3 == 0) ? "sim\n" : "nao\n");					 

	}
	return 0;
}
