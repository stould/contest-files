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

const Int INF = 1001001001001010010LL;
Int N;
Int up[] = {1LL, 2LL, 3LL, 4LL, 5LL, 6LL, 7LL, 15LL, 23LL, 50LL, 114LL, 330LL, 1330LL, 10591LL, 215970LL, 19464802LL, 16542386125LL, 409477218238718LL};

Int func(Int curr, int best) {
    for (int x = 0; x < best; x++) {
        Int ps = 1;
        for (Int i = 1; curr - i * i * i >= 0; i++) {
            ps = i;
        }
        curr -= ps * ps * ps;
    }
    return curr;
}

int main(void) {
    cin >> N;

    int best = 0;
    
    for (int i = 0; i < 18; i++) {
        if (N >= up[i]) {
            best = i + 1;
        }        
    }
    for (int i = 1; i <= 50; i++) {
        Int ans = func(i, best);
        
        cout << best << " " << i << " " << ans << "\n";
    }
    /*
    for (int x = 1; x <= 200; x++) {
        int best = 0;
        int val = 0;
        for (int y = 1; y <= x; y++) {
            int curr = y;
            int used = 0;
            
            while (curr > 0) {
                for (int i = y; i >= 1; i--) {
                    if (i * i * i <= curr) {
                        curr -= i * i * i;
                        used += 1;
                        break;
                    }
                }
            }
            if (used >= best) {
                best = used;
                val = y;
            }
        }
        cout << x << " " << val << " " << best << "\n";
    }
    */

    return 0;
}
