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

const int MAXN = 50004;
const double EPS = 1e-7;

int N;
pair<int, int> P[MAXN];
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
        bool seen[MAXN];
        memset(seen, 0, sizeof(seen));
 
        if (matchR[u] == -1 && bpm(u, seen, matchR)) {
            result++;
		}
    }
    return result;
}

double dist(int a, int b) {
	return hypot(P[a].first - P[b].first, P[a].second - P[b].second);
}

int main(void) {
	while (cin >> N) {
		map<pair<int, int>, int > mp;
		for (int i = 0; i < N; i++) {
			cin >> P[i].first >> P[i].second;
			graph[i].clear();
			mp[P[i]] = i;
		}		
		
		for (int i = 0; i < N; i++) {
			for (int x = -5; x <= 5; x++) {
				for (int y = -5; y <= 5; y++) {
					double px = P[i].first - (P[i].first + x);
					double py = P[i].second - (P[i].second - y);
					
					if (px * px + py * py + EPS <= 25) {
						pair<int, int> npair = make_pair(P[i].first + x, P[i].second + y);

						if (mp.find(npair) != mp.end() && mp[npair] != i) {
							//cout << P[i].first << " " << P[i].second << " " << npair.first << " " << npair.second << endl;
							graph[i].push_back(mp[npair]);
						}
					}
				}
			}
		}

		cout << maxBPM() << endl;
	}
	return 0;
}
