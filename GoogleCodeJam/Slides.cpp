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

const int MAXN = 55;

int T, N;
Int M;
int has[MAXN][MAXN];

Int pw(int base, int pot) {
    Int ans = 1;

    for (int i = 1; i <= pot; i++) {
        ans *= (Int) base;
    }

    return ans;
}

Int check() {
    Int cnt[MAXN][MAXN];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cnt[i][j] = has[i][j];
        }
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (has[i][k] && has[k][j]) {
                    cnt[i][j] += cnt[i][k] * cnt[k][j];
                }
            }
        }
    }
    return cnt[0][N - 1];
}

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N >> M;
        
        memset(has, 0, sizeof(has));
        
        cout << "Case #" << t << ": ";

        Int curr = pw(2, N - 2);
        
        if (M <= curr) {
            cout << "POSSIBLE" << endl;
            
            for (int i = 0; i < N; i++) {
                for (int j = i + 1; j < N; j++) {
                    has[i][j] = 1;
                }                
            }

            Int st = curr / 2;
            
            for (int x = 1; x < N; x++) {
                if (curr - st > M) {
                    curr -= st;
                    has[N - 1 - x][N - 1] = 0;
                }
                st /= 2;
            }

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    cout << has[i][j];
                }
                cout << "\n";
            }

        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
    
    return 0;
}
