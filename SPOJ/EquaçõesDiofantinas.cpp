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

const int MAXN = 1000000;
int T, N, C, ans;
map<int, map<int, int> > mp;

int rec(int now, int acc) {
    if(now > C || acc > N) return 0;

    mp[now][acc] += 1;

    for(int i = 0; i <= C; i++) {
        rec(now + i, acc + 1);
    }
}

int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%d", &T);
    N = C = 10;
    rec(0, 0);
    for( ; T--; ) {
        scanf("%d%d", &N, &C);
        printf("%d\n", mp[C][N]);
    }
    return 0;
}
