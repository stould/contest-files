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

const int MAXN = 110;
int N, S, T, d[MAXN], prev[MAXN], next[MAXN];

int main(void) {
    scanf("%d", &N);
    REP(i, N) {
        scanf("%d", &d[i]);

        next[i] = i + 1 == N ? 0 : i + 1;
        prev[i] = i - 1 == -1 ? N - 1 : i - 1;
    }

    scanf("%d%d", &S, &T);

    int further = 0, comeback = 0;

    for(int now = S - 1; now != T - 1; now = next[now]) {
        further += d[now];
    }

    for(int now = prev[S - 1]; now != prev[T - 1]; now = prev[now]) {
        comeback += d[now];
    }

    printf("%d\n", min(further, comeback));

    return 0;
}
