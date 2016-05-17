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

const int MAXN = 16;

int T, N;
int P[MAXN][MAXN];
int deg[MAXN];

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N;

        memset(P, 0, sizeof(P));
        memset(deg, 0, sizeof(deg));

        for (int i = 1; i < N; i++) {
            int A, B, C;
            cin >> A >> B >> C;

            A -= 1;
            B -= 1;

            deg[A] += 1;
            deg[B] += 1;

            P[A][B] = P[B][A] = C;
        }
    }
    return 0;
}
