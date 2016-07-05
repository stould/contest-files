#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <functional>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <valarray>
#include <vector>
#include <utility>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define REP(i, n) for((i) = 0; (i) < (n); i++)
#define FOR(i, a, n) for((i) = (a); (i) < (n); i++)
#define all(a) a.begin(), a.end()

using namespace std;

const int INF = 1000000000;
const double PI = acos(-1);

typedef long long ll;

int i, tmp, a, b;

int main(void) {
    while(scanf("%d%d", &a, &b) == 2 && !(a == 0 && b == 0)) {
        vector<int> sa, sb;
        set<int> checkA, checkB;
        REP(i, a) {
            scanf("%d", &tmp); sa.push_back(tmp);
        }
        REP(i, b) {
            scanf("%d", &tmp); sb.push_back(tmp);
            if(!binary_search(all(sa), sb[i])) {
                checkA.insert(sb[i]);
            }
        }
        REP(i, a) {
            if(!binary_search(all(sb), sa[i])) {
                checkB.insert(sa[i]);
            }
        }
        printf("%d\n", (int) min(checkA.size(), checkB.size()));
    }
    return 0;
}

