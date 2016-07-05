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
typedef unsigned uint;

const int MAXN = 300;

int T, N, K;
int X[MAXN], Y[MAXN];
string C[MAXN];
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
 
int maxBPM() {
    int matchR[MAXN];
 
    memset(matchR, -1, sizeof(matchR));
 
    int result = 0; 
    for (int u = 0; u < N; u++) {
		if (C[u] != "blue") continue;
		
        bool seen[MAXN];
        memset(seen, 0, sizeof(seen));
 
        if (bpm(u, seen, matchR)) {
            result++;
		}
    }
    return result;
}

int main(void) {
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N >> K;

		for (int i = 0; i < N; i++) {
			cin >> X[i] >> Y[i] >> C[i];					 
		}

		int l = 1, h = 10000, m;
		int best = INT_MAX;
		
		while (l <= h) {
			m = l + (h - l) / 2;

			for (int i = 0; i < MAXN; i++) {
				graph[i].clear();
			}
			
			for (int i = 0; i < N; i++) {
				if (C[i] == "blue") {
					for (int j = 0; j < N; j++) {
						if (C[j] == "red") {
							int dst = (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
							
							if (dst <= m * m) {
								graph[i].push_back(N + j);
							}
						}
					}
				}
			}

			int now = maxBPM();
			//cout << m << " "<< now << endl;
			if (now >= K) {
				best = min(best, m);
				h = m - 1;
			} else {
				l = m + 1;
			}
		}
		if (best == INT_MAX) {
			cout << "Impossible" << endl;
		} else {
			cout << best << endl;
		}
	}
	return 0;
}
