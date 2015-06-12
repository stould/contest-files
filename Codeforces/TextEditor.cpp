#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;

typedef long long Int;

const int MAXN = 110;

int N;
int M[MAXN];
int R1, C1, R2, C2;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int dist[MAXN][100005];

bool inside(int r, int c) {
    if (r < 1 || r > N) return false;    
    if (c < 1 || c > M[r]) return false;
    return true;
}

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        cin >> M[i];
        M[i] += 1;
    }
    
    cin >> R1 >> C1 >> R2 >> C2;
    
    memset(dist, 63, sizeof(dist));
    
    queue<pair<int, int> > q;
    q.push(make_pair(R1, C1));
    
    dist[R1][C1] = 0;
    
    for ( ; !q.empty(); ) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
//        cerr << r << " " << c << "\n";
        
//        if (r == R2 && c == C2) break;
        
        for (int i = 0; i < 4; i++) {
            int ri = r + dx[i];
            int ci = c + dy[i];
            
            if (ri >= 1 && ri <= N && ci >= 1) {            
                if (ci > M[ri]) {
                    ci = M[ri];
                }
                if (dist[ri][ci] > dist[r][c] + 1) {
                    dist[ri][ci] = dist[r][c] + 1;
                    q.push(make_pair(ri, ci));
                }
            }
        }        
    }
    
    cout << dist[R2][C2] <<"\n";
    
    return 0;
}
