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

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

double EPS = 1e-8;
double A, B, C;

bool eq(double a, double b) {
	return fabs(a - b) < EPS;
}

int main(void) {
    cin >> A >> B >> C;

    if (A < B) swap(A, B);
    if (A < C) swap(A, C);
    if (B < C) swap(B, C);

    if (A > B + C - EPS) {
        puts("NAO FORMA TRIANGULO");
    } else {
        if (eq(A * A, B * B + C * C)) {
            puts("TRIANGULO RETANGULO");
        }
        if (A * A > B * B + C * C) {
            puts("TRIANGULO OBTUSANGULO");
        }
        if (A * A < B * B + C * C) {
            puts("TRIANGULO ACUTANGULO");
        }
        if (eq(A, B) && eq(A, C) && eq(B, C)) {
            puts("TRIANGULO EQUILATERO");
        }
        if ((eq(A, B) && !eq(B, C)) || (eq(B, C) && !eq(A, B)) || (eq(A, C) && !eq(B, A))) {
            puts("TRIANGULO ISOSCELES");
        }
    }

    return 0;
}
