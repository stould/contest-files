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

const int MAXN = 50004;
const double EPS = 1e-9;

int N;
pair<int, int> P[MAXN];
vector<int> graph[MAXN];
int color[MAXN];
int cnt[3];

double dist(int a, int b) {
    return hypot(P[a].first - P[b].first, P[a].second - P[b].second);
}

void dfs(int node, int c) {
    color[node] = c;

    if (c) {
        cnt[1] += 1;
    }
    cnt[0] += 1;
    
    for (int i = 0; i < (int) graph[node].size(); i++) {
        int next = graph[node][i];

        if (color[next] == -1) {
            dfs(next, !c);
        }
    }
}

int main(void) {
    while (cin >> N) {
        map<pair<int, int>, int > mp;
        
        for (int i = 0; i < N; i++) {
            cin >> P[i].first >> P[i].second;
        }
        
        for (int i = 0; i < N; i++) {
            graph[i].clear();
            color[i] = -1;
            
            mp[P[i]] = i;
        }		
        
        for (int i = 0; i < N; i++) {
            for (int x = -5; x <= 5; x++) {
                for (int y = -5; y <= 5; y++) {
                    double px = P[i].first - (P[i].first + x);
                    double py = P[i].second - (P[i].second + y);
					
                    if (px * px + py * py - EPS <= 25.0) {
                        pair<int, int> npair = make_pair(P[i].first + x, P[i].second + y);

                        if (mp.find(npair) != mp.end() && mp[npair] != i) {
                            graph[i].push_back(mp[npair]);
                            graph[mp[npair]].push_back(i);
                        }
                    }
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < N; i++) {
            if (color[i] == -1) {
                cnt[0] = cnt[1] = 0;
                dfs(i, 0);
                ans += min(cnt[1], cnt[0] - cnt[1]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
