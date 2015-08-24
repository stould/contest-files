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

const int MAXN = 100005;

int NA, NB, K, M;
Int PA[MAXN], PB[MAXN];

int main(void) {
	cin >> NA >> NB >> K >> M;

	for (int i = 0; i < NA; i++) {
		cin >> PA[i];
	}
	for (int i = 0; i < NB; i++) {
		cin >> PB[i];
	}
	K -= 1;
	M -= 1;

	if (PA[K] < PB[NB - 1 - M]) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	
	
	return 0;
}
