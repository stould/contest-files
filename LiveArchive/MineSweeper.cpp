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

const int MAXN = 60;

int T, N, M;
string S[MAXN];
int cnt[MAXN][MAXN];

int dx[8] = {1, 1,  1,  0, -1, -1, -1, 0};
int dy[8] = {1, 0, -1, -1, -1,  0,  1, 1};

int main(void) {
	cin >> T;

	while (T--) {
		cin >> N >> M;

		memset(cnt, 0, sizeof(cnt));

		for (int i = 0; i < N; i++) {
			cin >> S[i];

			for (int j = 0; j < M; j++) {
				if (S[i][j] != 'F') {
					cnt[i][j] = (S[i][j] - '0');
				}
			}
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (S[i][j] == 'F') {
					for (int k = 0; k < 8; k++) {
						int di = i + dx[k];
						int dj = j + dy[k];

						if (di >= 0 && dj >= 0 && di < N && dj < M) {
							cnt[di][dj] -= 1;							
						}
					}
				}
			}
		}

		bool ok = true;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (S[i][j] != 'F' && cnt[i][j] != 0) {
					ok = false;
				}
			}
		}

		if (ok) {
			cout << "Well done Clark!\n";
		} else {
			cout << "Please sweep the mine again!\n";
		}
	}
	
	return 0;
}
		
