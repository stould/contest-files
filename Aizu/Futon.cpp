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

int N, x, y;
char c;
map<int, int> head, foot;

int main(void) {
    int i;
    for ( ; scanf("%d", &N) == 1 && N != 0; ) {
        bool ok = true;

        for (i = 0; i < N; i++) {
            scanf("%d%d%c", &x, &y, &c);
            if (c == 'x') {
                if (head[x]) ok = false;
                head[x] = 1;
            }
        }

        if (ok) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
