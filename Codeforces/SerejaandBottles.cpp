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

const int MAXN = 1100;
int N, a[MAXN], b[MAXN];

int main(void) {
    scanf("%d", &N);

    int i, j;

    for (i = 0; i < N; i++) {
        scanf("%d%d", &a[i], &b[i]);
    }

    int ans = 0;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) if (i != j) {
            if (a[i] == b[j]) {
                ans += 1;
                break;
            }
        }
    }

    printf("%d\n", N - ans);

    return 0;
}
