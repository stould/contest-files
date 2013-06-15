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

const int MAXN = 1010;
int N, ans, next[MAXN], done[MAXN];


int main(void) {
    freopen("relay.in", "r", stdin);
    freopen("relay.out", "w", stdout);
    scanf("%d", &N);

    for(int i = 1; i <= N; i++) {
        scanf("%d", &next[i]);

        if(next[i] == 0) done[i] = 1;
        else done[i] = 0;
    }

    for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) {
        if(done[next[j]] == 1) done[j] = 1;
    }

    ans = 0;

    for(int i = 1; i <= N; i++) ans += done[i];

    printf("%d\n", ans);

    return 0;
}
