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

    return 0;
}
