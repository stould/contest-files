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

const int MAXN = 25005;
const Int INF = 1001001010010100LL;

int N, P, M, G, T;
Int reduxGraph[20][20];
int SP[MAXN];
Int dist[MAXN];
vector<pair<int, Int> > graph[MAXN];
Int dp[20][1 << 17][2];
vector<int> interest;

void shortestPath(int source) {
    priority_queue<pair<Int, int> > q;
    
    memset(dist, 63, sizeof(dist));
    
    dist[interest[source]] = 0;
    
    q.push(make_pair(0, interest[source]));

    while(!q.empty()) {
        Int ds = -q.top().first;
        int now = q.top().second;
        q.pop();
        
        if (ds > dist[now]) continue;

        for(int i = 0; i < (int) graph[now].size(); i++) {
            int next = graph[now][i].first;
            Int cost = graph[now][i].second;

            if (dist[next] > dist[now] + cost) {
                dist[next] = dist[now] + cost;
                q.push(make_pair(-dist[next], next));
            }
        }
    }
    
    for (int i = 0; i < (int) interest.size(); i++) {
        reduxGraph[source][i] = dist[interest[i]];
    }
}

Int func(int pos, int mask, int taxi) {
    if (__builtin_popcount(mask) == (int) interest.size()) {
        return reduxGraph[pos][0] + SP[interest[0]];
    } else {
        Int& ans = dp[pos][mask][taxi];

        if (ans == -1) {
            ans = INF;
            
            for (int i = 0; i < (int) interest.size(); i++) {
                if (!(mask & (1 << i))) {
                    chmin(ans, reduxGraph[pos][i] + SP[interest[i]] + func(i, mask | (1 << i), taxi));
                    
                    if (taxi) {
                        chmin(ans, T + SP[interest[i]] + func(i, mask | (1 << i), 0));
                    }
                }
            }
        }

        return ans;
    }
}

int main(void) {
    cin >> N >> P >> M >> G >> T;

    interest.push_back(0);
    
    for (int i = 0; i < P; i++) {
        int p, t;
        cin >> p >> t;

        SP[p] += t;

        if (p != 0) {
            interest.push_back(p);
        }
    }

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }

    for (int i = 0; i < (int) interest.size(); i++) {
        shortestPath(i);
    }

    memset(dp, -1, sizeof(dp));

    //cout << func(0, 1 << 0, 0) << endl;
    //cout << func(0, 1 << 0, 1) << endl;
    
    if (func(0, 1 << 0, 0) <= G) {
        cout << "possible without taxi" << endl;
    } else if (func(0, 1 << 0, 1) <= G) {
        cout << "possible with taxi" << endl;
    } else {
        cout << "impossible" << endl;
    }
    
    return 0;
}
