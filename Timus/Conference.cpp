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

const int MAXN = 3005;

int N, M, K;

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
    for (int u = 1; u <= N; u++) {
        bool seen[MAXN];
        memset(seen, 0, sizeof(seen));
 
        if (bpm(u, seen, matchR)) {
            result++;
		}
    }
    return result;
}

int main(void) {
	cin >> N >> M >> K;

	int A, B;

	for (int i = 0; i < K; i++) {
		cin >> A >> B;
		graph[A].push_back(N + B);
		graph[N + B].push_back(A);
	}
	
	cout << maxBPM() << "\n";
    return 0;
}
