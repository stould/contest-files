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
const int INF = INT_MAX / 5;

int T, N, M, K;
vector<pair<int, int> > G[MAXN];
int dist[MAXN];
vector<int> pr[MAXN];
vector<int> rv[MAXN];
Int cnt[MAXN];
int obs[MAXN];
int deg[MAXN];

int func() {
    for (int i = 0; i < MAXN; i++) {
        dist[i] = INF;
        pr[i].clear();
    }

    priority_queue<pair<int, int> > q;
    dist[0] = 0;
    
    q.push(make_pair(0, 0));

    while(!q.empty()) {
        int ds = -q.top().first;
        int now = q.top().second;
        q.pop();

        if (ds > dist[now]) continue;

        for(int i = 0; i < G[now].size(); i++) {
            int next = G[now][i].first;
            int cost = G[now][i].second;

            if (obs[now]) {
                cost += 1;
            }
            
            if (dist[next] > dist[now] + cost) {
                dist[next] = dist[now] + cost;
                q.push(make_pair(-dist[next], next));

                pr[next].clear();
                pr[next].push_back(now);
            } else if (dist[next] == dist[now] + cost) {
                pr[next].push_back(now);
            }
        }
    }
    
    return dist[N - 1];
}

vector<int> bfs() {
    queue<int> q;
    q.push(0);

    for (int i = 0; i < MAXN; i++) {
        cnt[i] = 0;
        rv[i].clear();
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (int) pr[i].size(); j++) {
            rv[pr[i][j]].push_back(i);
        }
    }

    cnt[0] = 1;
    
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        
        for (int i = 0; i < rv[now].size(); i++) {
            int next = rv[now][i];

            cnt[next] += cnt[now];
            q.push(next);
        }
    }

    int ans = -1;
    vector<int> pans;
    int pos = 0;
    int pdeg = 0;

    for (int i = 0; i < N - 1; i++) {
        if (obs[i]) continue;

        if (cnt[i] > ans) {
            ans = cnt[i];
            pans.clear();
            pans.push_back(i);
        } else if (cnt[i] == ans) {
            pans.push_back(i);
        }
    }
    
    vector<int> pe;

    for (int i = 0; i < pans.size(); i++) {
        if (deg[pans[i]] > pdeg) {
            pdeg = deg[pans[i]];
            pe.clear();
            pe.push_back(pans[i]);
        } else if (deg[pans[i]] == pdeg) {
            pe.push_back(pans[i]);
        }
    }
    return pe;
}

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N >> M >> K;

        for (int i = 0; i < MAXN; i++) {
            G[i].clear();
            obs[i] = 0;
            deg[i] = 0;
        }
        
        for (int i = 0; i < M; i++) {
            int A, B;

            cin >> A >> B;

            deg[A] += 1;
            deg[B] += 1;

            G[A].push_back(make_pair(B, 1));
            G[B].push_back(make_pair(A, 1));
        }

        int ans = 0;

        while (K > 0) {
            ans = max(ans, func());
            vector<int> fix = bfs();
            if (fix.empty()) break;
            
            if (fix.size() <= K) {
                for (int i = 0; i < (int) fix.size(); i++) {
                    obs[fix[i]] = 1;
                }
                K -= fix.size();
            } else {
                for (int x = 0; x < 200; x++) {
                    random_shuffle(fix.begin(), fix.end());

                    for (int i = 0; i < min(K, (int) fix.size()); i++) {
                        obs[fix[i]] = 1;
                    }
                    ans = max(ans, func());
                    for (int i = 0; i < min(K, (int) fix.size()); i++) {
                        obs[fix[i]] = 0;
                    }
                }
                K = 0;
            }
        }
        ans = max(ans, func());
        cout << ans << endl;
    }
    return 0;
}
