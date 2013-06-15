#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <memory>
#include <iomanip>
#include <numeric>
#include <functional>
#include <new>
#include <utility>
#include <valarray>
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

struct edge {
    int to, len, start;
    edge(int to, int len, int start): to(to), len(len), start(start) {}
};

const int MAXN = 20020;
int M, start, dist[MAXN][50];
string a, b, word, origin, destiny;
map<string, int> si;
map<int, string> is;
vector<edge> graph[MAXN];

void addWord(string s) {
    if(si.count(s)) return;
    si[s] = start; is[start] = s; start++;
}

int func(int from, int end) {
    memset(dist, 63, sizeof(dist));
    REP(i, 28) dist[from][i] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    q.push(make_pair(from, 27));

    while(!q.empty()) {
        pair<int, int> now = q.top(); q.pop();
        REP(i, graph[now.first].size()) {
            int next = graph[now.first][i].to, sz = graph[now.first][i].len, differ = graph[now.first][i].start;

            if(now.second == differ) continue;

            if(dist[next][differ] > dist[now.first][now.second] + sz) {
                dist[next][differ] = dist[now.first][now.second] + sz;
                q.push(make_pair(next, differ));
            }
        }
    }
    int ans = 1061109569;
    REP(i, 27) ans = min(ans, dist[end][i]);
    return ans;
}

int main(void) {
    ios::sync_with_stdio(false);
    while(cin >> M && M != 0) {
        start = 0;
        is.clear();
        si.clear();
        REP(i, MAXN) graph[i].clear();

        cin >> origin >> destiny;
        addWord(origin);
        addWord(destiny);
        REP(i, M) {
            cin >> a >> b >> word;
            addWord(b);
            addWord(a);
            graph[si[a]].push_back(edge(si[b], word.size(), word[0]-'a'));
            graph[si[b]].push_back(edge(si[a], word.size(), word[0]-'a'));
        }
        int ans = func(si[origin], si[destiny]);
        if(ans == 1061109567) {
            cout << "impossivel\n";
        } else {
            cout << ans << "\n";
        }
    }
    return 0;
}
