#include <bits/stdc++.h>

using namespace std;

const int MAXN = 151;
const int INF = 1061109567;

vector<pair<int, int> > G[MAXN];

int T;
int N, M, Q;
int dist[MAXN][MAXN][MAXN];
int memo[MAXN][MAXN];

void gen() {
    cout << "1\n150 3000 1000\n";
    
    srand(time(NULL));
    
    for (int i = 0; i < 3000 + 1000; i++) {
        int a = rand() % 150;
        int b = rand() % 150;
        int c = rand() % 30000;
        
        cout << a << " " << b << " " << c << "\n";
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> T;        
    
    for (int t = 1; t <= T; t++) {
        cin >> N >> M >> Q;
        
        for (int i = 0; i <= N; i++) {
            G[i].clear();
        }
        
        for (int i = 0; i < M; i++) {
            int A, B, C;
            
            cin >> A >> B >> C;
            
            G[A].push_back(make_pair(B, C));
        }
        
        memset(dist, 63, sizeof(dist));
        
        for (int s = 1; s <= N; s++) {           
            memset(memo, 0, sizeof(memo));
            
            queue<pair<int, pair<int, pair<int, int> > > > q;
            q.push(make_pair(0, make_pair(0, make_pair(0, s))));
            
            dist[s][s][0] = 0;  
            memo[s][0] = 1;
                    
            
            for ( ; !q.empty(); ) {
                int curr_dist = -q.front().first;
                int curr_len = q.front().second.first;
                int last_edge_dist = q.front().second.second.first;
                int node = q.front().second.second.second;
                q.pop();   
                
                memo[node][curr_len] = 0;                                          

                if (dist[s][node][curr_len] < curr_dist) {
                    continue;
                }
                
                for (int i = 0; i < (int) G[node].size(); i++) {
                    int u = G[node][i].first;
                    int edge_dist = G[node][i].second;
                    
                    if (edge_dist <= last_edge_dist) continue;
                    
                    if (dist[s][u][curr_len + 1] > dist[s][node][curr_len] + edge_dist) {
                        dist[s][u][curr_len + 1] = dist[s][node][curr_len] + edge_dist;                     
                        q.push(make_pair(-dist[s][u][curr_len + 1], make_pair(curr_len + 1, make_pair(edge_dist, u))));                           
                        
                    }                   
                }
            }
            
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    dist[s][i][j] = min(dist[s][i][j], dist[s][i][j - 1]);
                }
            }          
        }

        for (int q = 0; q < Q; q++) {
            int A, B, C;
            
            cin >> A >> B >> C;
            
            C = min(C, N);
            
            int d = dist[A][B][C];
         
            if (d >= INF) d = -1;
            
            cout << d << "\n";           
        }
    }
 
    return 0;
}
