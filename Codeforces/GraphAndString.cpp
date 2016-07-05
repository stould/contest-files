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

const int MAXN = 502;

int N, M;
int P[MAXN][MAXN];
vector<int> G[MAXN], GA[MAXN];
vector<int> comp;
bool vis[MAXN];
int color[MAXN];

void dfs(int x) {
	vis[x] = true;

	for (int i = 0; i < (int) GA[x].size(); i++) {
		int u = G[x][i];

		if (!vis[u]) {
			dfs(u);
		}
	}
}

bool dfs_color(int node, int c) {
    if(color[node] != 0) {
        if(color[node] == c) {
            return true;
        } else {
            return false;
        }
    }
    color[node] = c;
	
    for(int i = 0; i < (int) GA[node].size(); i++) {
		if(!dfs_color(GA[node][i], -c)) {
			return false;
		}
	}
	
	return true;
}

int main(void) {
	cin >> N >> M;

	string S(N, 'b');
	
	for (int i = 0; i < M; i++) {
		int A, B;
		
		cin >> A >> B;

		A -= 1;
		B -= 1;
		
		P[A][B] = 1;
		P[B][A] = 1;

		G[A].push_back(B);
		G[B].push_back(A);
	}

	bool valid = true;

	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (i != j && !P[i][j]) {
				GA[i].push_back(j);
				GA[j].push_back(i);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (!vis[i] && GA[i].size() > 0) {
			comp.push_back(i);
		}
	}

	for (int i = 0; i < (int) comp.size(); i++) {
		if (color[comp[i]] == 0 && !dfs_color(comp[i], 1)) {
			valid = false;
		}
	}

	for (int i = 0; i < N; i++) {
		if (color[i] == -1) {
			S[i] = 'a';
		}
		if (color[i] == 1) {
			S[i] = 'c';
		}		
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i != j) {
				if (P[i][j] && abs(S[i] - S[j]) > 1) {
					valid = false;
				}
				if (!P[i][j] && abs(S[i] - S[j]) <= 1) {
					valid = false;
				}					
			}
		}
	}

	if (valid) {
		cout << "Yes\n" << S << "\n";
	} else {
		cout << "No\n";
	}

	return 0;
}
