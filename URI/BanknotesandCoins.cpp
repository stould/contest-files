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

double N;
int cnt;

void func(double x) {
    int cnt = 0;

    while (N - x >= 0.0) {
        N -= x;
        cnt += 1;
    }

    printf("%d nota(s) de R$ %.2lf\n", cnt, x);
}

void func2(double x) {
    int cnt = 0;

    while (N - x >= 0.0) {
        N -= x;
        cnt += 1;
    }

    printf("%d moeda(s) de R$ %.2lf\n", cnt, x);
}

int main(void) {
    scanf("%lf", &N);

    printf("NOTAS:\n");

    func(100.0);
    func(50.0);
    func(20.0);
    func(10.0);
    func(5.0);
    func(2.0);

    printf("MOEDAS:\n");

    func2(1.0);
    func2(0.50);
    func2(0.25);
    func2(0.10);
    func2(0.05);
    func2(0.01);

    return 0;
}
