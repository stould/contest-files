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

int dot(int A[], int B[], int C[]) {
    int AB[2];
    int BC[2];
    AB[0] = B[0]-A[0];
    AB[1] = B[1]-A[1];
    BC[0] = C[0]-B[0];
    BC[1] = C[1]-B[1];
    int dot = AB[0] * BC[0] + AB[1] * BC[1];
    return dot;
}
int cross(int A[], int B[], int C[]) {
    int AB[2];
    int AC[2];
    AB[0] = B[0]-A[0];
    AB[1] = B[1]-A[1];
    AC[0] = C[0]-A[0];
    AC[1] = C[1]-A[1];
    int cross = AB[0] * AC[1] - AB[1] * AC[0];
    return cross;
}
double distance(int A[], int B[]) {
    int d1 = A[0] - B[0];
    int d2 = A[1] - B[1];
    return (double) sqrt(d1*d1+d2*d2);
}
double linePointDist(int A[], int B[], int C[], bool isSegment) {
    double dist = cross(A,B,C) / distance(A,B);
    if(isSegment) {
        int dot1 = dot(A,B,C);
            if(dot1 > 0)return distance(B,C);
        int dot2 = dot(B,A,C);
        if(dot2 > 0)return distance(A,C);
    }
    return abs(dist);
}

int N, XC, YC, R, XI, YI, XJ, YJ, ans = 0;

int main(void) {
    scanf("%d%d%d%d", &N, &XC, &YC, &R);
    int tc[2] = {XC, YC};
    REP(i, N) {
        scanf("%d%d%d%d", &XI, &YI, &XJ, &YJ);
        int ta[2] = {XI, YI};
        int tb[2] = {XJ, YJ};
        double tmp = linePointDist(ta, tb, tc, false);
        if(tmp <= R) {
            ans += 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
