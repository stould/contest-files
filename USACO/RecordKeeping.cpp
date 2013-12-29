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


template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

int N;
map<pair<string, pair<string, string> >, int> mp;

string S[5];

int main(void) {
    freopen("records.in", "r", stdin);
    freopen("records.out", "w", stdout);
    N = in();

    int i;
    int best = 0;

    for (i = 0; i < N; i++) {
        cin >> S[0] >> S[1] >> S[2];

        sort(S, S + 3);

        pair<string, pair<string, string> > sp = make_pair(S[0], make_pair(S[1], S[2]));

        mp[sp] += 1;

        if (mp[sp] > best) {
            best = mp[sp];
        }
    }

    printf("%d\n", best);

    return 0;
}
