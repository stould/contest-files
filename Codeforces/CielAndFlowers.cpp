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

using namespace std;

typedef long long Int;
typedef unsigned uint;

int R, G, B;

Int funcA(int R, int G, int B) {
    Int ans = (Int) min(R, min(G, B));

    R -= ans;
    G -= ans;
    B -= ans;

    if (R > 0) ans += (Int) floor(R / 3);
    if (G > 0) ans += (Int) floor(G / 3);
    if (B > 0) ans += (Int) floor(B / 3);

    return ans;
}

Int funcB(int R, int G, int B) {
    return (Int) floor (R / 3) + floor (G / 3) + floor (B / 3);
}

int main(void) {
    scanf("%d%d%d", &R, &G, &B);

    printf("%lld\n", max(funcA(R, G, B), funcB(R, G, B)));

    return 0;
}
