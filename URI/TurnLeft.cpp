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

int N;

char str[1010];

char* P = "NLSO";

int fix(int& p, int x) {
    if (x > 0) {
        p = (p + 1) % 4;
    } else {
        p = (((p - 1) % 4) + 4) % 4;
    }
}

int main(void) {
    int i;
    for ( ; scanf("%d", &N) == 1 && N != 0; ) {
        scanf("%s", str);

        int p = 0;

        for (i = 0; i < N; i++) {
            if (str[i] == 'D') fix(p, 1);
            else fix(p, -1);
        }

        printf("%c\n", P[p]);
    }

    return 0;
}
