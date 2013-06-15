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

const int MAXN = 300009;
int N, M, pointer, a[MAXN], handle[MAXN];

int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%d%d", &N, &M);
    REP(i, N) {
        scanf("%d", &a[i]);
        if(i > 0) {
            a[i] = min(a[i - 1], a[i]);
        }
    }

    REP(i, M) {
        scanf("%d", &handle[i]);
    }

    int pos = 0, last = 0;

    for(int i = N - 1; i >= 0; i--) {
        if(pos >= M) break;
        if(a[i] >= handle[pos]) {
            pos += 1;
            last = i;
        }
    }
    printf("%d\n", pos != M ? 0 : last + 1);
    return 0;
}
