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

const int MAXN = 3030;

int T;
int N, M;
int id;
map<string, int> sh;
vector<int> G[MAXN];
int dist[MAXN];

int get(string s) {
    if (sh.find(s) == sh.end()) {
        sh[s] = id++;
    }
    return sh[s];
}

int far(int f) {
    queue<int> q;
        
    memset(dist, 63, sizeof(dist));
    
    dist[f] = 0;
    
    q.push(f);

    int ans = 0;
    
    while(!q.empty()) {
        int now = q.front();
        q.pop();

        chmax(ans, dist[now]);

        if (ans > 6) break;
        
        for (int i = 0; i < (int) G[now].size(); i++) {
            int next = G[now][i];

            if (dist[next] > dist[now] + 1) {
                dist[next] = dist[now] + 1;
                q.push(next);
            }
        }
    }
    
    return ans;
}

int main(void) {
    cin >> T;

    while (T--) {
        id = 1;

        cin >> M;

        sh.clear();

        for (int i = 0; i < MAXN; i++) {
            G[i].clear();
        }

        for (int i = 0; i < M; i++) {
            string a, b;

            cin >> a >> b;

            int ia = get(a);
            int ib = get(b);

            //cout << ia << " " << ib << endl;
            
            G[ia].push_back(ib);
            G[ib].push_back(ia);
        }

        int cnt = 0;

        for (int i = 1; i < id; i++) {
            if (far(i) > 6) {
                cnt += 1;
            }
        }
        if (5 * id / 100 < cnt) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}
