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

const int MAXN = 10001;

int N, P;
int A[MAXN];
int S[MAXN][25];

int main(void) {
	int test = 1;
	
	while (cin >> N >> P) {
		if (N == 0 && P == 0) {
			break;
		}
		
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		for (int i = 1; i <= 23; i++) {
			S[N][i] = N;
		}

		for (int i = N - 1; i >= 0; i--) {
			for (int j = 1; j <= 23; j++) {
				S[i][j] = S[i + 1][j];
				
				if (A[i] == j) {
					S[i][j] = i;
				}
			}
		}

		list<int> l;
		set<int> inside;
		int ans = 0;
		
		for (int i = 0; i < N; i++) {
			if (inside.count(A[i])) continue;

			if (P > (int) inside.size()) {
				l.push_back(A[i]);
				inside.insert(A[i]);
			} else {
				ans += 1;
				
				int it_cnt = 0;
				int seen = 0;
				list<int>::iterator pos;
				
				for (list<int>::iterator it = l.begin(); it != l.end(); it++)  {
					if (seen < S[i][*it]) {
						seen = S[i][*it];
						pos = it;
					}
					it_cnt += 1;
				}
				inside.erase(*pos);					
				inside.insert(A[i]);
				
				l.erase(pos);
				l.push_back(A[i]);									
			}
		}
		printf("Teste %d\n%d\n\n", test++, ans);
	}
	
	return 0;
}
