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
int x[1000005];
int mem[5050];

int main(void) {
    int i;

    memset(x, 0, sizeof(x));

    for ( ; scanf("%d", &N) == 1 && N != 0; ) {
        int ans = 0;
        int id;

        for (i = 0; i < N; i++) {
            mem[i] = in();

            x[mem[i]] += 1;

            if (x[mem[i]] > ans) {
                ans = x[mem[i]];
                id = mem[i];
            }
        }

        for (i = 0; i < N; i++) x[mem[i]] = 0;
        printf("%d\n", id);
    }

    return 0;
}
