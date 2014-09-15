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

const int MAXN = 100005;

int N;
vector<int> graph[MAXN];

bool bpm(int u, bool seen[], int matchR[]) {
    for (int i = 0; i < (int) graph[u].size(); i++) {
		int v = graph[u][i];

        if (!seen[v]) {
            seen[v] = true; 
 
            if (matchR[v] < 0 || bpm(matchR[v], seen, matchR)) {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}
 
vector<pair<int, int> > maxBPM() {
    int matchR[MAXN];
	vector<pair<int, int> > ans;

    memset(matchR, -1, sizeof(matchR));
 
    int result = 0; 
    for (int u = 1; u <= N; u++) {
        bool seen[MAXN];
        memset(seen, 0, sizeof(seen));
 
        if (bpm(u, seen, matchR)) {
            result++;
		}
    }
	if (result == N || (N % 2 == 1 && result == N - 1)) {		
		vector<bool> seen(N + 1, false);
		for (int i = 1; i <= N; i++) {
			if (matchR[i] != -1 && !seen[matchR[i]] && !seen[i]) {
				ans.push_back(make_pair(min(i, matchR[i]), max(i, matchR[i])));
				seen[matchR[i]] = seen[i] = true;
			}
		}
	}
	return ans;
}


int main(void) {
	for ( ; scanf("%d", &N) == 1; ) {
		int X, Y;

		for (int i = 0; i <= N; i++) {
			graph[i].clear();
		}

		for (int i = 0; i < N - 1; i++) {
			scanf("%d%d", &X, &Y);
			if (N % 2 != 0 && (X == 1 || Y == 1)) continue;
			graph[X].push_back(Y);
			graph[Y].push_back(X);
		}

		for (int i = 1; i <= N; i++) {
			sort(graph[i].begin(), graph[i].end());
		}

		vector<pair<int, int> > ans = maxBPM();

		if (ans.empty()) {
			printf("N\n");
		} else {
			printf("Y\n");
			for (int i = 0; i < (int) ans.size(); i++) {
				printf("%d %d\n", ans[i].first, ans[i].second);
			}
		}
	}
    return 0;
}
