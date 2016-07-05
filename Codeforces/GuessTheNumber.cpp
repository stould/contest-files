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

int main(void) {
    int L = 1, H = 1000000, M;
    int ans = -1;
    
    while (L <= H) {
        M = L + (H - L) / 2;

        cout << M << endl;
        cout << flush;


        string OT;
        cin >> OT;

        if (OT == ">=") {
            ans = M;
            L = M + 1;            
        } else {
            H = M - 1;

        }
    }

    cout << "! " << ans << endl;
    cout << flush;
    return 0;
}
