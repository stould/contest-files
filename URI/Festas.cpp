#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <iostream>
#include <functional>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <valarray>
#include <vector>
#include <utility>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define REP(i, n) for((i) = 0; (i) < (n); i++)
#define FOR(i, a, n) for((i) = (a); (i) < (n); i++)

using namespace std;

const int INF = 1000000000;
const double PI = acos(-1);

typedef long long ll;

int i, j, n, m, k, a, b, vis[1010];
vector<int> graph[1010];

int main(void) {
    freopen("i.in", "r", stdin);
    while(scanf("%d%d%d", &n, &m, &k) == 3) {
        REP(i, n+1) {
            graph[i].clear(); vis[i] = 0;
        }
        REP(i, m) {
            scanf("%d%d", &a, &b);
            graph[a].push_back(b);
      //     graph[b].push_back(a);
        }
        vector<int> ans;
        REP(i, n) {
            if(graph[i].size() >= k) {
                vector<int> tmp;
                tmp.push_back(i);
                REP(j, graph[i].size()) {
                    if(graph[graph[i][j]].size() >= k) {
                        tmp.push_back(graph[i][j]);
                    }
                }
                if(tmp.size() > ans.size()) ans = tmp;
            }
        }
        if(ans.size() == 0) {
            printf("0\n");
        } else {
            REP(i, ans.size()) {
                if(i == ans.size()-1) {
                    printf("%d\n", ans[i]);
                } else {
                    printf("%d ", ans[i]);
                }
            }
        }
    }
    return 0;
}



