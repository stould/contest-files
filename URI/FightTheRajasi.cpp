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

const int MAXN = 10005;

int T;
int N, H, K;
int X[MAXN], R[MAXN];

bool good_cmp(int a, int b) {
	return X[a] < X[b];
}

bool evil_cmp(int a, int b) {
	return R[a] > R[b];
}

int main(void) {
	cin >> T;

	while (T--) {
		cin >> N >> H >> K;

		bool alive = true;
		vector<int> good, evil;
		
		for (int i = 0; i < N; i++) {
			cin >> X[i] >> R[i];
			
			if (R[i] >= X[i]) {
				good.push_back(i);
			} else {
				evil.push_back(i);
			}
		}

		sort(good.begin(), good.end(), good_cmp);
		sort(evil.begin(), evil.end(), evil_cmp);

		for (int i = 0; i < (int) good.size(); i++) {
			if (H < X[good[i]]) alive = false;
			H -= X[good[i]];

			if (H < 0) alive = false;

			H += R[good[i]];
		}

		for (int i = 0; i < (int) evil.size() - K; i++) {
			if (H < X[evil[i]]) alive = false;
			H -= X[evil[i]];

			if (H < 0) alive = false;

			H += R[evil[i]];			
		}

		if (alive) {
			cout << "Y\n";
		} else {
			cout << "N\n";
		}
	}
	
	return 0;
}
