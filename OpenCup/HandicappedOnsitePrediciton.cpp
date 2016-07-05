#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200205;

int N, K;
long long A[MAXN], P[MAXN];

int main() {
	freopen("hop.in", "r", stdin);
	freopen("hop.out", "w", stdout);

	scanf("%d%d", &N, &K);

	for (int i = 0; i < N; i++) {
		scanf("%lld", &A[i]);
	}
  
	for (int i = 0; i < N; i++) {
		scanf("%lld", &P[i]);
	}

	sort(A + 1, A + N);

	int l = 0, h = N - 1, m;
	int best = -1;

	while (l <= h) {
		m = (l + h) / 2;

		long long out = A[0] + P[m];
		int pos = 1;
		int p = 0, a_pos = 1;
    
		vector<bool> used(N, false);
		bool done = false;
    
		for (int i = 1; i < N; i++) {
			if (pos > K) {
				break;
			}
			if (m == i - 1) {
				p += 1;
			}

			long long curr = P[p];

			if (done) {
				while (used[a_pos]) {
					a_pos += 1;
				}
				if (a_pos < N) {
					curr += A[a_pos];
				}
			} else {
				while (a_pos < N && A[a_pos] + P[p] <= out) {
					a_pos += 1;
				}
	
				if (a_pos >= N) a_pos -= 1;
	
				curr += A[a_pos];
				used[a_pos] = true;
			}
     
			if (curr > out) {
				pos += 1;
			}

			p += 1;
			a_pos += 1;
      
			if (a_pos >= N) {
				done = true;
				a_pos = 1;
			}      
		}

		if (pos <= K) {
			best = max(best, m + 1);
			l = m + 1;
		} else {
			h = m - 1;
		}
	}

	printf("%d\n", best);
  
	return 0;
}
