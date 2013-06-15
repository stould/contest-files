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
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <climits>

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

#define MAXN 10100

int i, n, l, h, yi[MAXN], xf[MAXN], yf[MAXN];
double ans;

double dot(pair<int, int> &A, pair<int, int> &B, pair<int, int> &C) {
    return (double) (B.first - A.first) * (C.first - B.first) + (B.second - A.second) * (C.second - B.second);
}

double cross(pair<int, int> &A, pair<int, int> &B, pair<int, int> &C) {
    return (double) (B.first-A.first) * (C.second-A.second) - (B.second-A.second) * (C.first-A.first);
}

double _distance(pair<int, int> A, pair<int, int> B) {
    int d1 = A.first - B.first;
    int d2 = A.second - B.second;
    return sqrt(d1*d1+d2*d2);
}

double linePointDist(pair<int, int> A, pair<int, int> B, pair<int, int> C, bool isSegment) {
    double dist = cross(A,B,C) / _distance(A,B);
    if(isSegment) {
        int dot1 = dot(A,B,C);
        if(dot1 > 0)return _distance(B,C);
        int dot2 = dot(B,A,C);
        if(dot2 > 0)return _distance(A,C);
    }
    return abs(dist);
}

int main(void) {
    while(scanf("%d%d%d", &n, &l, &h) == 3) {
        ans = 10000000000.0;
        REP(i, n) {
            scanf("%d%d%d", &yi[i], &xf[i], &yf[i]);
        }
        REP(i, n-1) {
            if(i % 2 == 0) {
                ans = min(ans, hypot(xf[i] - l, 0));
                ans = min(ans, linePointDist(make_pair(xf[i+1], yf[i+1]), make_pair(l, yi[i+1]), make_pair(xf[i], yf[i]), true));
            } else {
                ans = min(ans, hypot(0 - xf[i], 0));
                ans = min(ans, linePointDist(make_pair(xf[i+1], yf[i+1]), make_pair(0, yi[i+1]), make_pair(xf[i], yf[i]), true));
            }
        }
        if((n-1)%2==0) {
            ans = min(ans, hypot(xf[n-1] - l, 0));
        } else {
            ans = min(ans, hypot(0 - xf[n-1], 0));
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}

