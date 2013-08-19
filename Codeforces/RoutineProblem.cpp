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

int A, B, C, D;

int expandA(void) {
    int i, step = 0;

    if (A >= C && B >= D) return 0;

    for (i = 1; ; i++) {
        int nA = A * i;
        int nB = B * i;

        if (nA >= C && nB >= D) {
            A = nA;
            B = nB;
            break;
        }
    }

    return 1;
}

void expandB(void) {
    int i;

    for (i = 1; ; i++) {
        int nC = C * i;
        int nD = D * i;

        if (nC >= A && nD >= B) {
            C = nC;
            D = nD;
            break;
        }
    }
}

void reduce(int& x, int &y) {
    int r = gcd(x, y);

    //if (r == x || r == y) return;

    x /= r;
    y /= r;
}

int main(void) {
    A = in(), B = in(), C = in(), D = in();

    int x = gcd(A, B), y = gcd(C, D);

    A /= x; B /= x;
    C /= y; D /= y;

    if (A * B == C * D) {
        printf("%d/%d\n", 0, 1);
    } else {
        if (A / B < C / D) {

        } else {

        }
    }
    return 0;
}
