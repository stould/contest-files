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

const int MAXN = 15;

int N, M, S;
int E[MAXN], F[MAXN];
vector<int> G[MAXN];
int dp[1 << MAXN];

int func(int mask) {
    if (mask && (1 << N) - 1) {
        return 1;
    } else {
        int& ans = dp[mask];

        if (ans == -1) {
            ans = 0;

            int mine = S;

            for (int i = 0; i < N; i++) {
                if (mask & (1 << i)) {
                    mine += F[i];
                }
            }

            for (int i = 0; !ans && i < N; i++) {
                if (!(mask & (1 << i))) {
                    if (mine > E[i]) {
                        bool valid = true;

                        for (int j = 0; j < (int) G[i].size(); j++) {
                            int nd = G[i][j];

                            if (!(mask & (1 << nd))) {
                                valid = false;
                            }
                        }

                        if (valid) {
                            int check = func(mask | (1 << i));
                            
                            if (check == 1) {
                                ans = 1;
                            }
                        }
                    }
                }
            }            
        }

        return ans;
    }
}

int main(void) {
    while (cin >> N >> M >> S && !(N == 0 && M == 0 && S == 0)) {
        for (int i = 0; i < MAXN; i++) {
            G[i].clear();
        }
        for (int i = 0; i < N; i++) {
            cin >> E[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> F[i];
        }
        for (int i = 0; i < M; i++) {
            int A, B;
            cin >> A >> B;

            A -= 1;
            B -= 1;
            
            G[B].push_back(A);
        }

        memset(dp, -1, sizeof(dp));
        
        int can = func(0);

        if (can == 1) {
            cout << "possivel" << endl;
        } else {
            cout << "impossivel" << endl;
        }
    }
    return 0;
}
