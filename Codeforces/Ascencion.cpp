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
typedef unsigned uint;

int N, M, K;
string S[110][5];
int cnt[110][600];

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	cin >> K;

	for (int i = 0; i < K; i++) {
		cin >> S[i][0] >> S[i][1];

		for (int j = 0; j < (int) S[i][0].size(); j++) {
			cnt[i][(int) S[i][0][j]] += 1;
		}
		for (int j = 0; j < (int) S[i][1].size(); j++) {
			cnt[i][(int) S[i][1][j]] += 1;
		}
	}

	int ans = 0;
	int id_ans = 0;
	
	for (int i = 0; i < K; i++) {
		cin >> N >> M;
		char curr;

		vector<int> curr_cnt(600, 0);
		
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> curr;
				
				curr_cnt[(int) curr] += 1;
			}
		}

		int can = INT_MAX;

		for (int j = 0; j < 600; j++) {
			if (cnt[i][j] > 0) {
				chmin(can, curr_cnt[j] / cnt[i][j]);
			}
		}
		if (ans < can) {
			ans = can;
			id_ans = i;
		}
	}

	cout << S[id_ans][0] << " " << S[id_ans][1] << endl;
	return 0;
}
