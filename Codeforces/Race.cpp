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

const int MAXN = 25;

string S[MAXN];
int N, M;
int dist[MAXN][MAXN];

int dx[4] = {-1, 1,  0, 0};
int dy[4] = { 0, 0, -1, 1};

bool inside(int a, int b) {
    return a >= 0 && b >= 0 && a < N && b < M;
}

int main(void) {
    cin >> N >> M;

    int si = 0, sj = 0;
    int ei = 0, ej = 0;

    for (int i = 0; i < N; i++) {
        cin >> S[i];

        for (int j = 0; j < M; j++) {
            if (S[i][j] == 'S') {
                si = i;
                sj = j;
            } else if (S[i][j] == 'T') {
                ei = i;
                ej = j;
            }
        }
    }

    queue<pair<int, int> > q;
    q.push(make_pair(si, sj));

    memset(dist, 63, sizeof(dist));
    
    dist[si][sj] = 0;
    
    while (!q.empty()) {
        int ci = q.front().first;
        int cj = q.front().second;
        q.pop();

        //cout << ci << " " << cj << "\n";
        
        for (int i = 0; i < 4; i++) {
            int di = ci + dx[i];
            int dj = cj + dy[i];

            while (inside(di, dj) && S[di][dj] != '#') {
                di += dx[i];
                dj += dy[i];
            }

            if (!inside(di, dj) || S[di][dj] == '#') {
                di -= dx[i];
                dj -= dy[i];
            }
            
            int dis = (abs(ci - di) + abs(cj - dj) + 1) / 2;

            di = ci + dis * dx[i];
            dj = cj + dis * dy[i];

            if (dist[di][dj] > dist[ci][cj] + 1) {
                dist[di][dj] = dist[ci][cj] + 1;
                q.push(make_pair(di, dj));
            }
        }
    }

    int ans = dist[ei][ej];

    if (ans >= 1000000) {
        ans = -1;
    }

    cout << ans << "\n";
    
    return 0;
}
