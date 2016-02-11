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

int N, M;
string S[20];
bool seen[20][20];

int main(void) {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}
	
	int ans = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (S[i][j] == 'G') {
				for (int a = 0; a < N; a++) {
					for (int b = 0; b < M; b++) {						
						int curr = 1;
						
						memset(seen, false, sizeof(seen));
						
						for (int x = 1; x < min(N, M); x++) {
							bool valid = true;
							
							if (i + x >= N or (i + x < N and (S[i + x][j] != 'G' or seen[i + x][j]))) {
								valid = false;
							} else {
								seen[i + x][j] = true;
							}
							if (i - x < 0 or (i - x >= 0 and (S[i - x][j] != 'G' or seen[i - x][j]))) {
								valid = false;
							} else {
								seen[i - x][j] = true;
							}
							if (j + x >= M or (j + x < M and (S[i][j + x] != 'G' or seen[i][j + x]))) {
								valid = false;
							} else {
								seen[i][j + x] = true;
							}
							if (j - x < 0 or (j - x >= 0 and (S[i][j - x] != 'G' or seen[i][j - x]))) {
								valid = false;
							} else {
								seen[i][j - x] = true;
							}
							
							if (!valid) break;
							
							curr += 4;
							
							if (valid && !seen[a][b] && S[a][b] == 'G') {
								int cl = 1;
								for (int y = 1; y < min(N, M); y++) {									
									if (a + x >= N or ((a + x < N and S[a + x][b] == 'G') or seen[a + x][b])) {
										valid = false;
									} else {
										seen[a + x][b] = true;
									}
									if (a - x < 0 or ((a - x >= 0 and S[a - x][b] == 'G') or seen[a - x][b])) {
										valid = false;
									} else {
										seen[a - x][b] = true;
									}
									if (b + x >= M or ((b + x < M and S[a][b + x] == 'G') or seen[a][b + x])) {
										valid = false;
									} else {
										seen[a][b + x] = true;
									}
									if (b - x < 0 or ((b - x >= 0 and S[a][b - x] == 'G') or seen[a][b - x])) {
										valid = false;
									} else {
										seen[a][b - x] = true;
									}
									
									if (!valid) break;
									
									cl += 4;
								}
								chmax(ans, curr * cl);
							}
						}
					}
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}
