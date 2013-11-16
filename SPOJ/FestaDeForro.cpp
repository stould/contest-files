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

int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

const int MAXN = 510;
const int INF = 10101010;

int N, L;
string A, B;
bool found;

int id;
int vis[MAXN];

int pos, best_pos;

map<string, int> si;
map<int, string> is;

vector<int> curr, best;

vector<pair<int, int> > graph[MAXN];

void clear(void) {
    si.clear();
    is.clear();

    int i, j;

    for (i = 0; i < MAXN; i++) {
        graph[i].clear();

        vis[i] = 0;
    }
}

void mnt(string s) {
    if (si[s] == 0) {
        si[s] = id;

        is[id] = s;
        id += 1;
    }
}

void dfs(int x, int speed) {
    if (x == si[B]) {
        best = curr;
        best_pos = pos;
        found = true;
    } else {
        int i;

        for (i = 0; i < (int) graph[x].size(); i++) {
            int u = graph[x][i].first;

            if (!vis[u] && graph[x][i].second >= speed && pos + 1 < best_pos) {
                curr[pos++] = u;
                vis[u] = true;

                dfs(u, graph[x][i].second);

                vis[u] = false;
                pos--;
            }
        }
    }
}

int main(void) {
    //freopen("i.in", "r", stdin);
    int i;

    int ok = 0;

    for ( ; cin >> N; ) {
        clear();

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

        mnt(A);
        mnt(B);

        if (A == B) {
            cout << A;
        } else {
            found = false;
            best.resize(510);
            curr.resize(510);

            curr[0] = si[A];
            pos = 1;
            best_pos = 100100;
            vis[si[A]] = 1;

            dfs(si[A], -1);

            if (!found) {
                cout << "No valid route.";
            } else {
                for (i = 0; i < (int) best_pos; i++) {
                    cout << is[best[i]] << " ";
                }
            }
        }
        cout << "\n\n";
    }
    return 0;
}

