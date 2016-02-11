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

const int MAXN = 100005;

int N, M;
vector<int> G[MAXN];

int main(void) {
	while (cin >> N >> M) {
		if (N == -1 && M == -1) {
			break;
		}

		for (int i = 0; i <= N; i++) {
			G[i].clear();
		}

		int A, B;
		for (int i = 0; i < M; i++) {
			cin >> A >> B;

			G[A].push_back(B);
			G[B].push_back(A);
		}

		int cnt = 0;
		
		for (int i = 1; i <= N; i++) {
			cnt += max(0, 2 - (int) G[i].size());
		}
		
		cout << (cnt + 1) / 2 << "\n";
	}
	
	return 0;
}
