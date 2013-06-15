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

int n, v[1010];

int main(void) {
    while(scanf("%d", &n) == 1 && n != 0) {
        while(1) {
            scanf("%d", &v[0]);
            if(!v[0]) break;
            FOR(i, 1, n) {
                scanf("%d", &v[i]);
            }
            int now = 0;
            stack<int> s;
            FOR(i, 1, n+1) {
                s.push(i);
                while(!s.empty() && s.top() == v[now]) {
                    now += 1;
                    s.pop();
                }
            }
            if(s.empty()) {
                puts("Yes");
            } else {
                puts("No");
            }
        }
        puts("");
    }
    return 0;
}

