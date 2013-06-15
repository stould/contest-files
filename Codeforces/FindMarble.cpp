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

const int MAXN = 100007;
int N, S, T, now;
int next[MAXN] = {0}, vis[MAXN] = {0};

void dfs(int x, int prev) {
    vis[x] = vis[prev] + 1;

    if(!vis[next[x]]) dfs(next[x], x);
}

int main(void) {
    scanf("%d%d%d", &N, &S, &T);

    for(int i = 1; i <= N; i++) {
        scanf("%d", &now);
        next[i] = now;
    }

    dfs(S, 0);

    printf("%d\n", vis[T] != 0 ? vis[T] - 1: -1);
    return 0;
}
