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

const int MAXN = 105;
const Int INF = LLONG_MAX / 5;

int N, M;
uInt P[MAXN][MAXN], dp[MAXN][MAXN];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

uInt f(uInt a) {
     uInt res[] = {a,1,a+1,0};
     return res[a%4];
}

uInt getXor(uInt a, uInt b) {
	if (a == b) return a;
	uInt ans = (f(b)^f(a-1));
	return ans;
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	while (cin >> N >> M) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> P[i][j];
				dp[i][j] = INF;
			}
		}

		priority_queue<pair<long long, pair<int, int> > > q;
		q.push(make_pair(0LL, make_pair(0, 0)));
		
		dp[0][0] = 0LL;

		while (!q.empty()) {
			pair<uInt, pair<int, int> > curr = q.top();
			q.pop();

			int pi = curr.second.first;
			int pj = curr.second.second;

			if (-curr.first > dp[pi][pj]) continue;
						
			for (int i = 0; i < 4; i++) {
				int di = pi + dx[i];
				int dj = pj + dy[i];

				if (di >= 0 && dj >= 0 && di < N && dj < M) {
					uInt cst = getXor(min(P[pi][pj], P[di][dj]), max(P[pi][pj], P[di][dj]));
					
					if (dp[di][dj] > dp[pi][pj] + cst) {
						dp[di][dj] = dp[pi][pj] + cst;
						q.push(make_pair(-dp[di][dj], make_pair(di, dj)));						
					}
				}					
			}
		}

		cout << dp[N - 1][M - 1] << endl;
	}
	return 0;
}
