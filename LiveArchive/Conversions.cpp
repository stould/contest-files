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

int N, test = 1;
double V;
char str[5];

double kg_to_lb (double x) {
    return x * 2.2046;
}

double lb_to_kg (double x) {
    return x * 0.4536;
}

double l_to_g (double x) {
    return x * 0.2642;
}

double g_to_l (double x) {
    return x * 3.7854;
}

int main(void) {
    scanf("%d", &N);

    for ( ; N--; ) {
        scanf("%lf%s", &V, str);

        printf("%d ", test++);

        if (!strcmp(str, "kg")) {
            printf("%.4lf lb\n", kg_to_lb(V));
        } else if (!strcmp(str, "lb")) {
            printf("%.4lf kg\n", lb_to_kg(V));
        } else if (!strcmp(str, "l")) {
            printf("%.4lf g\n", l_to_g(V));
        } else if (!strcmp(str, "g")) {
            printf("%.4lf l\n", g_to_l(V));
        }
    }
    return 0;
}
