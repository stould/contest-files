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

const int MAXN = 1000009;
int N, a[MAXN], b[MAXN], ans = INT_MAX;

int recur(int i, int j, int spent) {
    if(i < 0 && j < 0) {
        ans = min(ans, spent);
        return 0;
    }

    if(a[i] != b[j]) {
        return recur(i - 1, j - 1, spent + 1);
    } else {
        return min(recur(i - 1, j, spent + 1), recur(i, j - 1, spent + 1));
    }
}

int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%d", &N);
    REP(i, N) {
        scanf("%d", &a[i]);
    }
    REP(i, N) {
        scanf("%d", &b[i]);
    }

    recur(N-1, N-1, 0);

    printf("%d\n", ans);
    return 0;
}
