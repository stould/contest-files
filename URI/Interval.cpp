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

double x;

int main(void) {
    scanf("%lf", &x);

    if (0.0 <= x && 25.0 >= x) {
        puts("Intervalo [0,25]");
    } else if (25.0 < x && x <= 50.0) {
        puts("Intervalo (25,50]");
    } else if (50.0 < x && x <= 75.0) {
        puts("Intervalo (50,75]");
    } else if (75.0 < x && x <= 100.0) {
        puts("Intervalo (75,100]");
    } else {
        puts("Fora de intervalo");
    }
    return 0;
}

