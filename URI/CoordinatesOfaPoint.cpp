#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <numeric>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

#define REP(i, n) for(int (i) = 0; i < n; i++)
#define FOR(i, a, n) for(int (i) = a; i < n; i++)
#define FORR(i, a, n) for(int (i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

using namespace std;

typedef long long ll;
typedef long double ld;

double x, y;

int main(void) {
    for ( ; scanf("%lf%lf", &x, &y) == 2; ) {
        if (x == 0.0 && y == 0.0) {
            puts("Origem");
        } else if (y == 0.0) {
            puts("Eixo X");
        } else if (x == 0.0) {
            puts("Eixo Y");
        } else if (x < 0.0) {
            if (y > 0.0) {
                puts("Q2");
            } else {
                puts("Q3");
            }
        } else {
            if (y > 0.0) {
                puts("Q1");
            } else {
                puts("Q4");
            }
        }
    }
    return 0;
}
