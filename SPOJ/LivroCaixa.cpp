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

const int MAXN = 1010010;

int N, F;
vector<int> A, B;
int dp1[MAXN], dp2[MAXN];

int P[50];
char pos[50];

void func1(void) {
	memset(dp1, 0, sizeof(dp1));

	for (int i = 1; i <= -F; i++) {
		for (int j = 0; j < (int) A.size(); j++) {
			if (i - A[j] >= 0) {
				dp1[i] = min(dp1[i], dp1[i - A[j]] + 1);
			}
		}
	}
}

void func2(void) {
	memset(dp2, 0, sizeof(dp2));

	for (int i = 1; i <= F; i++) {
		for (int j = 0; j < (int) B.size(); j++) {
			if (i - B[j] >= 0) {
				dp2[i] = min(dp2[i], dp2[i - B[j]] + 1);
			}
		}
	}
}

int main(void) {
    for ( ; scanf("%d%d", &N, &F) == 2 && N + F != 0; ) {
		A.clear();
		B.clear();

		int p;

		for (int i = 0; i < N; i++) {
			scanf("%d", &p);

			P[i] = P;			

			if (p < 0) {
				A.push_back(-p);
			} else {
				B.push_back(p);
			}
		}

		sort(A.begin(), A.end());
		sort(B.begin(), B.end());

		func1();
		func2();
    }
    return 0;
}

