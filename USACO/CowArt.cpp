#include <iostream>
#include <cstring>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

int N;
string S[110];
bool vis[110][110];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfsH(int x, int y) {
	vis[x][y] = true;
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
			if (!vis[nx][ny]) {
				if (S[x][y] == S[nx][ny]) {
					dfsH(nx, ny);
				}
			}
		}
	}
}

void dfsC(int x, int y) {
	vis[x][y] = true;
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
			if (!vis[nx][ny]) {
				if (S[x][y] == S[nx][ny]) {
					dfsC(nx, ny);
				} else {
					if ((S[x][y] == 'R' && S[nx][ny] == 'G') || (S[x][y] == 'G' && S[nx][ny] == 'R')) {
						dfsC(nx, ny);
					}
				}
			}
		}
	}
}

int main(void) {
	freopen("cowart.in", "r", stdin);
	freopen("cowart.out", "w", stdout);
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}

	int sH = 0;
	int sC = 0;

	memset(vis, false, sizeof(vis));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!vis[i][j]) {
				sH += 1;
				dfsH(i, j);
			}
		}
	}

	memset(vis, false, sizeof(vis));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!vis[i][j]) {
				sC += 1;
				dfsC(i, j);
			}
		}
	}

	cout << sH << " " << sC << "\n";

    return 0;
}
