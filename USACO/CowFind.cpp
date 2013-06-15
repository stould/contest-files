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

vector<int> kmp(const string &needle, const string &haystack) {
    int m = needle.size();
    vector<int> border(m + 1), ans;
    border[0] = -1;
    for (int i = 0; i < m; ++i) {
        border[i+1] = border[i];
        while (border[i+1] > -1 and needle[border[i+1]] != needle[i]) {
            border[i+1] = border[border[i+1]];
        }
        border[i+1]++;
    }
    int n = haystack.size();
    int seen = 0;
    for (int i = 0; i < n; ++i) {
        while (seen > -1 and needle[seen] != haystack[i]) {
            seen = border[seen];
        }
        if (++seen == m) {
            ans.push_back(i - m + 1);
            seen = border[m];
        }
    }
    return ans;
}

string str;

int main(void) {
    freopen("cowfind.in", "r", stdin);
    freopen("cowfind.out", "w", stdout);
    cin >> str;
    int i, j;
    vector<int> l = kmp("((", str), r = kmp("))", str);
    set<pair<int, int> > sp;
    REP(i, l.size()) REP(j, r.size()) {
        if(l[i] < r[j]) sp.insert(make_pair(l[i], r[j]));
    }
    printf("%d", (int)sp.size());
    return 0;
}
