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

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }

using namespace std;

typedef long long ll;
typedef unsigned uint;

const int MAXN = 107;
int N, M;
int vis_N[MAXN], vis_M[MAXN];

int main(void) {
    int i, j;

    scanf("%d%d", &N, &M);

    memset(vis_N, 0, sizeof(vis_N));
    memset(vis_M, 0, sizeof(vis_M));

    vector<pair<int, int> > vp;

    for (i = 1; i <= N; i++) {
        for (j = 1; j <= M; j++) {
            if (!vis_N[i] || !vis_M[j]) {
                vp.push_back(make_pair(i, j));
                vis_N[i] = vis_M[j] = 1;
            }
        }
    }

    printf("%d\n", (int) vp.size());

    for (i = 0; i < (int) vp.size(); i++) {
        printf("%d %d\n", vp[i].first, vp[i].second);
    }

    return 0;
}
