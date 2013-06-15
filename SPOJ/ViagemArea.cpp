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

#define REP(i, n) for((i) = 0; i < n; i++)
#define FOR(i, a, n) for((i) = a; i < n; i++)
#define FORR(i, a, n) for((i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long ll;
typedef long double ld;

int i, n, f, o, d, c, t, start, end;
char type;

struct edge {
    int o, d, c, t;
    edge(){}
    edge(int o, int d, int c, int t): o(o), d(d), c(c), t(t){}
    bool operator<(const edge& e) const {
        if(type == 'P') {

        } else {

        }
    }
};

int main(void) {
    scanf("%d%d%c%d%d", &n, &f, &type, &start, &end);
    vector<edge> ve;
    REP(i, n) {
        scanf("%d%d%d%d", &o, &d, &c, &t);
        ve.push_back(edge(o, d, c, t))
    }
    return 0;
}

