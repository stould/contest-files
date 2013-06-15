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

int N;
char str[100009];

int main(void) {
    scanf("%d%s", &N, str);
    int H = 0, M = 0;

    REP(i, N - 1) {
        if(str[i] == 'H') H++;
        else M++;
    }
    if(H == M) {
        if(N - 2 >= 0 && str[N-2] == 'H') H -= 1;
        else if(N - 2 >= 0 && str[N-2] == 'M') M -= 1;
    }
    if(H > M) puts("H");
    else if(H < M) puts("M");
    else puts("HM");
    return 0;
}
