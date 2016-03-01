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
 
const int MAXN = 10007;
int T, N, F;
int v[MAXN];
 
double PI = 3.14159265358979323846264338327950;
 
int main(void) {
    //freopen("i.in", "r", stdin);
    T = in();
 
    int i, x, o_id;
 
    for ( ; T--; ) {
        N = in(), F = in();
 
        for (i = 0; i < N; i++) {
            v[i] = in();
            v[i] = (double) (v[i] * v[i]);
        }
 
        sort(v, v + N);
 
 
        double l = 0.0, h = v[N-1], m, ans = 0.0;
 
        for (x = 0; x < 1000; x++) {
            m = l + (h - l) / 2.0;
 
            int cnt = 0;
 
            for (i = 0; i < N; i++) {
                if (v[i] >= m) {
                    cnt += (int) floor(v[i] / m);
                }
            }
 
            if (cnt < F + 1) {
                h = m;
            } else {
                l = m;
            }
        }
 
//        printf("%.4lf %.4lf %.4lf\n", l, m, h);
 
        printf("%.4lf\n", l * PI);
    }
    return 0;
}
