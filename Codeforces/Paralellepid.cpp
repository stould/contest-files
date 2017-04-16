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
#define FOR(i, a, n) for((i) = (a); (i) <= (n); i++)

using namespace std;

const int INF = 1000000000;
const double PI = acos(-1);

typedef long long ll;

int gcd(int a, int b) {
    if(!b) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int i, j, k, a, b, c;

int main(void) {
    scanf("%d%d%d", &a, &b, &c);
    FOR(i, 1, 10000) {
        FOR(j, 1, 10000) {
            if(i*j == a) {
                k = c / j;
                if(i * k == c && i * k == b) {
                    printf("%d\n", i*4+j*4+k*4);
                    return 0;
                }
            }
            if(i*j == b) {
                k = b / j;
                if(i*k == a && j*k == c) {
                    printf("%d\n", i*4+j*4+k*4);
                    return 0;
                }
            }
            if(i*j == c) {
                k = a / i;
                if(i*k == a && j*k == b) {
                    printf("%d\n", i*4+j*4+k*4);
                    return 0;
                }
            }
        }
    }
    return 0;
}
