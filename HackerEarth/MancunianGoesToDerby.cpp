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

const int MAXN = 100005;

int N, E, Q;
int dist[MAXN];
vector<int> graph[2][MAXN];

void bfs() {
    priority_queue<pair<int, int> > q;
    q.push(make_pair(0, 1));

    memset(dist, 63, sizeof(dist));

    dist[1] = 0;

    while (!q.empty()) {
        int dst = -q.top().first;
        int now = q.top().second;
        q.pop();
        
        if (dst > dist[now]) continue;

        int p1 = dist[now] % 2;
        int p2 = p1 ^ 1;

        for (int i = 0; i < (int) graph[p2][now].size(); i++) {
            int next = graph[p2][now][i];
            
            if (dist[next] > dist[now] + 2) {
                dist[next] = dist[now] + 2;
                q.push(make_pair(-dist[next], next));
            }                
        }
        
        for (int i = 0; i < (int) graph[p1][now].size(); i++) {
            int next = graph[p1][now][i];

            if (dist[next] > dist[now] + 1) {
                dist[next] = dist[now] + 1;
                q.push(make_pair(-dist[next], next));
            }                
        }
    }
}

int main(void) {
    cin >> N >> E >> Q;

    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;

        graph[0][a].push_back(b);
        graph[1][b].push_back(a);
    }

    bfs();

    for (int i = 0; i < Q; i++) {
        int now;
        cin >> now;

        if (dist[N] <= now) {
            cout << "GGMU\n";
        } else {
            cout << "FML\n";
        }
    }
    
    return 0;
}
