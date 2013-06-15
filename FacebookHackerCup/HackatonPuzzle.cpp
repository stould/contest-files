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

int N, K;

vector<string> vstr;

int func(string str) {
    int i, ans = 0;

    for (i = 0; i < (int) str.size(); i++) ans += (str[i] == '1');

    return ans;
}

int to_int(string str) {
    int i, ans = 0;

    for (i = str.size() - 1; i >= 0; i--) if(str[i] == '1') {
        ans += 1 << (str.size() - i - 1);
    }

    return ans;
}

bool cmp(string a, string b) {
    int now_a = func(a), now_b = func(b);

    if(now_a != now_b) return now_a < now_b;
    else return to_int(a) < to_int(b);
}

int main(void) {
    int i, j;
    scanf("%d%d", &N, &K);

    for (i = 0; i < (1 << N); i++) {
        string now(N, '0');
        for (j = 0; j < N; j++) if ((i >> j) & 1) {
            now[j] = '1';
        }
        vstr.push_back(now);
    }

    sort(vstr.begin(), vstr.end(), cmp);

    printf("%s\n", vstr[K-1].c_str());

    return 0;
}
