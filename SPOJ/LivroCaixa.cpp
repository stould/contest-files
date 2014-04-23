#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <functional>
#include <valarray>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

using namespace std;

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;


int N, F;
int T[60];

int dp1[16005], dp2[16005];

void func1(void) {
	memset(dp1, 63, sizeof(dp1));

	dp1[0] = 0;

	for (int i = 1; i <= F; i++) {
		for (int j = 0; j < N; j++) {
			if (i - T[j] >= 0) {
				dp1[i] = min(dp1[i], dp1[i - T[j]] + 1);
			}
		}
	}
}

int main(void) {
    for ( ; scanf("%d%d", &N, &F) == 2 && N + F != 0; ) {
		for (int i = 0; i < N; i++) {
			scanf("%d", &T[i]);			
		}
		func1();

		for (int i = 0; i <= F; i++) {
			printf("%d %d\n", i, dp1[i]);
		}
		puts("");
    }

    return 0;
}

