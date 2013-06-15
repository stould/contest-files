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

int k, f[1000000];
string s;

ll ans = 0;

int main(void) {
    memset(f, 0, sizeof(f));
    cin >> k >> s;
    int ct = 0;
    f[0] = 1;
    for(int i = 0; i < (int) s.size(); i++) {
        if(s[i] == '1') {
            ct += 1;
        }
        if(ct >= k) ans += (ll) f[ct - k];
        f[ct] += 1;
    }
    cout << ans << endl;

    return 0;
}

