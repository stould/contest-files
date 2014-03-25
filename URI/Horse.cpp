#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110;
const int INF = INT_MAX / 3;

int N, M, K;
string str[MAXN];
map<pair<int, int>, int> hash;
int point, source;

int vis[MAXN][MAXN];
int dst[MAXN][MAXN];

int dx[8] = {+1,+1,-1,-1,+2,+2,-2,-2};
int dy[8] = {+2,-2,+2,-2,+1,-1,+1,-1};

void fix(int x, int y) {
    pair<int, int> p = make_pair(x, y);
   
    if (hash[p] == 0) {
        hash[p] = point++;
    }
}

void bfs(int x, int y) {
    fix(x, y);
   
    pair<int, int> root = make_pair(x, y);
   
    queue<pair<int, int> > q;
    memset(vis, false, sizeof(vis));
   
    q.push(make_pair(x, y));
    memset(vis, 63, sizeof(vis));
    vis[x][y] = 0;

	//	cout << "from = " << x << " " << y << "\n";
   
    for ( ; !q.empty(); ) {
        pair<int, int> p = q.front();
        q.pop();

		//		cout << p.first << " " << p.second << " " << vis[p.first][p.second] << "\n";
       
        for (int i = 0; i < 8; i++) {
            int px = p.first + dx[i];
            int py = p.second + dy[i];
           
            if (px >= 0 && py >= 0 && px < N && py < M) {
                if (vis[px][py] > vis[p.first][p.second] + 1 && str[px][py] != '#') {
                    pair<int, int> np = make_pair(px, py);   
                    q.push(np);                  
                   
                    vis[px][py] = vis[p.first][p.second] + 1;					
                   
					if (str[px][py] == 'P' || str[px][py] == 'C') {
                         int curr = vis[px][py];             
                         fix(px, py);                   
                        
                         int p1 = hash[root];
                         int p2 = hash[np];

                         dst[p1][p2] = min(curr, dst[p1][p2]);
                         dst[p2][p1] = min(curr, dst[p2][p1]);
							 //						 cout << x << " " << y  << " - " << px << " " << py << " = " << dst[p1][p2] << "\n";
                    }
                }
            }
        }
    }   
}

int dp[(1 << 17)];

int func(int id, int mask) {
    if (mask == (1 << point) - 2) {
        return dst[id][source];
    } else {
        int& ans = dp[mask];
       
        if (ans == -1) {
            ans = INF;
           
            for (int i = 1; i < point; i++) {
                if (i != id) {
                    if (!(mask & (1 << i))) {
                        ans = min(ans, dst[id][i] + func(i, mask | (1 << i)));
                    }
                }
            }
        }
       
        return ans;
    }
}

int main(void) {
    for ( ; cin >> N >> M >> K && (N + M + K != 0); ) {
        point = 1;
        hash.clear();
       
        memset(dst, 63, sizeof(dst));
       
        for (int i = 0; i < N; i++) {
            cin >> str[i];
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (str[i][j] == 'P' || str[i][j] == 'C') {
                    bfs(i, j);

                    if (str[i][j] == 'C') {
                        source = hash[make_pair(i, j)];
                    }
                }
            }
        }
        memset(dp, -1, sizeof(dp));     
       
        cout << func(source, (1 << source)) << "\n";
    }
    return 0;
}
