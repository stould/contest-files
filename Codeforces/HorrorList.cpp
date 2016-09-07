#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
const int INF = 1001001010;

int N, H, L;
int dist[MAXN], W[MAXN];
vector<int> G[MAXN];

void bfs() {
    queue<int> q;
    for (int i = 0; i < N; i++) {
        dist[i] = INF;
    }
    for (int i = 0; i < H; i++) {
        q.push(W[i]);
        dist[W[i]] = 0;
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < (int) G[now].size(); i++) {
            int next = G[now][i];
      
            if (dist[next] > dist[now] + 1) {
                dist[next] = dist[now] + 1;
                q.push(next);
            }
        }   
    }
}

int main() {
    cin >> N >> H >> L;

    for (int i = 0; i < H; i++) {
        cin >> W[i];
    }

    for (int i = 0; i < L; i++) {
        int a, b;
        cin >> a >> b;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    bfs();

    int best = -1;
    int ans = -1;

    for (int i = 0; i < N; i++) {
        if (dist[i] > best) {
            best = dist[i];
            ans = i;
        }
    }
    cout << ans << "\n";
    return 0;
}
