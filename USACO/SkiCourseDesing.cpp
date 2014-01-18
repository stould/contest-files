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
	
	int ans = 0;

	for ( ; ; ) {
		int l = 110, l_id = 0;
		int h = 0, h_id = 0;

		for (int i = 0; i < N; i++) {
			if (H[i] < l) {
				l = H[i];
				l_id = i;
			}
			if (H[i] > h) {
				h = H[i];
				h_id = i;
			}
		}
		if (h - l <= 17) break;

		int df = h - l - 17;

		if (df % 2 == 0) {
			ans += 2 * (df / 2) * (df / 2);
			H[h_id] -= df / 2;
			H[l_id] += df / 2;			
		} else {
			ans += (df / 2) * (df / 2) + (df / 2 + 1) * (df / 2 + 1);
			H[h_id] -= df / 2 + 1;
			H[l_id] += df / 2;
		}
	}

	printf("%d\n", ans);

    return 0;
}
