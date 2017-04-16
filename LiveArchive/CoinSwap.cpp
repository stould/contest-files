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

const int MAXN = 505;
const int INF = 10010101;

int T, N, M;
vector<int> G[MAXN];
int C[MAXN], D[MAXN];
int dist[MAXN];

pair<int, int> bfs(int node) {
    queue<int> q;
    q.push(node);

    memset(dist, 63, sizeof(dist));

    dist[node] = 0;

    int mx = INF;
    int id = -1;
    
    while (!q.empty()) {
        int now = q.front();
        q.pop();

        if (now != node && C[now] == D[node]) {
            if (mx > dist[now]) {
                mx = dist[now];
                id = now;
            }
        }

        for (int i = 0; i < (int) G[now].size(); i++) {
            int next = G[now][i];

            if (D[next] != D[now] && dist[next] > dist[now] + 1) {
                dist[next] = dist[now] + 1;
                q.push(next);
            }
        }
    }
    
    return make_pair(id, mx);
}

int main(void) {
    cin >> T;

    while (T--) {
        cin >> N >> M;
        
        for (int i = 0; i < MAXN; i++) {
            G[i].clear();
        }

        for (int i = 0; i < M; i++) {
            int A, B;
            cin >> A >> B;

            G[A].push_back(B);
            G[B].push_back(A);
        }

        for (int i = 1; i <= N; i++) {
            cin >> C[i];
        }
        for (int i = 1; i <= N; i++) {
            cin >> D[i];
        }

        int ans = 0;
        int lf = -1;
        int le = -1;
        
        while (1) {
            int f = 0;
            int e = -1;
            int best = INF;
            
            for (int i = 1; i <= N; i++) {
                pair<int, int> now = bfs(i);
                    
                if (now.second < best && !(lf == i && le == now.first)) {
                    best = now.second;
                    f = min(i, now.first);
                    e = max(i, now.first);
                }
            }
            lf = f;
            le = e;
            cout << f << " " << e << " " << best << endl;
            if (e <= 0) break;
            swap(D[e], D[f]);
            ans += best;
        }

        cout << ans << endl;
    }
    return 0;
}
