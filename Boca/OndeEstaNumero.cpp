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

int N, P;
char C;

int main(void) {
	for ( ; scanf("%d", &N) == 1 && N != 0; ) {
		vector<int> vp, ans;
		for (int i = 0; i < N; i++) {
			scanf(" %c %d", &C, &P);

			if (C == 'I') {
				vp.push_back(P);
			} else {
				int pos = distance(vp.begin(), lower_bound(vp.begin(), vp.end(), P));
				ans.push_back(vp.size() - pos);
			}
		}		
		printf("%d", ans[0]);
		for (int i = 1; i < ans.size(); i++) {
			printf(" %d", ans[i]);
		}
		printf("\n");
	}
    return 0;
}
