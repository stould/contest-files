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

const int MAXN = 525;
int N, M;
char str[MAXN];

bool isletter(char c) {
    char cc = tolower(c);
    return cc >= 'a' && cc <= 'z';
}

int main(void) {
    freopen("i.in", "r", stdin);
    freopen("o.ot", "w", stdout);
    scanf("%d", &M);
    gets(str);
    REP(x, M) {
        ll ans = 0LL;
        map<char, int> mp;
        map<char, int>::iterator it;
        gets(str);
        N = strlen(str);
        REP(i, N) if(isletter(str[i])) {
            mp[tolower(str[i])] += 1;
        }
        vector<int> memo;
        for_each(it, mp) memo.push_back(it->second);
        sort(memo.begin(), memo.end());
        int cnt = 26;
        for(int i = memo.size() - 1; i >= 0; i--) {
            ans += (ll) memo[i] * cnt;
            cnt -= 1;
        }
        printf("Case #%d: %lld\n", x + 1, ans);
    }
    return 0;
}
