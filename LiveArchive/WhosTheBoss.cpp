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

const int MAXN = 300010;
int T, M, Q, id, sal, ta;
vector<int> graph[MAXN];

int parent[MAXN] = {-1};

int i_id[MAXN];
int id_i[MAXN];

int dp[MAXN];

int dfs(int now) {
    int ans = 1;
    REP(i, graph[now].size()) {
        ans += dfs(graph[now][i]);
    }
    return dp[now] = ans;
}

struct employee {
    int id, salary, tall;

    employee(){}
    employee(int _id, int _salary, int _tall) {
        id = _id; salary = _salary; tall = _tall;
    }
    bool operator<(const employee& e) const {
        return salary > e.salary;
    }
};

employee ve[MAXN];

inline void fastRead_int(int &x) {
    register int c = getchar_unlocked();

    x = 0;

    int neg = 0;

    for (; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if (c=='-') {
        neg = 1;
        c = getchar_unlocked();
    }

    for ( ; c>47 && c<58 ; c = getchar_unlocked()) {
        x = (x<<1) + (x<<3) + c - 48;
    }

    if (neg) {
        x = -x;
    }
}

int main(void) {
    fastRead_int(T);
    for( ; T-- ; ) {
        fastRead_int(M);
        fastRead_int(Q);

        REP(i, M) {
            graph[i].clear();
            parent[i] = -1;
        }
        REP(i, M) {
            fastRead_int(id);
            fastRead_int(sal);
            fastRead_int(ta);
            i_id[i] = id;
            id_i[id] = i;
            ve[i] = employee(i, sal, ta);
        }

        sort(ve, ve + M);

        int root = ve[0].id;
        for(int i = 1; i < M; i++) {
            for(int j = i - 1; j >= 0; j--) {
                if(ve[i].salary < ve[j].salary && ve[i].tall <= ve[j].tall) {
                    parent[ve[i].id] = ve[j].id;
                    graph[ve[j].id].push_back(ve[i].id);
                    break;
                }
            }
        }
        dfs(root);
        REP(i, Q) {
            fastRead_int(id);
            id = id_i[id];
            int boss = parent[id], go = dp[id]-1;
            boss = i_id[boss];
            if(boss == -1) boss = 0;
            printf("%d %d\n", boss, go);
        }
    }
    return 0;
}
