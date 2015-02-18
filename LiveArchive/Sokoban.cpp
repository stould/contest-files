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

const int MAXN = 16;
int N, M;
string S[MAXN], C;
int dx[4] = { 0, 0, -1, 1};
int dy[4] = {-1, 1,  0, 0};

map<char, int> p_id;

void build(void) {
	p_id['L'] = 0;
	p_id['R'] = 1;
	p_id['U'] = 2;
	p_id['D'] = 3;
}

void go(int& p, int& q, char dir) {
	int nx = p + dx[p_id[dir]];
	int ny = q + dy[p_id[dir]];

	bool went = false;
	if (S[nx][ny] == '#') {
		return;
	} else if (S[nx][ny] == '+') {
		S[nx][ny] = 'W';
		if (S[p][q] == 'W') {
			S[p][q] = '+';
		} else {
			S[p][q] = '.';
		}
		went = true;
	} else if (S[nx][ny] == '.') {
		S[nx][ny] = 'w';
		if (S[p][q] == 'W') {
			S[p][q] = '+';
		} else {
			S[p][q] = '.';
		}
		went = true;
	} else if (S[nx][ny] == 'b' || S[nx][ny] == 'B') {
		int mx = nx + dx[p_id[dir]];
		int my = ny + dy[p_id[dir]];

		if (S[mx][my] == '.') {
			S[mx][my] = 'b';
			if (S[nx][ny] == 'B') {
				S[nx][ny] = 'W';
			} else {
				S[nx][ny] = 'w';			
			}
			if (S[p][q] == 'W') {
				S[p][q] = '+';
			} else {
				S[p][q] = '.';
			}
			went = true;
		} else if (S[mx][my] == '+') {	
			S[mx][my] = 'B';
			if (S[nx][ny] == 'B') {
				S[nx][ny] = 'W';
			} else {
				S[nx][ny] = 'w';
			}
			if (S[p][q] == 'W') {
				S[p][q] = '+';
			} else {
				S[p][q] = '.';
			}
			went = true;
		}
	}
	if (went) {
		p = nx;
		q = ny;
	}
}

int main(void) {
	int t = 1;
	build();
	for ( ; cin >> N >> M  && N + M != 0; ) {
		int p = -1, q = -1;
		int goal = 0;
		for (int i = 0; i < N; i++) {
			cin >> S[i];
			for (int j = 0; j < M; j++) {
				if (S[i][j] == 'w' || S[i][j] == 'W') {
					p = i;
					q = j;
				}
				if (S[i][j] == '+' || S[i][j] == 'W' || S[i][j] == 'B') {
					goal += 1;
				}
			}
		}
		cin >> C;

		for (int i = 0; i < (int) C.size(); i++) {
			go(p, q, C[i]);
			int b = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (S[i][j] == 'B') {
						b += 1;
					}
				}
			}		
			if (b == goal) {
				break;
			}
		}
		bool ok = false;
		int b = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (S[i][j] == 'B') {
					b += 1;
				}
			}
		}		
		if (b == goal) ok = true;

		cout << "Game " << t++ << ": " << (ok ? "complete\n" : "incomplete\n");

		for (int i = 0; i < N; i++) {
			cout << S[i] << "\n";
		}
	}
    return 0;
}
