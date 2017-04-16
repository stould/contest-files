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

const int MAXN = 1000;

int N;
int P[MAXN];

int main(void) {
    cin >> N;

    int ia = 0;
    int ib = 0;

    for (int i = 0; i < N; i++) {
        cin >> P[i];

        if (P[i] == 1) {
            ia = i;
        }
        if (P[i] == N) {
            ib = i;
        }
    }

    int ans = 0;
    
    if (ia != 0) {
        chmax(ans, ib);
    }
    if (ib != 0) {
        chmax(ans, ia);
    }
    if (ia != N - 1) {
        chmax(ans, N - 1 - ib);
    }
    if (ib != N - 1) {
        chmax(ans, N - 1 - ia);
    }

    if (ans == 0) {
        ans = N - 1;
    }
    
    cout << ans << "\n";
    return 0;
}
