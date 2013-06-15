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

#define REP(i, n) for((i) = 0; i < n; i++)
#define FOR(i, a, n) for((i) = a; i < n; i++)
#define FORR(i, a, n) for((i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long ll;
typedef long double ld;

int i, x, n, len, ans;
char str[1010];

int main(void) {
    scanf("%d", &n);
    REP(x, n) {
        scanf("%s", str);
        len = strlen(str);
        stack<char> s;
        ans = 0;
        REP(i, len) {
            if(str[i] == '<') {
                s.push('<');
            } else if(str[i] == '>') {
                if(!s.empty()) {
                    s.pop();
                    ans += 1;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

