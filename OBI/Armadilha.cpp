#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <functional>
#include <valarray>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

using namespace std;

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

typedef long long ll;
typedef long double ld;

int j, q, da, db, ta, tb, tc, t = 1;

bool ok = true;

int main(void) {
    while(1) {
        cin >> j >> q;
        if(j == 0 && q == 0) break;

        cin >> ta >> tb >> tc;
        int pos[j];
        int trap[j];

        memset(pos, 0, sizeof(pos));
        memset(trap, 0, sizeof(pos));

        int actual = 0;

        while(1) {
            if(trap[actual % j] == 1) {
                trap[actual % j] = 0;
                actual += 1;
                continue;
            }
            cin >> da >> db;
            int sum = da + db;

            pos[actual % j] += sum;
            if(pos[actual % j] == ta || pos[actual % j] == tb || pos[actual % j] == tc) {
                trap[actual % j] = 1;
            }

            if(pos[actual % j] > q) {
                break;
            }
            actual += 1;
        }
        cout << "Teste " << (t++) << endl << (actual % j) + 1 << endl << endl;;
    }
    return 0;
}

