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

const int MAXN = 50010;
int N, maximal[MAXN], minimal[MAXN];
string tmp;
vector<string> str;
map<string, int> mp;

struct query {
    string original, other;

    query(){}
    query(string a, string b) {
        original = a;
        other = b;
    }
};

vector<query> vsor, vrev;

bool cmp(query a, query b) {
    return a.other < b.other;
}

int main(void) {
    freopen("scramble.in", "r", stdin);
    freopen("scramble.out", "w", stdout);
    cin >> N;
    REP(i, N) {
        cin >> tmp;
        mp[tmp] = i;
        str.push_back(tmp);
        string other = tmp;
        sort(other.begin(), other.end());
        vsor.push_back(query(tmp, other));
        reverse(other.begin(), other.end());
        vrev.push_back(query(tmp, other));

        maximal[i] = INT_MIN;
        minimal[i] = INT_MAX;
    }

    sort(vsor.begin(), vsor.end(), cmp);
    sort(vrev.begin(), vrev.end(), cmp);

    REP(i, N) {
        maximal[mp[vsor[i].original]] = max(maximal[mp[vsor[i].original]], i);
        maximal[mp[vrev[i].original]] = max(maximal[mp[vrev[i].original]], i);
        minimal[mp[vsor[i].original]] = min(minimal[mp[vsor[i].original]], i);
        minimal[mp[vrev[i].original]] = min(minimal[mp[vrev[i].original]], i);
    }

    REP(i, N) {
        printf("%d %d\n", minimal[i] + 1, maximal[i] + 1);
    }
    return 0;
}
