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
const int INF = 1000000005;

int N, E, K, Q;
vector<int> G[MAXN];

vector<int> func(int source) {
    vector<int> dist(N + 1, INF);

    queue<int> q;
    q.push(source);

    dist[source] = 0;

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

    return dist;
}

int main(void) {
    cin >> N >> E >> K;

    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    int mf, mt;
    int nf, nt;

    cin >> mf >> mt >> Q;

    vector<int> dist_mf = func(mf);
    vector<int> dist_mt = func(mt);

    int ans = 0;

    if (dist_mf[mt] >= INF || dist_mt[mf] >= INF) {
        cout << "0\n";
        return 0;
    }

    while (Q--) {
        cin >> nf >> nt;
        //cout << dist_mf[nf] << " " << dist_mt[nt] << "\n";
        if (dist_mf[nf] <= K && dist_mt[nt] <= K) {
            ans += 1;
        }
    }
    cout << ans << "\n";
    return 0;
}
