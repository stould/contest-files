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

const int MAXN = 210;

int T, N;
Int bin[MAXN][MAXN];

int main(void) {
    bin[0][0] = 1LL;

    for (int n = 1; n < MAXN; n++) {
        bin[n][0] = 1;
        bin[n][n] = 1;
	
        for (int k = 1; k < n; k++) {
            bin[n][k] = bin[n - 1][k] + bin[n - 1][k - 1];
        }
    }

    cin >> T;

    while (T--) {
        cin >> N;
        
        Int ans = bin[N - 1][4] + bin[N - 1][3] + bin[N - 1][2] + bin[N - 1][1] + bin[N - 1][0];

        cout << ans << "\n";
    }
    return 0;
}
