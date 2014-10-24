/*
ID: jeferso1
LANG: C++
TASK: sprime
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
set<int> prime;

bool isPrime(long long n) {
    if(n <= 1) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;

    long long m = (long long) sqrt(n);

    for(int i = 3L; i <= m; i += 2L) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

void func(int d, int len) {
	if (len == N) {
		prime.insert(d);
	} else {
		for (int i = 1; i <= 9; i++) {
			int nd = d * 10 + i;
			if (isPrime(nd)) {
				func(nd, len + 1);
			}
		}
	}
}
int main(void) {
	freopen("sprime.in", "r", stdin);
	freopen("sprime.out", "w", stdout);

	cin >> N;

	func(0, 0);

	for (set<int>::iterator it = prime.begin(); it != prime.end(); it++) {
		cout << *it << endl;
	}

    return 0;
}

