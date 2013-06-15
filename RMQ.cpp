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

const int MAXN = 20000;
const int INF = 10000000;

//0-Based Range Minimum Query Segment Tree
template<typename T>
struct SegmentTreeRMQ {
    pair<T, T> t[MAXN*4];
    void build(T a[], int v, int tl, int tr) {
        if (tl == tr) t[v].first = a[tl];
        else {
            int tm = (tl + tr) >> 1;
            build (a, 2*v,tl,tm);
            build (a, 2*v+1,tm+1,tr);
            t[v].first = min (t[2*v].first,t[2*v+1].first);
        }
    }

    void update(int v, int tl, int tr, int l, int r, T value) {
        if (l > r) return;
        if (tl == l && r == tr) {
            t[v].second += value;
        } else {
            int tm = (tl + tr) >> 1;
            update (2*v,tl,tm,l,min(tm,r),value);
            update (2*v+1,tm+1,tr,max(tm+1,l),r,value);
            t[v].first = min (t[2*v].first + t[2*v].second,t[2*v+1].first + t[2*v+1].second);
        }
    }
    T rmq (int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return INF;
        }
        if (tl == l && tr == r) {
            return t[v].first + t[v].second;
        } else {
            int tm = (tl + tr) >> 1;
            t[v].first = min (t[2*v].first + t[2*v].second,t[2*v+1].first + t[2*v+1].second);
            return min(rmq(2*v,tl,tm,l,min(tm,r)),rmq(2*v+1,tm+1,tr,max(l,tm+1),r))+t[v].second;
        }
    }
};

int main(void) {
    return 0;
}
