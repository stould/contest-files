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

int N, D, R;
int A[110];
int B[110];

int main(void) {
    int i;
    for ( ; scanf("%d%d%d", &N, &D, &R) == 3 && (N + D + R != 0); ) {
        for (i = 0; i < N; i++) A[i] = in();
        for (i = 0; i < N; i++) B[i] = in();

        sort(A, A + N);
        sort(B, B + N);

        int ans = 0;

        for (i = 0; i < N; i++) {
            ans += max(0, (A[i] + B[N - i - 1] - D) * R);
        }

        printf("%d\n", ans);
    }

    return 0;
}
