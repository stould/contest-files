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

int n;
int dp[10][10] = {0};
char graph[10][10];


int main(void) {
    freopen("i.in", "r", stdin);
//    freopen("hshoe.out", "w", stdout);
    int i, j, ans = -1;
    scanf("%d", &n);
    REP(i, n) scanf("%s", graph[i]);
    REP(i, n) REP(i, n) {
        if(graph[i][j])
        dp[i][j] =
    }
    printf("%d", ans);
    return 0;
}
