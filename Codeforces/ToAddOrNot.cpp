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

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = (int) (10e5);
int N, K, v[MAXN+10];
ll sum[MAXN+10];

int main(void) {
    scanf("%d%d", &N, &K);
    sum[0] = v[0] = 0;
    FOR(i, 1, N+1) {
        scanf("%d", &v[i]);
    }
    sort(v+1, v + N+1);
    FOR(i, 1, N+1) sum[i] = sum[i - 1] + v[i];
    int best = v[1], occur = 1;
    FOR(i, 2, N+1) {
        int low = 1, high = i - 1, mid, where = i;
        ll tmp_cost;
        while(low <= high) {
            mid = (low + high)/ 2;
            tmp_cost = v[i]  * (ll) (i - mid + 1) - (sum[i] - sum[mid-1]);

            if(tmp_cost <= (ll) K) {
                high = mid - 1;
                where = mid;
            } else {
                low = mid + 1;
            }
        }
        printf("%d %d %lld\n", (int) i - where + 1, v[i], tmp_cost);
        if(i - where + 1 > occur) {
            occur = i - where + 1;
            best = v[i];
        }
    }
    printf("%d %d\n", occur, best);
    return 0;
}

