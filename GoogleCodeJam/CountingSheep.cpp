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

int T;
Int N;

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N;

        Int ans = -1;
        vector<int> seen(10);
        
        for (int i = 1; i <= 500; i++) {
            Int now = N * (Int) i;

            while (now > 0) {
                seen[now % 10] = 1;
                now /= 10;
            }

            bool ok = true;

            for (int j = 0; j < 10; j++) {
                if (seen[j] == 0) {
                    ok = false;
                }
            }

            if (ok) {
                ans = N * (Int) i;
                break;
            }
        }
        
        cout << "Case #" << t << ": ";
        
        if (ans == -1) {
            cout << "INSOMNIA\n";
        } else {
            cout << ans << "\n";
        }
    }
    return 0;
}
