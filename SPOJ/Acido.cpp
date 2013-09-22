#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <iostream>
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

using namespace std;

const int INF = 1000000000;
const double PI = acos(-1);

typedef long long ll;

bool match(char a, char b) {
    if(a == 'B' && b == 'S') return true;
    if(b == 'B' && a == 'S') return true;
    if(a == 'C' && b == 'F') return true;
    if(b == 'C' && a == 'F') return true;
    return false;
}

int i, ans = 0, check;
string s;

int main(void) {
    ios::sync_with_stdio(false);
    while(cin >> s) {
        check = 1;
        ans = 0;
        while(check && s.size() >= 2) {
            check = 0;
            REP(i, s.size() - 1) {
                if(match(s[i], s[i + 1])) {
                    ans += 1;
                    s = s.substr(0, i) + s.substr(i + 2, s.size() - i + 1);
                    check = 1;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
