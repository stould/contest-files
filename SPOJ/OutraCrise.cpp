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

const int MAXN = 1e5 + 10;

int i, n, t;
vector<int> graph[MAXN];

int main(void) {
    while(scanf("%d%d", &n, &t) == 2 && !(n == 0 && t == 0)) {
        REP(i, n) graph[i].clear();
        REP(i, n) {
            scanf("%d", &tmp);
            graph[tmp].push_back(i);
        }
    }
    return 0;
}

