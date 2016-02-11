#include <bits/stdc++.h>

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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 1100;

int N;
int A[MAXN][MAXN];
bool used[MAXN];

int main(void) {
	cin >> N;

	for (int i = 2; i <= 2 * N; i++) {
		for (int j = 1; j < i; j++) {
			cin >> A[i][j];
			A[j][i] = A[i][j];
		}
	}

	vector<int> M_ans(2 * N + 1, 0);
	
	for (int a = 1; a <= N; a++) {
		int best = 0;
		int ia = 0, ib = 0;
		
		for (int i = 1; i <= 2 * N; i++) {
			if (used[i]) continue;
			for (int j = 1; j <= 2 * N; j++) {
				if (i != j && used[j]) continue;
				
				if (A[i][j] > best) {
					best = A[i][j];
					ia = i;
					ib = j;
				}
			}
		}

		used[ia] = used[ib] = true;
		M_ans[ia] = ib;
		M_ans[ib] = ia;
	}

	for (int i = 1; i <= 2 * N; i++) {
		cout << M_ans[i] << " ";
	}
	cout << endl;
	
	return 0;
}
