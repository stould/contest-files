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

int K, done;
int v[17];

int main(void) {
    int i, j, k, l, m, n;
    done = 0;

    for ( ; scanf("%d", &K) == 1 && K != 0; ) {
        if (done) {
            printf("\n");
        }

        done += 1;

        for (i = 0; i < K; i++) scanf("%d", &v[i]);

        for (i = 0; i < K; i++) {
            for (j = i + 1; j < K; j++) {
                for (k = j + 1; k < K; k++) {
                    for (l = k + 1; l < K; l++) {
                        for (m = l + 1; m < K; m++) {
                            for (n = m + 1; n < K; n++) {
                                printf("%d %d %d %d %d %d\n", v[i], v[j], v[k], v[l], v[m], v[n]);
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
