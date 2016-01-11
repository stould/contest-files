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

const int MAXN = 1010;

int N, M;
string S[MAXN], ans[MAXN];
bool vis[MAXN][MAXN];
int id_mem[MAXN][MAXN];
int sum_comp[MAXN * MAXN];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool valid(int i, int j) {
	return i >= 0 && j >= 0 && i < N && j < M;
}

void dfs(int i, int j, int id) {
	vis[i][j] = true;
	id_mem[i][j] = id;

	sum_comp[id] += 1;

	for (int x = 0; x < 4; x++) {
		int ii = i + dx[x];
		int jj = j + dy[x];

		if (valid(ii, jj) && S[ii][jj] == '.' && !vis[ii][jj]) {
			dfs(ii, jj, id);
		}
	}
}
int main(void) {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> S[i];
		ans[i] = S[i];
	}

	int comp_id = 1;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (S[i][j] == '.' && !vis[i][j]) {
				dfs(i, j, comp_id++);
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (S[i][j] == '*') {
				int sum = 1;
				set<int> cnt;
				
				for (int k = 0; k < 4; k++) {
					int ii = i + dx[k];
					int jj = j + dy[k];

					if (valid(ii, jj) && S[ii][jj] == '.') {						
						if (!cnt.count(id_mem[ii][jj])) {							
							sum += sum_comp[id_mem[ii][jj]];
							cnt.insert(id_mem[ii][jj]);
						}
					}
				}
				
				ans[i][j] = '0' + (sum % 10);
			}			
		}
	}
	
	for (int i = 0; i < N; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}
