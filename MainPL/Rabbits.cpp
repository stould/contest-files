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

struct state {
    int moved, shoted;
    vector<int> row;

    state() {}

    state(int _moved, vector<int> _row, int _shoted) {
        shoted = _shoted;
        moved = _moved;
        row = _row;
    }
};

int main(void) {
    scanf("%d%d", &N, &K);

    vector<int> base(N);

    REP(i, N) scanf("%d", &base[i]);

    queue<state> q; q.push(state(0, base, 0));

    int ans = -1;

    while(!q.empty()) {
        state now = q.front(); q.pop();

        if(now.shoted > K) continue;

        ans = max(ans, now.moved);

        REP(i, now.row.size()) if(now.row[i] != 0) {
            state next(now.moved + now.row[i], now.row, now.shoted + 1);
            next.row[i] = 0;

            int left = i - 1 < 0 ? N - 1 : i - 1;
            int right = (i + 1) % N;

            int next_left = left - 1 < 0 ? N - 1 : left - 1;
            int next_right = (right + 1) % N;

            next.row[next_left] += next.row[left];
            next.row[left] = 0;

            next.row[next_right] += next.row[right];
            next.row[right] = 0;

            q.push(next);
        }
    }
    printf("%d\n", ans);
    return 0;
}
