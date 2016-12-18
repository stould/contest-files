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

int N;
int X[MAXN], Y[MAXN];
map<int, vector<int> > GX;
map<int, vector<int> > GY;
int dist[MAXN];

int main(void) {
    //freopen("lasers.in", "r", stdin);
    //freopen("lasers.out", "w", stdout);
    
    cin >> N >> X[0] >> Y[0];
    cin >> X[N + 1] >> Y[N + 1];

    GX[X[0]].push_back(0);
    GY[Y[0]].push_back(0);
    
    GX[X[N + 1]].push_back(N + 1);
    GY[Y[N + 1]].push_back(N + 1);
    
    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> Y[i];

        GX[X[i]].push_back(i);
        GY[Y[i]].push_back(i);
    }
    
    priority_queue<pair<int, pair<int, int> > > q;

    q.push(make_pair(0, make_pair(0, 0)));
    q.push(make_pair(0, make_pair(0, 1)));

    memset(dist, 63, sizeof(dist));

    dist[0] = 0;
    
    while (!q.empty()) {
        int now = q.top().second.first;
        int dir = q.top().second.second;
        int dst = -q.top().first;
        q.pop();

        if (dist[now] < dst) {
            continue;
        }

        if (now == N + 1) {
            break;
        }
        
        if (dir == 0) {
            for (int i = 0; i < (int) GX[X[now]].size(); i++) {
                int next = GX[X[now]][i];

                if (dist[next] > dist[now] + 1) {
                    dist[next] = dist[now] + 1;
                    q.push(make_pair(-dist[next], make_pair(next, dir ^ 1)));
                }
            }
        } else {
            for (int i = 0; i < (int) GY[Y[now]].size(); i++) {
                int next = GY[Y[now]][i];

                if (dist[next] > dist[now] + 1) {
                    dist[next] = dist[now] + 1;
                    q.push(make_pair(-dist[next], make_pair(next, dir ^ 1)));
                }
            }
        }            
    }

    cout << dist[N + 1] - 1 << "\n";
    
    return 0;
}
