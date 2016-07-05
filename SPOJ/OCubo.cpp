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
typedef unsigned uint;

const int MAXN = 21;
const int INF = INT_MAX / 3;

int R, C;
char S[MAXN][MAXN];
//step, push
pair<int, int> dist[MAXN][MAXN][MAXN][MAXN];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

struct state {
    int mx, my, bx, by;
	
    state(){}

    state(int mx, int my, int bx, int by): mx(mx), my(my), bx(bx), by(by){}
};

//compare whether a is less than b from second, then first
bool isLess(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

pair<int, int> bfs(int sx, int sy, int bx, int by) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            for (int k = 0; k < R; k++) {
                for (int l = 0; l < C; l++) {
                    dist[i][j][k][l] = make_pair(INF, INF);
                }
            }
        }
    }
	
    queue<state> q;
    q.push(state(sx, sy, bx, by));
	
    dist[sx][sy][bx][by] = make_pair(0, 0);

    pair<int, int> ans = make_pair(INF, INF);

    for ( ; !q.empty(); ) {
        int mx = q.front().mx;
        int my = q.front().my;
        int bx = q.front().bx;
        int by = q.front().by;

        q.pop();
		
        if (S[bx][by] == 'T') {
            if (isLess(dist[mx][my][bx][by], ans)) {
                ans = dist[mx][my][bx][by];
            }
            continue;
        }
		
        for (int i = 0; i < 4; i++) {
            int px = mx + dx[i];
            int py = my + dy[i];
			
            if (px >= 0 && py >= 0 && px < R && py < C) {
                if (px == bx && py == by) {					
                    int qx = bx + dx[i];
                    int qy = by + dy[i];
					
                    if (qx >= 0 && qy >= 0 && qx < R && qy < C) {
                        if (S[qx][qy] != '#') {
                            pair<int, int> n_step = make_pair(dist[mx][my][bx][by].first + 1, dist[mx][my][bx][by].second + 1);
							
                            if (isLess(n_step, dist[px][py][qx][qy])) {
                                dist[px][py][qx][qy] = n_step;
                                q.push(state(px, py, qx, qy));
                            }							
                        }
                    }
                } else if (S[px][py] != '#') {
                    pair<int, int> n_step = make_pair(dist[mx][my][bx][by].first + 1, dist[mx][my][bx][by].second);

                    if (isLess(n_step, dist[px][py][bx][by])) {			
                        dist[px][py][bx][by] = n_step;
                        q.push(state(px, py, bx, by));
                    }
                }
            }
        }
    }
    return ans;
}

int main(void) {
    int test = 1;

    for ( ; scanf("%d%d", &R, &C) == 2 && !(R == 0 && C == 0); ) {
        if (test > 1) {
            printf("\n");
        }
        pair<int, int> st, bp;
		
        for (int i = 0; i < R; i++) {
            scanf("%s", S[i]);
            for (int j = 0; j < C; j++) {
                if (S[i][j] == 'S') {
                    st = make_pair(i, j);
                } else if (S[i][j] == 'B') {
                    bp = make_pair(i, j);
                }
            }
        }

        pair<int, int> ans = bfs(st.first, st.second, bp.first, bp.second);

        printf("Instancia %d\n", test++);

        if (ans.first >= INF) {
            printf("Impossivel\n");
        } else {
            printf("%d %d\n", ans.first, ans.second);
        }
    }
    return 0;
}
