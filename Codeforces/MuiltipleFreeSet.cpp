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

const int MAXN = 100009;
int N, K, ans, v[MAXN];
set<int> over;

int main(void) {
    scanf("%d%d", &N, &K);

    for(int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }

    sort(v, v + N);

    ans = 0;

    for(int i = N - 1; i >= 0; i--) if(!over.count(v[i])) {
        ans += 1;
        if(v[i] % K == 0) over.insert(v[i] / K);
    }

    printf("%d\n", ans);
    return 0;
}
