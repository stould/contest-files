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
#include <numeric>
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

int in(void) { int x; scanf("%d", &x); return x; }

const int MAXN = 107;
int N, C, K;
int buff[MAXN];

int main(void) {
    //freopen("i.in", "r", stdin);
    int i, j;
    for ( ; scanf("%d%d%d", &N, &C, &K) == 3 && N + C + K != 0; ) {
        memset(buff, 0, sizeof(buff));

        int least = INT_MAX;

        for (i = 0; i < N; i++) {
            for (j = 0; j < C; j++) {
                buff[in()] += 1;
            }
        }

        for (i = 1; i <= K; i++) least = min(least, buff[i]);

        vector<int> ans;

        for (i = 1; i <= K; i++) {
            if (buff[i] == least) {
                ans.push_back(i);
            }
        }

        for (i = 0; i < (int) ans.size(); i++) {
            printf("%d", ans[i]);
            if (i != ans.size() - 1) {
                printf(" ");
            } else {
                printf("\n");
            }
        }
    }
    return 0;
}
