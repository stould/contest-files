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

const int MAXN = 1000010

trapezio tr[MAXN];
int n, all = 0;

struct trapezio {
    int peso, forca, index;
    trapezio(){}
    trapezio(int peso, int forca, int index): peso(peso), forca(forca), index(index){}
    bool operator<(const trapezio& t) const {
        if(forca != t.forca) return forca > t.forca;
        if(peso != t.peso) return peso < t.peso;
        return index < t.index;
    }
};

int main(void) {
    scanf("%d", &n);
    REP(i, n) {
        scanf("%d%d", &tr[i]., &tr[i].second);
        all += tr[i].first;
    }

    return 0;
}

