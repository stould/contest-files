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

int T, a[5], dp[110][5][15], N;
char s[109];
/*
//current position, type of the last ballon used, number of repeated ballons of type 'last', id of the last
int rec(int pos, int last, int repeated, int last_id) {
    if (pos >= N) return 0;
    if (repeated > 9) return 0;

    if (dp[pos][last][repeated] != -1) return dp[pos][last][repeated];

    int& ans = dp[pos][last][repeated] = 0;

    int now = s[pos] - 'a';


    //Use current ballon
    ans = a[now] + rec(pos + 1, now, repeated + 1, pos);

    if (now == last) {
        ans = max(ans, 2 * a[now] + rec(pos + 1, last, repeated + 1, pos));
    }

    //Igonore current ballon
    ans = max(ans, rec(pos + 1, last, repeated, last_id));

    return ans;
}

*/

int func(void) {
    queue<pair<int, int> > q;

    q.push(make_pair(-1, 0));

    int i;

    for ( ; !q.empty(); ) {
        pair<int, int> curr = q.front(); q.pop();

        int last = curr.first != -1 ? a[s[curr.first]-'a'] ? -1;

        for (i = curr.first + 1; i < N; i++) {
            int pos = a[s[i]-'a'];

            if (pos == last) {
                q.push(make_pair(i, curr.second + (min(a[last] * 2, a[last]))))
            }
        }
    }
}
int main(void) {
    int i, j, k;
    freopen("i.in", "r", stdin);
    scanf("%d", &T);

    for ( ; T--; ) {
        scanf("%d%d%d%s", &a[0], &a[1], &a[2], s);
        N = strlen(s);
        for (i = 0; i < 110; i++) {
            for (j = 0; j < 5; j++) {
                for (k = 0; k < 15; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        printf("%d\n", rec(0, 3, 0, -1));
    }
    return 0;
}
