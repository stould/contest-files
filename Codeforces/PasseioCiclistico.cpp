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

const int MAXN = 510;
const Int INF = 1000101000100001LL;

int N;
Int dist[MAXN];
vector<pair<int, Int> > G[MAXN];
Int redux[MAXN][MAXN];

void shortestPath(int source) {
    priority_queue<pair<Int, int> > q;
    
    for (int i = 0; i < MAXN; i++) {
        dist[i] = INF;
    }
    
    dist[source] = 0;
    
    q.push(make_pair(0, source));

    while(!q.empty()) {
        Int ds = -q.top().first;
        int now = q.top().second;
        q.pop();
        
        if (ds > dist[now]) continue;

        redux[source][now] = dist[now];
        
        for(int i = 0; i < (int) G[now].size(); i++) {
            int next = G[now][i].first;
            Int cost = G[now][i].second;

            if (dist[next] > dist[now] + cost) {
                dist[next] = dist[now] + cost;
                q.push(make_pair(-dist[next], next));
            }
        }
    }
}


int main(void) {
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Int p; cin >> p;

            redux[i][j] = -1;            
            
            if (p != -1) {
                G[i].push_back(make_pair(j, p));
            }
        }
    }

    int id = -1;
    Int cost = INF;
    
    for (int i = 0; i < N; i++) {
        shortestPath(i);
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            Int now = redux[i][j] + redux[j][i];

            if (redux[i][j] == -1 or redux[j][i] == -1) {
                continue;
            }
            
            if (now < cost) {
                cost = now;
                id = i;
            }
        }
    }
    
    if (cost >= INF) {
        cout << "-1" << endl;
    } else {
        cout << id + 1 << " " << cost << endl;
    }
    return 0;
}
