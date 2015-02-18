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

int C[12];
int T[4];
int L[3];

int main(void) {
	freopen("bteams.in", "r", stdin);
	freopen("bteams.out", "w", stdout);

	for (int i = 0; i < 12; i++) {
		C[i] = in();
	}

	sort(C, C + 12);
	int ans = 12 * 1000000;

	for (int i = 0; i < 4; i++) L[i] = C[i];

	do {
		T[0] = T[1] = T[2] = T[3] = 0;

		int id = 0;

		for (int i = 4; i < 12; i++) {
			T[id] += C[i]; 
			id = (id + 1) % 4;
		}

		int A = *min_element(T, T + 4);
		int B = *max_element(T, T + 4);

		ans = min(ans, abs((B + L[0]) - (A + L[1])));

	} while(next_permutation(C + 4, C + 12));

	printf("%d\n", ans);

    return 0;
}
