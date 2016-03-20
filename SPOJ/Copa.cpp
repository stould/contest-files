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

using namespace std;

const int INF = 1000000000;
const double PI = acos(-1);

typedef long long ll;

int a, b, i;

int main(void) {
    vector<char> win;
    int index = 0;
    REP(i, 8) {
        scanf("%d%d", &a, &b);
        if(a > b) {
            win.push_back('A'+index);
        } else {
            win.push_back('A'+index+1);
        }
        index += 2;
    }
    index = 0;
    vector<char> win2;
    REP(i, 4) {
        scanf("%d%d", &a, &b);
        if(a > b) {
            win2.push_back(win[index]);
        } else {
            win2.push_back(win[index + 1]);
        }
        index += 2;
    }
    index = 0;
    scanf("%d%d", &a, &b);
    char fa = a > b ? win2[index] : win2[index + 1];
    index += 2;
    scanf("%d%d", &a, &b);
    char fb = a > b ? win2[index] : win2[index + 1];
    scanf("%d%d", &a, &b);
    if(a > b) {
        printf("%c\n", fa);
    } else {
        printf("%c\n", fb);
    }
    return 0;
}

