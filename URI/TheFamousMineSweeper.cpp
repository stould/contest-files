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

int N, M, K;
int X[35], Y[35];

char S[22][22], P[22][22];

int dx[8] = { 0, 0, -1, 1, -1, 1, -1,  1};
int dy[8] = {-1, 1,  0, 0, -1, 1,  1, -1};

int main(void) {
	for ( ; scanf("%d%d%d", &N, &M, &K) == 3 && (N + M + K != 0); ) {
		for (int i = 0; i < N; i++) {
			scanf("%s", &S[i]);
			for (int j = 0; j < M; j++) {
				P[i][j] = S[i][j];
			}
		}

		for (int i = 0; i < K; i++) {
			scanf("%d%d", &X[i], &Y[i]);
			X[i] -= 1;
			Y[i] -= 1;

			P[X[i]][Y[i]] = '*';
		}
		
		bool ok = true;

		for (int u = 0; u <= K; u++) {			
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (S[i][j] >= '0' && S[i][j] <= '9') {											
						int f = 0, b = 0;
						for (int k = 0; k < 8; k++) {
							int pi = i + dx[k];
							int pj = j + dy[k];

							if (pi >= 0 && pj >= 0 && pi < N && pj < M) {
								if (S[pi][pj] == '.') {
									f += 1;
								} else if (S[pi][pj] == '*') {
									b += 1;
								}						
							}
						}
						if (f + b == S[i][j] - '0') {
							for (int k = 0; k < 8; k++) {
								int pi = i + dx[k];
								int pj = j + dy[k];
								
								if (pi >= 0 && pj >= 0 && pi < N && pj < M) {
									if (S[pi][pj] == '.') {
										S[pi][pj] = '*';
									}
								}
							}
						} else if (S[i][j] - '0' == b) {
							for (int k = 0; k < 8; k++) {
								int pi = i + dx[k];
								int pj = j + dy[k];
								
								if (pi >= 0 && pj >= 0 && pi < N && pj < M) {
									if (S[pi][pj] != '.') continue;
									int cnt = 0;
									for (int l = 0; l < 8; l++) {
										int qi = pi + dx[l];
										int qj = pj + dy[l];

										if (qi >= 0 && qj >= 0 && qi < N && qj < M) {
											if (P[qi][qj] == '*') {
												cnt += 1;
											}
										}
									}
									S[pi][pj] = '0' + cnt;
								}
							}
						}
					}
				}
			}			
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (S[i][j] == '.') {
					ok = false;
				}
			}			
		}
		
		puts(ok ? "Possivel" : "Impossivel");
	}
    return 0;
}
