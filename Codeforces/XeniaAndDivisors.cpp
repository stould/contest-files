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

const int MAXN = 100007;


int readInt () {
	bool minus = false;
	int result = 0;
	char ch;

	ch = getchar();

	while (1) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') {
	    minus = true;
    } else {
        result = ch-'0';
    }

	while (1) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result * 10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}


int N;
int c[MAXN], cnt[MAXN];

struct triplet {
    int a, b, c;

    triplet(void) {}

    triplet(int a, int b, int c):
        a(a), b(b), c(c)
    {}
};

int main(void) {
    N = in();

    int i;

    memset(cnt, 0, sizeof(cnt));

    for (i = 0; i < N; i++) {
        c[i] = in();

        cnt[c[i]] += 1;
    }

    vector<triplet> vt;

    for ( ; cnt[1] > 0 && cnt[2] > 0 && cnt[4] > 0; )  {
        vt.push_back(triplet(1, 2, 4));
        cnt[1] -= 1;
        cnt[2] -= 1;
        cnt[4] -= 1;
    }

    for ( ; cnt[1] > 0 && cnt[2] > 0 && cnt[6] > 0; )  {
        vt.push_back(triplet(1, 2, 6));
        cnt[1] -= 1;
        cnt[2] -= 1;
        cnt[6] -= 1;
    }

    for ( ; cnt[1] > 0 && cnt[3] > 0 && cnt[6] > 0; )  {
        vt.push_back(triplet(1, 3, 6));
        cnt[1] -= 1;
        cnt[3] -= 1;
        cnt[6] -= 1;
    }

    if (3 * (int) vt.size() == N) {
        for (i = 0; i < (int) vt.size(); i++) {
            printf("%d %d %d\n", vt[i].a, vt[i].b, vt[i].c);
        }
    } else {
        puts("-1");
    }


    return 0;
}
