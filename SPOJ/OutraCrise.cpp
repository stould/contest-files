#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <functional>
#include <valarray>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <climits>

using namespace std;

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;

const int MAXN = 10007;

int N, T;
vector<int> graph[MAXN];

int main(void) {
    int i, x;

    for ( ; scanf("%d%d", &N, &T) == 2 && N + T != 0; ) {
        for (i = 0; i < N; i++) raph[i].clear();

        for (i = 0; i < N; i++) {
            scanf("%d", &x);
            graph[x].push_back(i);
        }
    }
    return 0;
}
