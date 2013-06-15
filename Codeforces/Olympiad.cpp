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

const int MAXN = 1000010;
int i, n, k, tmp;
ll v[MAXN];
vector<ll> help;

int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%d%d", &n, &k);
    REP(i, n+1) v[i] = 0LL;
    REP(i, n) {
        scanf("%d", &tmp); v[i] += tmp;
    }
    REP(i, n) {
        scanf("%d", &tmp); v[i] += tmp;
        if(v[i] >= k) {
            help.push_back((ll)v[i]);
        }
    }
    sort(help.begin(), help.end());
    sort(v, v + n, greater<int>());
    int low, high;
    FOR(i, 0, n) {
        if(v[i] == help[help.size()-1]) {
            low = i + 1; break;
        }
    }
    REV(i, n-1, -1) {
        if(v[i] == help[0]) {
            high = i + 1; break;
        }
    }
    REP(i, n) {
        printf("%lld ", v[i]);
    }
    printf("\n");
    printf("%d %d\n", low, high);
    return 0;
}

