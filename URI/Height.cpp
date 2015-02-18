#include <bits/stdc++.h>
<<<<<<< HEAD
 
=======

>>>>>>> 9957ccf786462e42629e4a9da30744014e6e12b2
template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}
<<<<<<< HEAD
 
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
=======

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

int T, N, C[235], P;

int main(void) {
	scanf("%d", &T);
	for ( ; T--; ) {
		scanf("%d", &N);

		memset(C, 0, sizeof(C));

		for (int i = 0; i < N; i++) {
			scanf("%d", &P);
			C[P] += 1;
		}
		for (int i = 20; i <= 230; i++) {
			for (int j = 0; j < C[i]; j++) {
				printf("%d ", i);
			}
		}
		printf("\n");
	}
>>>>>>> 9957ccf786462e42629e4a9da30744014e6e12b2
    return 0;
}
