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
typedef unsigned long long uInt;
typedef unsigned uint;

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

const int MAXN = 100010;

int T;
int N, K;
string S, P[1010];
bool ans[1010];

map<char, pair<int, int> > to[MAXN];
map<char, vector<int> > end_point[MAXN];
int link[MAXN], que[MAXN], sz = 1;
 
void add_str(string s, int id) {
    int v = 0;
	for (int i = 0; i < (int) s.size(); i++) {
		char c = s[i];
		
        if(!to[v][c].first) {
			to[v][c].first = sz++;
		}
		if (i == (int) s.size() - 1) {
			to[v][c].second += 1;
			end_point[v][c].push_back(id);
		}
        v = to[v][c].first;
    }
}

void push_links() {
	link[0] = -1;
	int st = 0, fi = 1;
	que[0] = 0;
	
	while (st < fi) {
		int v = que[st++];

		for (auto it: to[v]) {
			int u = it.second.first;
			int c = it.first;
			int j = link[v];
			while (j != -1 && !to[j][c].first) {
				j = link[j];
			}
			if(j != -1) {
				link[u] = to[j][c].first;
			}
			que[fi++] = u;
		}
	}
}

void search() {	
}

int main(void) {
	cin >> T;

	while (T--) {
		cin >> S >> K;

		for (int i = 0; i < MAXN; i++) {
			to[i].clear();
			end_point[i].clear();
		}
		
		for (int i = 0; i < K; i++) {
			cin >> P[i];

			add_str(P[i], i);
		}

		push_links();
	}
	return 0;
}
