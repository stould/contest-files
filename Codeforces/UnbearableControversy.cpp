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

const int MAXN = 3030;

int N, M;
vector<int> graph[MAXN];
int rev[MAXN][MAXN];

int func(int a, int b) {
	int ans = 0;
	
	for (int i = 0; i < graph[a].size(); i++) {
		int nx = graph[a][i];

		if (nx != a && nx != b && rev[b][nx]) {
			ans += 1;
		}
	}
	
	return ans * (ans - 1) / 2;
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	int A, B;

	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		graph[A].push_back(B);
		rev[B][A] = 1;
	}

	Int ans = 0LL;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j) {
				ans += func(i, j);
			}
		}
	}

	cout << ans << "\n";

    return 0;
}
