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

int N, cnt[26] = {0};
char str[100010];
char c[5] = "ACGT";
set<char> s;

int main(void) {
    scanf("%d %s", &N, str);

    int base = 0;

    string ans = "";

    FOR(i, base, N) {
        cnt[str[i]-'A'] += 1;
        s.insert(str[i]);
    }
    if(s.size() != 4) {
        printf("%d\n", 0);
        REP(i, 4) if(!s.count(c[i])) {
            REP(j, N) putchar(c[i]);
            break;
        }
    } else {
        int last = INT_MAX, index = -1;
        REP(i, 26) if(cnt[i] < last && cnt[i] != 0) last = cnt[i], index = i;
        printf("%d\n", last);
        REP(i, N) putchar('A'+index);
    }
    return 0;
}

