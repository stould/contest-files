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
int N, K, v[MAXN];

bool func(int goal) {
    int low = 0, high = N, mid;

    while(low <= high) {
        int mid = (low + high)/2;

        if(v[mid] == goal) return true;

        if(v[mid] < goal) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}

int main(void) {
    while(scanf("%d", &N) == 1) {
        REP(i, N) {
            scanf("%d", &v[i]);
        }
        scanf("%d", &K);
        REP(i, N) if(func(K - v[i])) {
            printf("%d %d\n", min(v[i], K - v[i]), max(v[i], K - v[i]));
            break;
        }
    }
    return 0;
}
