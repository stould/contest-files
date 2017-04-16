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

int P[10];

int func(int p) {
	vector<int> ch;

	int a = P[0] + P[1] + P[2] + P[3] + p;
	int b = P[0] + P[3] + P[4] + p;
	int c = P[0] + P[1] + P[5] + p;
	
	return min(a, min(b, c));
}

int main(void) {
	for (int i = 0; i < 6; i++) {
		cin >> P[i];
	}

	for (int i = 0; i <= 200; i++) {
		if (func(i) >= 0) {
			cout << i << "\n";
			break;
		}
	}
	return 0;
}
