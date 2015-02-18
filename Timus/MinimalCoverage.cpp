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

const int MAXN = 100007;

int T, M;
int N;

pair<int, int> p[MAXN];
bool used[MAXN];

int main(void) {
	M = in();
		
	N = 0;
	int A, B;
	for ( ; scanf("%d%d", &A, &B) == 2 && !(A == 0 && B == 0); ) {
		if (B < 0) continue;
		p[N] = make_pair(A, B);
		N++;
	}
	
	sort(p, p + N);
	
	int l = 0;
	int r = 0;
	vector<pair<int, int> > ans;
	
	for (int i = 0; i < N; i++) {
		if (r >= M) break;
		if (p[i].first <= l) {
			int pos = i;
			
			r = p[i].second;
			
			while (i < N && p[i].first <= l) {
				if (p[i].second > r) {
					pos = i;
					r = p[i].second;
					}
				i++;					
			}
			ans.push_back(p[pos]);
				l = r;
				i--;
		}
	}
	
	if (r < M) {
		printf("No solution\n");
	} else {
		printf("%d\n", (int) ans.size());

		for (int i = 0; i < (int) ans.size(); i++) {
			printf("%d %d\n", ans[i].first, ans[i].second);
		}		
        printf("\n");
	}

    return 0;
}
