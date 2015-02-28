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

const int MAXN = 100005;

int N, M, K;
int P[MAXN], id[MAXN];
pair<int, int> curr_page[MAXN];
int pr[MAXN], nx[MAXN];

int main(void) {
	cin >> N >> M >> K;

	int cnt = 1, curr = 1;
	
	for (int i = 1; i <= N; i++) {
		cin >> P[i];

		if (cnt > K) {
			cnt = 1;
			curr += 1;
		}

		curr_page[P[i]] = make_pair(curr, cnt);
		id[P[i]] = i;
		cnt += 1;
	}

	P[0] = 0;
	P[N + 1] = N + 1;
	
	for (int i = 1; i <= N; i++) {
		pr[P[i]] = P[i - 1];	
		nx[P[i]] = P[i + 1];
		
	}

	Int ans = 0LL;
	
	for (int i = 0; i < M; i++) {
		int C;
		cin >> C;

		ans += curr_page[C].first;
		
		if (!(curr_page[C].first == 1 && curr_page[C].second == 1)) {
			int ant = pr[C];

			swap(curr_page[ant].first, curr_page[C].first);
			swap(curr_page[ant].second, curr_page[C].second);

			int pr_ant = pr[ant];
			int pr_c = pr[C];
			
			nx[pr[ant]] = C;
			pr[nx[C]] = ant;

			nx[C] = ant;
			nx[ant] = nx_c;

			pr[C] = pr_ant;
			pr[ant] = C;
			
			swap(id[ant], id[C]);
		}
	}

	cout << ans << "\n";

    return 0;
}
