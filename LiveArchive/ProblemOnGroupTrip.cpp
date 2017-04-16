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

const int MAXN = 110;

int T, N;
int M[MAXN][5];
int id[MAXN];

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N;

        for (int i = 0; i < N; i++) {
            id[i] = 0;
            for (int j = 0; j < 3; j++) {
                cin >> M[i][j];
            }
        }

        int ans = 0;

        vector<int> is(3, -1);
        
        while (1) {
            //cout << is[0] << " " << is[1] << " " << is[2] << "\n";
            bool valid = false;
            for (int i = 0; i < N; i++) {
                if (id[i] < 3) {
                    valid = true;
                    while (id[i] < 3 && M[i][id[i]] <= 0) {
                        if (is[id[i]] == i) {
                            is[id[i]] = -1;
                        }
                        id[i] += 1;
                    }
                }
            }

            if (!valid) break;
            
            for (int i = 0; i < N; i++) {
                if (id[i] < 3 && is[id[i]] == -1) {
                    is[id[i]] = i;
                }
            }
            for (int i = 0; i < 3; i++) {
                if (is[i] != -1) {
                    M[is[i]][i] -= 1;
                }
            }
            ans += 1;
        }

        cout << "Case #" << t << ": " << ans - 1 << "\n";
    }
    return 0;
}
