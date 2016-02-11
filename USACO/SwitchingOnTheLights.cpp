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

const int MAXN = 110;

int N, M;
vector<pair<int, int> > L[MAXN][MAXN];
bool on[MAXN][MAXN], vis[MAXN][MAXN];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(void) {
	freopen("lightson.in", "r", stdin);
	freopen("lightson.out", "w", stdout);
	
	cin >> N >> M;

	int A, B, X, Y;

	queue<pair<int, int> > q;

	for (int i = 0; i < M; i++) {
		cin >> A >> B >> X >> Y;

		L[A][B].push_back(make_pair(X, Y));
	}

	q.push(make_pair(1, 1));
	on[1][1] = vis[1][1] = true;

	while (!q.empty()) {
		queue<pair<int, int> > qs;
		
		while (!q.empty()) {
			int xi = q.front().first;
			int xj = q.front().second;

			//cout << "on " << xi << " " << xj << "\n";
			
			qs.push(q.front());
			q.pop();
			
			on[xi][xj] = true;
			
			for (int i = 0; i < (int) L[xi][xj].size(); i++) {
				int yi = L[xi][xj][i].first;
				int yj = L[xi][xj][i].second;
				
				on[yi][yj] = true;			
			}
		}
		
		for (int xi = 1; xi <= N; xi++) {
			for (int xj = 1; xj <= N; xj++) {
				if (vis[xi][xj]) {
					for (int i = 0; i < 4; i++) {
						int yi = xi + dx[i];
						int yj = xj + dy[i];
				
						if (yi >= 1 && yj >= 1 && yi <= N && yj <= N && on[yi][yj]) {
							if (!vis[yi][yj]) {
								//cout << "vis " << yi << " " << yj << "\n";
								q.push(make_pair(yi, yj));
								vis[yi][yj] = true;
							}
						}
					}
				}
			}
		}
	}
	
	int ans = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans += (on[i][j] == true);
		}
	}

	cout << ans << "\n";
	
	return 0;
}
