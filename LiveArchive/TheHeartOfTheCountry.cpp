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

const int MAXN = 1010;

int N, M, K;
int P[MAXN];
Int S[MAXN];
set<int> G[MAXN];
bool active[MAXN];

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    while (cin >> N >> K) {
        if (N == 0 && K == 0) break;
        
        for (int i = 0; i <= N; i++) {
            G[i].clear();
            S[i] = 0;
            active[i] = 1;
        }
        
        for (int i = 0; i < N; i++) {
            cin >> P[i] >> M;

            for (int j = 0; j < M; j++) {
                int a;
                cin >> a;
                
                G[i].insert(a);
                G[a].insert(i);
            }
        }

        vector<pair<Int, int> > q;
        
        for (int i = 0; i < N; i++) {
            S[i] = P[i];
            for (auto& it : G[i]) {
                S[i] += P[it];
            }
            q.push_back({S[i], i});
        }

        sort(q.begin(), q.end());

        while (1) {
            bool fine = false;
            
            for (int i = 0; i < N; i++) {
                int is = q[i].second;
                
                if (!active[is]) continue;

                if (S[is] < K) {
                    fine = true;
                    active[is] = 0;

                    for (auto& it : G[is]) {
                        S[it] -= P[is];
                    }
                }
            }

            if (!fine) break;
        }
            
        int ans = 0;
        Int cnt = 0;
        //cout << "\n";
        for (int i = 0; i < N; i++) {
            if (S[q[i].second] >= K) {
                ans += 1;
                //cout << (*q.begin()).second << "\n";
                cnt += P[q[i].second];
            }
        }

        cout << ans << " " << cnt << "\n";
    }
    return 0;
}
