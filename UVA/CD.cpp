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
#include <numeric>
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

const int MAXN = 10009;
int N, T, v[MAXN];

int main(void) {
    while(scanf("%d%d", &N, &T) == 2) {
        REP(i, T) scanf("%d", &v[i]);

        int end_sum = -1, end_mask = -1;

        REP(i, (1<<T)) {
            int current_sum = 0, occur = 0;
            REP(j, T) {
                if((i >> j) & 1) {
                    current_sum += v[j];
                    occur += 1;
                }
            }
            if(current_sum >= end_sum && current_sum <= N) {
                end_sum = current_sum, end_mask = i;
            }
        }
        REP(i, T) if((end_mask >> i) & 1) {
            printf("%d ", v[i]);
        }
        printf("sum:%d\n", end_sum);
    }
    return 0;
}
