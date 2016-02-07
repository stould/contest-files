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

const int MAXN = 7000005;

int T, L;
int belong[MAXN];

string SS;
int AN;
int A[3 * MAXN + 100];
int cnt[MAXN + 1]; // Should be >= 256
int SA[MAXN + 1];
int pos[MAXN];
int REVSA[MAXN + 1];
int LCP[MAXN + 1];
/* Used by suffix_array. */
void radix_pass(int* A, int AN, int* R, int RN, int* D) {
	memset(cnt, 0, sizeof(int) * (AN + 1));
	int* C = cnt + 1;
	for(int i = 0; i < RN; i++) ++C[A[R[i]]];
	for(int i = -1, v = 0; i <= AN && v < RN; v += C[i++]) swap(v, C[i]);
	for(int i = 0; i < RN; i++) D[C[A[R[i]]]++] = R[i];
}

/* DC3 in O(N) using 20N bytes of memory.  Stores the suffix array of the string
 * [A,A+AN) into SA where SA[i] (0<=i<=AN) gives the starting position of the
 * i-th least suffix of A (including the empty suffix).
 */
void suffix_array(int* A, int AN) {
	// Base case... length 1 string.
	if(!AN) {
		SA[0] = 0;
	} else if(AN == 1) {
		SA[0] = 1; SA[1] = 0;
		return;
	}

	// Sort all strings of length 3 starting at non-multiples of 3 into R.
	int RN = 0;
	int* SUBA = A + AN + 2;
	int* R = SUBA + AN + 2;
	for(int i = 1; i < AN; i += 3) SUBA[RN++] = i;
	for(int i = 2; i < AN; i += 3) SUBA[RN++] = i;
	A[AN + 1] = A[AN] = -1;
	radix_pass(A + 2, AN - 2, SUBA, RN, R);
	radix_pass(A + 1, AN - 1, R, RN, SUBA);
	radix_pass(A + 0, AN - 0, SUBA, RN, R);

	// Compute the relabel array if we need to recursively solve for the
	// non-multiples.
	int resfix, resmul, v;
	if(AN % 3 == 1) {
		resfix = 1; resmul = RN >> 1;
	} else {
		resfix = 2; resmul = RN + 1 >> 1;
	}
	for(int i = v = 0; i < RN; i++) {
		v += i && (A[R[i - 1] + 0] != A[R[i] + 0] ||
				   A[R[i - 1] + 1] != A[R[i] + 1] ||
				   A[R[i - 1] + 2] != A[R[i] + 2]);
		SUBA[R[i] / 3 + (R[i] % 3 == resfix) * resmul] = v;
	}

	// Recursively solve if needed to compute relative ranks in the final suffix
	// array of all non-multiples.
	if(v + 1 != RN) {
		suffix_array(SUBA, RN);
		SA[0] = AN;
		for(int i = 1; i <= RN; i++) {
			SA[i] = SA[i] < resmul ? 3 * SA[i] + (resfix==1?2:1) :
                3 * (SA[i] - resmul) + resfix;
		}
	} else {
		SA[0] = AN;
		memcpy(SA + 1, R, sizeof(int) * RN);
	}

	// Compute the relative ordering of the multiples.
	int NMN = RN;
	for(int i = RN = 0; i <= NMN; i++) {
		if(SA[i] % 3 == 1) {
			SUBA[RN++] = SA[i] - 1;
		}
	}
	radix_pass(A, AN, SUBA, RN, R);

	// Compute the reverse SA for what we know so far.
	for(int i = 0; i <= NMN; i++) {
		SUBA[SA[i]] = i;
	}

	// Merge the orderings.
	int ii = RN - 1;
	int jj = NMN;
	int pos;
	for(pos = AN; ii >= 0; pos--) {
		int i = R[ii];
		int j = SA[jj];
		int v = A[i] - A[j];
		if(!v) {
			if(j % 3 == 1) {
				v = SUBA[i + 1] - SUBA[j + 1];
			} else {
				v = A[i + 1] - A[j + 1];
				if(!v) v = SUBA[i + 2] - SUBA[j + 2];
			}
		}
		SA[pos] = v < 0 ? SA[jj--] : R[ii--];
	}
}

/* Copies the string in s into A and reduces the characters as needed. */
void prep_string() {
	int v = AN = 0;
	memset(cnt, 0, 256 * sizeof(int));
	for(int i = 0; i < (int) SS.size(); ++AN, i++) {
		cnt[SS[i]]++;
		cnt[i] = SA[i] = pos[i] = REVSA[i] = LCP[i] = 0;
	}
	for(int i = 0; i < AN; i++) cnt[SS[i]]++;
	for(int i = 0; i < 256; i++) cnt[i] = cnt[i] ? v++ : -1;
	for(int i = 0; i < AN; i++) A[i] = cnt[SS[i]];
}

/* Computes the reverse SA index.  REVSA[i] gives the index of the suffix
 * starting a i in the SA array.  In other words, REVSA[i] gives the number of
 * suffixes before the suffix starting at i.  This can be useful in itself but
 * is also used for compute_lcp().
 */

void compute_reverse_sa() {
	for(int i = 0; i <= AN; i++) {
		REVSA[SA[i]] = i;
	}
}

/* Computes the longest common prefix between adjacent suffixes.  LCP[i] gives
 * the longest common suffix between the suffix starting at i and the next
 * smallest suffix.  Runs in O(N) time.
 */

void compute_lcp() {
	int len = 0;
	for(int i = 0; i < AN; i++, len = max(0, len - 1)) {
		int s = REVSA[i];
		int j = SA[s - 1];
		for(; i + len < AN && j + len < AN && A[i + len] == A[j + len]; len++);
		LCP[s] = len;
	}
}

int main(void) {
	string P, Q;
	cin >> P >> Q;

	SS = P + "$" + Q;
	
	int b = 0;
	AN = 0;
	L = 2;

	for (int i = 0; i < (int) SS.size(); i++) {
		belong[i] = b;
		if (SS[i] == '$') {
			b += 1;
		}
	}
	
	prep_string();
	suffix_array(A, AN);
	compute_reverse_sa();
	compute_lcp();
		
	int best = L == 1 ? AN - 1: 0;
		
	for (int i = 0; i < AN; i++) {
		pos[REVSA[i]] = i;
	}

	for (int i = 1; i < AN; i++) {
		int j = i + 1;
		int curr = LCP[i];
		int seen = 0;
			
		seen |= 1 << belong[pos[i - 1]];
		seen |= 1 << belong[pos[i]];
			
		while (j < AN) {
			seen |= 1 << belong[pos[j]];
			if (__builtin_popcount(seen) == L) {
				break;
			}		
			chmin(curr, LCP[j]);		
			j += 1;
		}
			
		if (__builtin_popcount(seen) == L) {
			chmax(best, curr);
		}

		i = j - 1;
	}

	printf("%d\n", best);


    return 0;
}
