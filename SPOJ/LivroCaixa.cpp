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
<<<<<<< HEAD
int T[60];

int dp1[16005], dp2[16005];

void func1(void) {
	memset(dp1, 63, sizeof(dp1));

	dp1[0] = 0;

	for (int i = 1; i <= F; i++) {
		for (int j = 0; j < N; j++) {
			if (i - T[j] >= 0) {
				dp1[i] = min(dp1[i], dp1[i - T[j]] + 1);
=======
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
>>>>>>> 638e145a317d94f9e5ee44f0d70723189b2bf385
			}
		}
	}
}

int main(void) {
    for ( ; scanf("%d%d", &N, &F) == 2 && N + F != 0; ) {
<<<<<<< HEAD
		for (int i = 0; i < N; i++) {
			scanf("%d", &T[i]);			
		}
		func1();

		for (int i = 0; i <= F; i++) {
			printf("%d %d\n", i, dp1[i]);
		}
		puts("");
=======
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
>>>>>>> 638e145a317d94f9e5ee44f0d70723189b2bf385
    }

    return 0;
}

