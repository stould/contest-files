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

int N;

int main(void) {
    scanf("%d", &N);

    printf("Gnomes:\n");

    for ( ; N--; ) {
        vector<int> a(3), b(3), c(3);
        scanf("%d%d%d", &b[0], &b[1], &b[2]);

        a[0] = c[0] = b[0];
        a[1] = c[1] = b[1];
        a[2] = c[2] = b[2];

        sort (a.begin(), a.end()); sort (c.begin(), c.end()); reverse(c.begin(), c.end());

        if (a == b || b == c) {
            printf("Ordered\n");
        } else {
            printf("Unordered\n");
        }
    }

    return 0;
}
