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

int N, K;
string S;
int cnt[MAXN][2];


int main(void) {
    cin >> N >> K >> S;

    for (int i = 0; i < N; i++) {
        cnt[i][S[i] - 'a'] += 1;

        if (i > 0) {
            cnt[i][0] += cnt[i - 1][0];
            cnt[i][1] += cnt[i - 1][1];
        }
    }

    int l = 0, h = N, m;
    int ans = 1;

    for (int i = 0; i < N; i++) {
        int j = i;
        int s = 0;
        
        while (j < N && S[i] == S[j]) {
            j += 1;
            s += 1;
        }

        ans = max(ans, s);
        i = j;
    }
    
    while (l <= h) {
        m = (l + h) / 2;

        bool valid = false;
        
        for (int i = m; i < N; i++) {
            int ia = cnt[i][0];
            int ib = cnt[i][1];

            if (i - m - 1 >= 0) {
                ia -= cnt[i - m - 1][0];
                ib -= cnt[i - m - 1][1];
            }

            if (min(ia, ib) <= K) {
                valid = true;
            }
        }

        if (valid) {
            ans = m + 1;
            l = m + 1;
        } else {
            h = m - 1;
        }
    }

    cout << ans << "\n";
    
    return 0;
}
