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

typedef long long Int;
typedef unsigned uint;

const int MAXN = 50;

int P;

int S[MAXN];
int C[MAXN];
int W[MAXN];

int main(void) {
    int test = 1, curr;
    for ( ; cin >> curr; ) {
        memset(S, 0, sizeof(S));
        memset(W, 0, sizeof(W));
        memset(C, 0, sizeof(C));

        S[curr] += 1;
        for (int i = 1; i < 15; i++) {
            cin >> curr;
            S[curr] += 1;
        }
        cin >> P;
        for (int i = 0; i < P; i++) {
            cin >> C[i];
        }
        for (int i = 0; i < (1 << P); i++) {
            int b = __builtin_popcount(i);
            if (b == 15) {
                int cnt = 0;
                int cpy[MAXN];
                for (int j = 0; j <= 25; j++) cpy[j] = S[j];
                for (int j = 0; j < P; j++) {
                    if (i & (1 << j) && cpy[C[j]] > 0) {
                        cnt += 1;
                        cpy[C[j]] -= 1;
                    }
                }
                if (cnt >= 11) {
                    W[cnt] += 1;
                }
            }
        }
        vector<pair<int, int> > ans;
        for (int i = 11; i <= 15; i++) {
            if (W[i] > 0) {
                ans.push_back(make_pair(i, W[i]));
            }
        }
        cout << "Aposta " << test++ << "\n";

        if (ans.empty()) {
            cout << "nenhum premio aqui\n";
        } else {
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i].first << ": " << ans[i].second << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}
