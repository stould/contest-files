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

int N, M;
Int dp[15][15][1 << 10];
int seen[15][15][1 << 10];
int lenN, lenM;

int getLen(int x) {
    int ans = 0;

    if (x == 0) return 1;
       
    while (x > 0) {
        x /= 7;
        ans += 1;
    }

    return ans;
}

Int pw(Int base, Int p) {
    Int ans = 1;

    for (int i = 1; i <= p; i++) {
        ans *= base;
    }    
    return ans;
}

Int func(int ln, int lm, int valN, int valM, int mask) {
    if (valN >= N || valM >= M) {
        return 0;
    } else if (lm == lenM) {
        return 1;
    } else {
        Int& ans = dp[ln][lm][mask];
        
        if (seen[ln][lm][mask] == 0) {
            seen[ln][lm][mask] = 1;
            
            ans = 0;
            
            for (int i = 0; i <= 6; i++) {
                if (!(mask & (1 << i))) {
                    if (ln < lenN) {
                        ans += func(ln + 1, lm, valN + i * pw(7, ln), valM, mask | (1 << i));
                    } else {
                        if (lm < lenM) {
                            ans += func(ln, lm + 1, valN, valM + i * pw(7, lm), mask | (1 << i));                                                    }
                    }
                }
            }
        }
        
        return ans;
    }
}
int main(void) {
    cin >> N >> M;

    lenN = getLen(N - 1);
    lenM = getLen(M - 1);
    //cout << lenN << " " << lenM << "\n";
    memset(dp, -1, sizeof(dp));
    cout << func(0, 0, 0, 0, 0) << "\n";
    
    return 0;
}
