#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>
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
typedef unsigned uint;

const int MAXN = 1010;

int N, M;
bool vis[MAXN][MAXN];
int dist[MAXN][MAXN];
char field[MAXN][MAXN];

void bfs(int x, int y) {
    queue<pair<int, int> > q;
    
    q.push(make_pair(x, y));
    vis[x][y] = true;    
    
    for ( ; !q.empty(); ) {
        pair<int, int> now = q.front();
        q.pop();
        vis[now.first][now.second] = true;
        
        int xx = -1, yy = -1;
        
        if (field[now.first][now.second] == '/') {
            xx = now.first - 1;
            yy = now.second + 1;
        } else {
            xx = now.first + 1;
            yy = now.second + 1;        
        }
        
        if (xx >= 0 && xx < N && yy >= 0 && yy < M) {
            if (dist[now.first][now.second] + 1 > dist[xx][yy]) {
                if (!vis[xx][yy]) {
                    q.push(make_pair(xx, yy));
                    dist[xx][yy] = dist[now.first][now.second] + 1;
                } else {
                    dist[xx][yy] = -1;
                }
            }
        }
    } 
}

int main(void) {
    freopen("i.in", "r", stdin);
    
//    freopen("mirror.in", "r", stdin);
//    freopen("mirror.out", "w", stdout);

    N = in();
    M = in();
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf(" %c", &field[i][j]);
        }
    }
    
    int ans = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (dist[i][j] == 0) {
                bfs(i, j);        
            }
        }
    }
    bool done = false;
    for (int i = 0; !done && i < N; i++) {
        for (int j = 0; !done && j < M; j++) {            
            if (dist[i][j] == -1) {
                done = true;
            } else {
                chmax(ans, dist[i][j] + 1);
            }
        }
    }
    cout << (done ? -1 : ans) << endl;
    
    return 0;
}
