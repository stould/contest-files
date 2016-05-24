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

const int MAXN = 220;

int N, M, Q;
int P[MAXN][MAXN];
int cnt[MAXN][MAXN];

int main(void) {
    cin >> N >> M;

    int best = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> P[i][j];

            if (P[i][j] == 0) {
                P[i][j] = 1;
            } else {
                P[i][j] = 0;
            }

            cnt[i][j] = P[i][j];

            if (i > 0 && j > 0) {
                cnt[i][j] += cnt[i - 1][j - 1];
            }

            for (int k = 0; k < i; k++) {
                cnt[i][j] += P[k][j];
            }
            for (int k = 0; k < j; k++) {
                cnt[i][j] += P[i][k];
            }
        }
    }
        
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int l = 0, h = min(N - i - 1, M - j - 1), m;

            while (l <= h) {
                m = (l + h) / 2;

                int sum = cnt[i + m][j + m];
                
                if (i > 0) {
                    sum -= cnt[i - 1][j + m];
                }
                if (j > 0) {
                    sum -= cnt[i + m][j - 1];
                }

                if (i > 0 && j > 0) {
                    sum += cnt[i - 1][j - 1];
                }
                if (sum == 0){
                    best = max(best, m + 1);
                    l = m + 1;
                } else {
                    h = m - 1;
                }
            }

        }
    }

    cin >> Q;

    while (Q--) {
        int curr;
        cin >> curr;

        if (curr <= best) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}
