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

const int MAXN = 500009;
int N, ans;

struct Circle {
    int x, y, radius;

    bool operator<(const Circle& c) const {
        return (int) hypot(x - c.x, y - c.y);
    }

} array[MAXN];

int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%d", &N);
    REP(i, N) {
        scanf("%d%d%d", &array[i].x, &array[i].y, &array[i].radius);
    }
    sort(array, array + N);
    REP(i, N) {
        printf("%d %d %d\n", array[i].x, array[i].y, array[i].radius);
        FOR(j, i + 1, N) {
            double dis = hypot(array[i].x - array[j].x, array[i].y - array[j].y);
            if(dis == array[i].radius + array[j].radius) ans += 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
