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

int A, B;

int main(void) {
	while (scanf("%d:%d", &A, &B) == 2) {
		
		B += 60;
		if (B >= 60) {
			A += 1;
			B %= 60;
		}
		
		int at = 0;
		
		if (A >= 8) {
			at += (A - 8) * 60 + B;
		}
		
		cout << "Atraso maximo: " << at << endl;
	}
	return 0;
}
