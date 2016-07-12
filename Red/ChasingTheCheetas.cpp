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

const int MAXN = 100005;
const double INF = 100000000000000.0;

int N;
int T[MAXN], S[MAXN];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
        
    while (cin >> N && N != 0) {
        for (int i = 0; i < N; i++) {
            cin >> T[i] >> S[i];
        }
        double ans = INF;
        
        double l = *max_element(T, T + N), h = INF;

        for (int x = 0; x < 150; x++) {
            double ml = l + (h - l) / 3.0;
            double mr = h - (h - l) / 3.0;

            if (fabs(ml - mr) < 1e-3) {
                break;
            }
            
            double max_l = 0.0;
            double max_r = 0.0;
            double min_l = INF;
            double min_r = INF;
            
            for (int i = 0; i < N; i++) {
                max_l = max(max_l, (ml - T[i]) * S[i]);
                min_l = min(min_l, (ml - T[i]) * S[i]);
                max_r = max(max_r, (mr - T[i]) * S[i]);
                min_r = min(min_r, (mr - T[i]) * S[i]);
            }

            ans = min(ans, max_l - min_l);
            ans = min(ans, max_r - min_r);

            if (max_l - min_l >= max_r - min_r) {
                l = ml;
            } else {
                h = mr;
            }
        }

        cout << fixed << setprecision(3) << ans << endl;
    }
    return 0;
}
