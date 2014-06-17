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

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

#define TT 123

const int MAXN = 1103;
int T, C, V;

int m[MAXN][MAXN];

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}

int main(void) {
    T = in();

    for ( ; T--; ) {		
        C = in();
        V = in();

        int id = 0, cnt = 0;

        map<int, int> mp;
        vector<int> win;
		map<int, int> vint;
		map<int, int> pos[V];

		vector<pair<int, int> > v_vote(C + 1);

		for (int i = 1; i <= C; i++) {
			v_vote[i].first = i;
		}

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < C; j++) {
                m[i][j] = in();
				if (j == 0) {
					v_vote[m[i][j]].second += 1;
				}
				vint[m[i][j]] += C - j;
				pos[i][m[i][j]] = j;
            }
        }
		sort(v_vote.begin() + 1, v_vote.end(), cmp);
		cnt = v_vote[1].second;
		id = v_vote[1].first;

        if (cnt > (V / 2)) {
			printf("%d %d", id, 1);
        } else {			
			win.push_back(v_vote[1].first);
			win.push_back(v_vote[2].first);

            int p1 = 0, p2 = 0;
			
            for (int i = 0; i < V; i++) {
				if (pos[i][win[0]] < pos[i][win[1]]) {
					p1 += 1;
				} else {
					p2 += 1;
				}
            }
			if (p1 > p2) id = win[0];
			else id = win[1];

			printf("%d %d", id, 2);
        }
		printf("\n");
    }
    return 0;
}
