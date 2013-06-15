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

const int MAXN = 10010;
const int INF = 1000101010;
int N, K, v[MAXN];

int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%d%d", &N, &K);
    REP(i, K) scanf("%d", &v[i]);

    int low = 1, high = INF, mid;
    while(low <= high) {
        mid = (low + high) / 2;
        int count = 0;
        REP(i, K) {
            count += (int) floor(v[i] / mid);
        }
        if(count > N) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("%d\n", low);
    return 0;
}

