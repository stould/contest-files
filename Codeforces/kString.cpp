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
#include <limits.h>

using namespace std;

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;

int i, k, ct[26];
string s, ans = "";

int main(void) {
    cin >> k >> s;
    memset(ct, 0, sizeof(ct));
    REP(i, s.size()) ct[s[i]-'a'] += 1;
    bool ok = s.size() % k == 0;
    REP(i, 26) {
        if(ct[i] != 0 && ct[i] % k != 0) {
            ok = false;
            break;
        } else if(ct[i] != 0 && ct[i] % k == 0) {
            for(int j = 0; j < ct[i] / k; j++) {
                ans += 'a' + i;
            }
        }
    }
    if(ok) {
        REP(i, k) {
            cout << ans;
        } cout << "\n";
    } else {
        cout << -1 << "\n";
    }
    return 0;
}
