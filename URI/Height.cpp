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
 
int T, N, C[235], P;


inline void rd(int &x) {
    register int c = getchar_unlocked();

    x = 0;

    int neg = 0;

    for (; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if (c=='-') {
        neg = 1;
        c = getchar_unlocked();
    }

    for ( ; c>47 && c<58 ; c = getchar_unlocked()) {
        x = (x<<1) + (x<<3) + c - 48;
    }

    if (neg) {
        x = -x;
    }
}
 

int main(void) {
	rd(T);
    for (int t = 1; t <= T; t++) {
		rd(N);
 
		for (int i = 20; i <= 230; i++) C[i] = 0;
 
        for (int i = 0; i < N; i++) {
			rd(P);
			C[P] += 1;			
        }
		bool ok = false;
		for (int i = 20; i <= 230; i++) {
            for (int j = 0; j < C[i]; j++) {
				if (ok) {
					printf(" ");
				}
				ok = true;

                printf("%d", i);
            }
        }
		printf("\n");
    }
    return 0;
}
