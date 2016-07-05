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

int i, j;
string str;
int main(void) {
    while(getline(cin, str)) {
        if(str == "*") break;
        set<char> s;
        REP(i, str.size()) {
            s.insert(tolower(str[i]));
            int j = i + 1;
            while(j < str.size() && str[j] != ' ') {
                j += 1;
            }
            i = j;
        }
        if(s.size()==1) {
            puts("Y");
        } else {
            puts("N");
        }
    }
    return 0;
}


