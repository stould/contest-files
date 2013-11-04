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

int P[15];
int I[15];

int pi = 0, pp = 0;

int main(void) {
    int i, j;

    for (i = 0; i < 15; i++) {
        int x = in();

        if (x % 2 == 0) {
            P[pp++] = x;

            if (pp == 5) {
                for (j = 0; j < 5; j++) {
                    printf("par[%d] = %d\n", j, P[j]);
                }
                pp = 0;
            }
        } else {
            I[pi++] = x;

            if (pi == 5) {
                for (j = 0; j < 5; j++) {
                    printf("impar[%d] = %d\n", j, I[j]);
                }
                pi = 0;
            }
        }
    }

    for (j = 0; j < pi; j++) {
        printf("impar[%d] = %d\n", j, I[j]);
    }
    for (j = 0; j < pp; j++) {
        printf("par[%d] = %d\n", j, P[j]);
    }

    return 0;
}
