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

const int MAXN = 1000006;

int T;
Int N;
int P[MAXN];

int main(void) {
    cin >> T;

    while (T--) {
        cin >> N;

        bool ok = true;
        
        if (N > 3) {
            for (int i = 2; i <= sqrt(N); i++) {
                int cnt = 0;
                while (N % i == 0) {
                    N /= i;
                    cnt += 1;
                }
                if (cnt >= 2) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
