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

int i, tmp, n, m, a, b;
priority_queue<int, vector<int>, greater<int> > high;
priority_queue<int, vector<int>, less<int> > low;


int main(void) {
    scanf("%d%d", &n, &m);
    REP(i, m) {
        scanf("%d", &tmp);
        high.push(tmp);
        low.push(tmp);
    }
    a = b = 0;
    tmp = n;
    while(tmp > 0) {
        int mx = low.top(); low.pop();
        a += mx; mx -= 1; tmp -= 1;
        if(mx > 0) low.push(mx);
    }
    tmp = n;
    while(tmp > 0) {
        int mx = high.top(); high.pop();
        b += mx; mx -= 1; tmp -= 1;
        if(mx > 0) high.push(mx);
    }
    printf("%d %d\n", a, b);
    return 0;
}

