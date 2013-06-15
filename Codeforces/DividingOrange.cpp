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

#define REP(i, n) for((i) = 0; i < n; i++)
#define FOR(i, a, n) for((i) = a; i < n; i++)
#define FORR(i, a, n) for((i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 30*30+10;
int n, k, tmp, pivot = 0, node[MAXN] = {0}, used[MAXN] = {0};

int main(void) {
    int i, j;
    scanf("%d%d", &n, &k);
    REP(i, k) { scanf("%d", &tmp); node[i] = tmp; used[tmp-1] = 1; }
    REP(i, k) {
        printf("%d ", node[i]);
        int cnt = 0;
        REP(j, n*k) {
            if(!used[j]) {
                printf("%d ", j + 1);
                used[j] = 1;
                cnt += 1;
            }
            if(cnt == n - 1) break;
        }
        printf("\n");
    }
    return 0;
}
