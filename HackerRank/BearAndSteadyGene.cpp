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

const int MAXN = 500050;

int N;
string S;
int C[MAXN][5];

int cv(char a) {
    if (a == 'A') {
        return 0;
    } else if (a == 'C') {
        return 1;
    } else if (a == 'G') {
        return 2;
    } else {
        return 3;
    }
}

bool can(int l, int r, int need) {
    int S[4];

    for (int i = 0; i < 4; i++) {
        S[i] = C[r][i];

        if (l > 0) {
            S[i] -= C[l - 1][i];
        }
    }

    int above = 0;

    for (int i = 0; i < 4; i++) {
        int out = C[N - 1][i] - S[i];

        if (out >= N / 4) {
            above += S[i];
        } else {
            above += max(0, S[i] - (N / 4 - out));
        }
    }

    return above >= need;
}

int main(void) {
    cin >> N >> S;
    
    for (int i = 0; i < N; i++) {
        C[i][cv(S[i])] += 1;

        if (i > 0) {
            for (int j = 0; j < 4; j++) {
                C[i][j] += C[i - 1][j];
            }
        }
    }

    int need = 0;
    int ans = 0;
    
    for (int i = 0; i < 4; i++) {
        need += max(0, N / 4 - C[N - 1][i]);
    }

    if (need != 0) {
        int l = 0, h = N - 1, m;
    
        while (l <= h) {
            m = (l + h) / 2;
            
            bool ok = false;
            
            for (int i = 0; i < N - m; i++) {
                if (can(i, i + m, need)) {
                    ok = true;
                    break;
                }
            }

            if (ok) {
                ans = m + 1;
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
    }
    cout << ans << "\n";
    
    return 0;
}
