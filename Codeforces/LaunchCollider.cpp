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

const int MAXN = 200005;
const Int INF = 100000000000LL;

int N;
string S;
Int P[MAXN];

int main(void) {
    cin >> N >> S;

    Int ans = INF;
    Int lr = -1;
    
    
    for (int i = 0; i < N; i++) {
        cin >> P[i];

        if (S[i] == 'R') {
            lr = P[i];
        } else {
            if (lr != -1) {
                chmin(ans, (P[i] - lr) / 2);
            }
        }
    }
    if (ans >= INF) {
        ans = -1;
    }
    cout << ans << "\n";

    
    return 0;    
}
