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

#define REP(i, n) for(int (i) = 0; i < n; i++)
#define FOR(i, a, n) for(int (i) = a; i < n; i++)
#define FORR(i, a, n) for(int (i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 55;
int N, M, A, O, D, S, capacity[MAXN][MAXN], prev[MAXN], dist[MAXN], on[MAXN];
vector<int> graph[MAXN];

pair<vector<int>, int> least_path(void) {
    queue<int> q; q.push(1);

    for(int i = 0; i < MAXN; i++) {
        prev[i] = -1;
        dist[i] = INT_MAX;
    }

    dist[1] = 0;

    while(!q.empty()) {
        int now = q.front(); q.pop();

        for(int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];

            if(dist[next] > dist[now] + 1) {
                dist[next] = dist[now] + 1;
                prev[next] = now;
                q.push(next);
            }
        }
    }

    if(dist[N] == INT_MAX) return make_pair(vector<int>(), -1);

    vector<int> ans;
    int now = N, poss = INT_MAX;

    while(now != -1) {
        ans.push_back(now);
        int shold = now;
        now = prev[now];
        if(now == -1) continue;
        poss = min(poss, capacity[now][shold]);
        graph[now].erase(find(graph[now].begin(), graph[now].end(), shold));
    }

    reverse(ans.begin(), ans.end());

    return make_pair(ans, poss);
}

int main(void) {
    freopen("i.in", "r", stdin);
    while(3 == scanf("%d%d%d", &N, &M, &A) && (N + M + A) != 0) {
        REP(i, N) {
            graph[i].clear();
            REP(j, N) capacity[i][j] = 0;
        }
        REP(i, M) {
            scanf("%d%d%d", &O, &D, &S);
            graph[O].push_back(D);
            capacity[O][D] += S;
        }
        map<vector<int>, int> mp;
        map<vector<int>, int>::iterator it;
        while(1) {
            pair<vector<int>, int> v = least_path();

            if(v.second == -1) break;

            printf("%d -> ", v.second);

            for(int i = 0; i < v.first.size(); i++) {
                printf("%d ", v.first[i]);
            }
            printf("\n");

            mp.insert(v);
        }

        int answer = mp.begin()->second * A;;
        printf("%d\n", answer);
    }
    return 0;
}
