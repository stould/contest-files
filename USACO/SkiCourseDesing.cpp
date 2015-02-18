/*
ID: jeferso1
LANG: C++
TASK: skidesign
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

const int MAXN = 1010;
int N;
int H[MAXN];

int main(void) {
	freopen("skidesign.in", "r", stdin);
	freopen("skidesign.out", "w", stdout);
	
	N = in();

	for (int i = 0; i < N; i++) {
		H[i] = in();
	}
	
	long long ans = 101010010101001LL;
	
	for (int i = 1; i <= 1000; i++) {
		for (int j = i; j <= 1000; j++) {
			if (j - i > 17) break;
			long long df = 0LL;

			for (int k = 0; k < N; k++) {
				long long ds = 0LL;
				
				if (H[k] < i) {
					ds = H[k] - i;
				} else if (H[k] > j) {
					ds = j - H[k];
				}

				df += ds * ds;
			}
			if (df < ans) {
				ans = df;
			}
		}
	}


	printf("%lld\n", ans);

    return 0;
}
