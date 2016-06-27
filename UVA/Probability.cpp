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
int A, B, S;

int main(void) {
    cin >> T;

    while (T--) {
        cin >> A >> B >> S;

        if (A < B) {
            swap(A, B);
        }
        
        double cnt = 0;

        for (int i = 0; i <= A; i++) {
            for (int j = 0; j <= B; j++) {
                if (abs(i) * abs(j) > S) {
                    cnt += 1;
                }
            }
        }
        
        for (int i = 1; i <= A; i++) {
            //int added = max(0, (int) ((int) ceil(S / i)));
            //cout << i << " " << max(0, B - added) << endl;
            //cnt += 4 * max(0, B - added);
        }
        cout << cnt << " " << A * B << endl;
        double ans = cnt;
        ans *= 100.0;
        ans /= A * B;
        cout << fixed << setprecision(6) << ans << "\n";
        //cout << fixed << setprecision(6) << (8.0 * cnt) / (double) ((2.0 * A + 1) * (2.0 * B + 1)) << "%\n";
    }
    return 0;
}
