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

typedef long long Int;
typedef unsigned uint;

const int MAXN = 330;

int N;
int A[MAXN];
int B[MAXN];

int main(void) {
	N = in();

	vector<pair<int, int> > ans;

	int i;
	int j;

	for (i = 0; i < N; i++) A[i] = in();
	for (i = 0; i < N; i++) B[i] = in();

	for (i = 0; i < N; i++) if (A[i] != B[i]) {
		int pos = i;
		for (j = i + 1; j < N; j++) if (B[j] == A[i]) {
			pos = j;
			break;
		}

		for ( ; pos != i; ) {			
			ans.push_back(make_pair(pos, pos + 1));
			swap(B[pos], B[pos - 1]);
			pos = pos - 1;
		}
	}

	printf("%d\n", (int) ans.size());

	for (i = 0; i < (int) ans.size(); i++) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}

    return 0;
}
