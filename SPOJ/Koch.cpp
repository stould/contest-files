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


int main(void) {
    int a[10] = {0};
    for(int i = 100; i <= 125; i++) {
        int tmp = i;
        while(tmp > 0) {
            a[tmp % 10] += 1;
            tmp /= 10;
        }
    }
    for(int i = 200; i <= 225; i++) {
        int tmp = i;
        while(tmp > 0) {
            a[tmp % 10] += 1;
            tmp /= 10;
        }
    }
    int ans = 0;
    for(int i = 0; i <= 9; i++) ans = max(ans, a[i]);
    printf("%d\n", ans);
    return 0;
}

