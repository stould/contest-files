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
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 20;
int T, N, M;

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N >> M;

        vector<pair<int, int> > G[MAXN];
        
        for (int i = 0; i < M; i++) {
            string type;
            int a, b;

            cin >> a >> b >> type;

            a -= 1;
            b -= 1;

            int conv = type == "T" ? 0 : 1;

            G[a].push_back(make_pair(b, conv));
        }

        int ans = 0;

        for (int i = 0; i < (1 << N); i++) {
            vector<int> ass(N + 1, -1);
            
            for (int j = 0; j < N; j++) {
                if (i & (1 << j)) {
                    ass[j] = 0;
                } else {
                    ass[j] = 1;
                }
            }

            bool fine = true;

            for (int j = 0; j < N; j++) {
                //T
                if (i & (1 << j)) {
                    for (int k = 0; k < (int) G[j].size(); k++) {
                        int ne = G[j][k].first;
                        int kind = G[j][k].second;
                        
                        if (ass[ne] != kind) {
                            fine = false;
                        }
                    }
                } else {
                    for (int k = 0; k < (int) G[j].size(); k++) {
                        int ne = G[j][k].first;
                        int kind = G[j][k].second;
                        
                        if (ass[ne] == kind) {
                            fine = false;
                        }
                    }
                }
            }
            if (fine) ans += 1;
        }

        cout << "Case #" << t << ": " << ans << "\n";
    }
    return 0;
}
