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
#include <numeric>
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

#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)

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

const int MAXN = 5007;

int N, L;
string A, B;
int id;
int vis[MAXN], prev[MAXN];

map<string, int> si;
map<int, string> is;

vector<pair<int, int> > graph[MAXN];


void clear(void) {
    si.clear();
    is.clear();

    int i;

    for (i = 0; i < MAXN; i++) {
        graph[i].clear();
        vis[i] = 0;
        prev[i] = -1;
    }
}

void mnt(string s) {
    if (si[s] == 0) {
        si[s] = id;
        is[id] = s;
        id += 1;
    }
}

void bfs(void) {
    queue<pair<int, int> > q; q.push(make_pair(si[A], 0)); vis[si[A]] = 1;

    int i;

    for ( ; !q.empty(); ) {
        pair<int, int> sp = q.front(); q.pop();

        int now = sp.first;
        int spd = sp.second;

        cout << now << " " << spd << "\n";

        for (i = 0; i < (int) graph[now].size(); i++) {
            int next = graph[now][i].first;
            int next_speed = graph[now][i].second;

            if (!vis[next] && spd <= next_speed) {
                vis[next] = 1;
                prev[next] = now;
                q.push(make_pair(next, next_speed));
            }
        }
    }

    vector<string> ans;
    int curr = si[B];

    if (curr == -1) {
        cout << "No valid route.";
    } else {
        for ( ; curr != -1; ) {
            ans.push_back(is[curr]);
            curr = prev[curr];
        }

        reverse (ans.begin(), ans.end());

        for (i = 0; i < (int) ans.size(); i++) {
            cout << ans[i];

            if (i != (int) ans.size() - 1) {
                cout << " ";
            }
        }
    }
}

int main(void) {
    freopen("i.in", "r", stdin);
    int i;

    int ok = 0;

    for ( ; cin >> N; ) {
        clear();

        if (ok) cout << "\n\n";

        ok = 1;

        id = 1;

        for (i = 0; i < N; i++) {
            cin >> A >> B >> L;

            mnt(A);
            mnt(B);

            int id_A = si[A], id_B = si[B];

            graph[id_A].push_back(make_pair(id_B, L));
            graph[id_B].push_back(make_pair(id_A, L));
        }

        for (i = 1; i <= id; i++) {
            sort (graph[i].begin(), graph[i].end());
        }

        cin >> A >> B;

        if (A == B) {
            cout << A;
        } else {
            bfs();
        }
    }
    return 0;
}
