/*
ID: jeferso1
LANG: C++
TASK: combo
*/

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

int N;
int F[5], M[5];

bool check(int i, int j, int k) {
	int li = abs(i - F[0]);
	int lj = abs(j - F[1]);
	int lk = abs(k - F[2]);


	int ri = abs(i - M[0]);
	int rj = abs(j - M[1]);
	int rk = abs(k - M[2]);
	
	bool A = (li <= 2 || li >= N - 2) && (lj <= 2 || lj >= N - 2) && (lk <= 2 || lk >= N - 2);
	bool B = (ri <= 2 || ri >= N - 2) && (rj <= 2 || rj >= N - 2) && (rk <= 2 || rk >= N - 2);

	return A || B;
}

int main(void) {
	freopen("combo.in", "r", stdin);
	freopen("combo.out", "w", stdout);

	cin >> N;
	
    for (int i = 0; i < 3; i++) {
        cin >> F[i];
    }
    for (int i = 0; i < 3; i++) {
        cin >> M[i];
    }

    int ans = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if (check(i, j, k)) {
					ans += 1;
				}
            }
        }
    }

	cout << ans << endl;

    return 0;
}

