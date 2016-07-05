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

const int MAXN = 300005;

int N, K;
vector<int> P;
bool vis[MAXN];
vector<int> ans;

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	cin >> N >> K;

	//cout << P.size() << "\n";
	P.resize(N);	
	ans.resize(N);	
	
	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	sort(P.begin(), P.end());

	for (int i = 0; i < K; i++) {
		int curr_window = 0;
		int win_len = N / K;
		int curr_best = INT_MAX;

		int pos = 0;
		///		cerr << P.size() << "\n";
		for (int j = 0; j < (int) P.size(); j++) {
			cout << P[j] << " ";
			if (j > 0) {
				curr_window += abs(P[j] - P[j - 1]);
			}
			if (j > win_len) {
				curr_window -= abs(P[j - win_len] - P[j - win_len - 1]);
			}
			if (j >= win_len - 1) {
				if (curr_best > curr_window) {
					curr_best = curr_window;;
					pos = j - win_len + 1;
				}
			}
		}
		cout << "\n";
		cout << "deb " << win_len << " " << curr_best << "\n";
		for (int j = i, cnt = 0; cnt < win_len && j < N; j += K, cnt++) {
			ans[j] = P[pos + cnt];
			vis[j] = true;
		}
		P.erase(P.begin() + pos, P.begin() + pos + win_len);
	}

	int pos = 0;	
	for (int i = 0; i < N; i++) {
		if (!vis[i]) {
			//cout << P[pos] << "\n";
			ans[i] = P[pos++];
		}
	}
	Int ans_val = LLONG_MAX;
	for (int i = 0; i < N; i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < K; i++) {
		Int curr_rot = 0;
		for (int j = i, cnt = 0; cnt < N - K; j++, cnt++) {
			int nx = (j + K) % N;
			curr_rot += (Int) abs(ans[j] - ans[nx]);
		}
		chmin(ans_val, curr_rot);
	}
	
	cout << ans_val << "\n";

	return 0;
}
