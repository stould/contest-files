#include <bits/stdc++.h>

#define ll long long
#define MAXN 10011
#define INF 1001001010100101LL

using namespace std;

vector<vector<pair<ll, pair<ll, ll> > > > graph(MAXN);

void add(ll a, ll b, ll c){
    graph[a].push_back(make_pair(b, make_pair(c, 0)));
    graph[b].push_back(make_pair(a, make_pair(c, 0)));
}

ll n, m, k, U, V, C, K[MAXN];

ll dist[MAXN][2];

bool cmp(pair<ll, pair<ll, ll> > a, pair<ll, pair<ll, ll> > b) {
    return a.second.first < b.second.first;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    cin >> n >> m >> k;
  
    for(int i = 0; i < k; i++){
        cin >> K[i];
    }

    for(int i = 0; i < m; i++){
        cin >> U >> V >> C;
    
        add(U, V, C);
    }
  
    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end(), cmp);
    }

    for (int i = 1; i < k; i++) {
        ll p = K[i - 1];
        ll q = K[i];
    
        for (int j = 0; j < (int) graph[p].size(); j++) {
            if (graph[p][j].first == q) {
                graph[p][j].second.second = 1;
                break;
            }
        }
    }
  
    priority_queue<pair<ll, pair<ll, ll> > > q;
  
    q.push(make_pair(0, make_pair(1, 1)));
    
    for (int i = 1; i <= n; i++) {
        dist[i][0] = dist[i][1] = INF;
    }
  
    dist[1][1] = 0;
  
    while (!q.empty()) {
        ll ds = -q.top().first;
        ll now = q.top().second.first;
        int seen = q.top().second.second;
        q.pop();

        if (dist[now][seen] < ds) {
            continue;
        }
    
        for(int i = 0; i < (int) graph[now].size(); i++){
            int next = graph[now][i].first;
            ll cost = graph[now][i].second.first;
            int next_seen = seen;
      
            if (graph[now][i].second.second == 0) {
                next_seen = 0;
            }
      
            if (dist[now][seen] + cost < dist[next][next_seen]) {
                dist[next][next_seen] = dist[now][seen] + cost;
                q.push(make_pair(-dist[next][next_seen], make_pair(next, next_seen)));
            }
        }
    }
  
    bool ans = dist[n][0] == dist[n][1];
  
    // cout << dist[n][0] << " " << dist[n][1] << "\n";
  
    if (ans){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }
    return 0;
}

