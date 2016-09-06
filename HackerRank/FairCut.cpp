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

const Int INF = 1001000100010010LL;
const int MAXN = 3010;

Int N, K, P[MAXN];

//Inside interval [a, b]
Int funcI(int a, int b) {
    int L = b - a + 1;
    
    if (L == 1) return 0;
    Int ans = 0;
    Int whole = 0;

    for (int i = 0; i < N; i++) {
        if (i < a || i > b) {
            whole += P[i];
        }
    }

    for (int i = a; i <= b; i++) {
        Int a = P[i];
        cout << "DEB " << a << " " << whole << "\n";
        ans += abs(a - whole);
    }

    return ans;
}

int main(void) {
    for ( ; cin >> N >> K; ) {				
        for (int i = 0; i < N; i++) {
            cin >> P[i];
        }

        sort(P, P + N);
        
        Int ans = INF;

        for (int i = 0; i + K - 1 < N; i++) {
            Int now = funcI(i, i + K - 1);
            cout << i << " " << i + K - 1 << " " << now << "\n";
            if (now < ans) {
                ans = now;
            }
        }    

        printf("%lld\n", ans);
    }
    return 0;
}
