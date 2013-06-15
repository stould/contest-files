#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <functional>
#include <valarray>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;

const int MAXN = 110;

int N, M, cont, graph[MAXN][MAXN], vis[MAXN], tree[MAXN][MAXN], used[MAXN][MAXN];
string a, b;
map<string, int> si;
map<int, string> is;
vector<pair<string, string> > order;

void do_tree(int x) {
    vis[x] = 1;
    int i;

    for (i = 0; i < N; i++) if (!vis[i] && graph[i][x]) {
        tree[i][x] = 1;
        do_tree(i);
    }
}

void dfs(int x) {
    vis[x] = 1;
    int i;

    for (i = 0; i < N; i++) if (!vis[i] && graph[x][i]) {
        dfs(i);
    }
}

int main(void) {
	int i, j, k;
    while(scanf("%d%d", &N, &M) == 2 && !(N == 0 && M == 0)) {
        is.clear(); si.clear(); order.clear();
     	for (i = 0; i < N; i++) {
            vis[i] = 0;
			for (j = 0; j < N; j++) {
				tree[i][j] = graph[i][j] = used[i][j] = 0;
			}
        }
       	for (i = 0; i < N; i++) {
            cin >> a;
            si[a] = i;
            is[i] = a;
        }

        for (i = 0; i < M; i++) {
            cin >> a >> b;
            order.push_back(make_pair(a, b));
            graph[si[a]][si[b]] += 1;
        }

		do_tree(0);

		bool done = false;

		for (i = 0; i < N; i++) for (j = 0; j < N; j++) if (tree[i][j]) {
            graph[i][j] -= 1;
            for (k = 0; k < N; k++) vis[k] = 0;
            dfs(i);
            if (!vis[0]) {
                used[i][j] = 1;
                done = true;
            }
            graph[i][j] += 1;
		}

		if(!done) {
            printf("Nenhuma\n");
        } else {
            for (i = 0; i < M; i++) {
                int x = si[order[i].first], y = si[order[i].second];

                if (used[x][y]) {
                    printf("%s %s\n", is[x].c_str(), is[y].c_str());
                }
            }
        }
        printf("\n");
    }
    return 0;
}
