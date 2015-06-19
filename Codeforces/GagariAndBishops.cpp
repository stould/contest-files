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

const int MAXN = 2020;

int N;
Int M[MAXN][MAXN];
Int S[MAXN][MAXN];

int dx[4] = {-1, 1, -1, 1};
int dy[4] = {1, -1, -1, 1};

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> M[i][j];
		}
	}

	Int ansA = 0LL;
	Int ansB = 0LL;
	int ai = -1, aj = -1, bi = -1, bj = -1;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 1; k < N; k++) {
				int inside = 0;
				
				for (int d = 0; d < 4; d++) {
					int pi = i + dx[d] * k;
					int pj = j + dy[d] * k;

					if (pi >= 0 && pi < N && pj >= 0 && pj < N) {
						inside += 1;
						cout << i << " " << j << " => " << pi << " " << pj << endl;
						S[i][j] += M[pi][pj];
					}
				}
				if (!inside) break;
			}
			S[i][j] += M[i][j];
			  
			if (i % 2 == j % 2) {
				if (S[i][j] > ansA) {
					ansA = S[i][j];
					ai = i + 1;
					aj = j + 1;
				}
			} else {
				if (S[i][j] > ansB) {
					ansB = S[i][j];
					bi = i + 1;
					bj = j + 1;
				}
			}		
		}
	}

	cout << ansA + ansB << endl;

	cout << ai << " " << aj << " " << bi << " " << bj << endl;
			
	
	return 0;
}
