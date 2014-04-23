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

const double PI = 2.0 * acos(0.0);
double N;

int main(void) {
    for ( ; scanf("%lf", &N) == 1; ) {
		double S = sin(PI / 12.0), C = cos(PI / 12.0);
		double co = 2.0*N*S;
		double ca = N * C;
		double center = co*co + 4.0 * (PI*N*N/12.0 - co*ca/2.0);
	  
		double petal = 2.0 * ((N*N - (2.0 * (N*N - PI*N*N / 4.0))) - center);

		printf("%.3lf %.3lf %.3lf\n", center, petal, N*N - center - petal);
    }
    return 0;
}
