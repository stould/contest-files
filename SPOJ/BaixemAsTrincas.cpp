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

int N, ans;
int A[15], B[15];
map<int, int> dp;

int func(int mask, int L, vector<int>& vs, int used) {
	if (L - used < 3) return 0;	

	if (dp.find(mask) == dp.end()) {
		for (int i = 0; i < L; i++) {
			if (!(mask & (1 << i))) {
				for (int j = i + 1; j < L; j++) {
					if (!(mask & (1 << j))) {
						for (int k = j + 1; k < L; k++) {
							if (!(mask & (1 << k))) {
								if (vs[i] + vs[j] > vs[k]) {
									int new_mask = mask | (1 << i) | (1 << j) | (1 << k);
									
									chmax(dp[mask], 1 + func(new_mask, L, vs, used + 3));									
								}									
							}	
						}	
					}	
				}	
			}	
		}	
	}	
	return dp[mask];
}

int run(vector<int>& vs) {
	dp.clear();
	int L = (int) vs.size();
	return func(0, L, vs, 0);
}

int main(void) {
    for ( ; scanf("%d", &N) == 1 && N != 0; ) {
        for (int i = 0; i < 15; i++) {
			A[i] = B[i] = 0;
		}

        for (int i = 0; i < N; i++) {
            int x = in();
            if (i % 2 == 0) {
                A[x] += 1;
            } else {
                B[x] += 1;
            }
        }
		int A1 = 0, B1 = 0;

		for (int i = 1; i <= 13; i++) {
			A1 += A[i] / 3;
			A[i] %= 3;
			B1 += B[i] / 3;
			B[i] %= 3;
		}
		if (A1 != B1) {
			puts(A1 > B1 ? "1" : "2");
		} else {
			vector<int> vs1, vs2;
			
			for (int i = 1; i <= 13; i++) {
				while (A[i] > 0) {
					vs1.push_back(i);
					A[i] -= 1;
				}
				while (B[i] > 0) {
					vs2.push_back(i);
					B[i] -= 1;
				}
			}
			
			int cnt1 = run(vs1);			
			int cnt2 = run(vs2);

			if (cnt1 != cnt2) {
				puts(cnt1 > cnt2 ? "1" : "2");
			} else {
				puts("0");
			}
		}
    }

    return 0;
}
