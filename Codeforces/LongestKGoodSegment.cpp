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

const int MAXN = 1000005;

int N, K;
int P[MAXN], cnt[MAXN];

int main(void) {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    
    int l = 0, r = 0, df = 0;
    int ans_l = 0, ans_r = 0;

    while (r < N) {
        cnt[P[r]] += 1;

        if (cnt[P[r]] == 1) {
            df += 1;
        }

        while (l < r && df > K) {
            cnt[P[l]] -= 1;

            if (cnt[P[l]] == 0) df -= 1;

            l += 1;
        }

        if (r - l + 1 > ans_r - ans_l + 1) {
            ans_l = l;
            ans_r = r;
        }

        r += 1;
    }

    cout << ans_l + 1 << " " << ans_r + 1 << "\n";
    
	return 0;
}
