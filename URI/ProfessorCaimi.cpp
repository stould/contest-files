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

const int MAXN = 100005;

int N, M;
int color[MAXN];
vector<int> G[MAXN];

bool dfs(int node, int c) {
    if (color[node] != 0) {
        if (color[node] == c) {
            return true;
        } else {
            return false;
        }
    }
    color[node] = c;
    for (int i = 0; i < (int) G[node].size(); i++) {
		if (!dfs(G[node][i], -c)) {
			return false;
		}	
    }
    return true;
}


int main(void) {
	cin >> N >> M;

	int A, B;

	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		G[A].push_back(B);
		G[B].push_back(A);		
	}

	bool ok = true;

	for (int i = 1; i <= N; i++) {
		if (!color[i] && !dfs(i, 1)) {
			ok = false;
		}
	}

	if (ok) {
		cout << "Y\n";
	} else {
		cout << "N\n";
	}
	return 0;
}
