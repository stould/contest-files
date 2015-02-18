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

const int INF = 101010101;
const int MAXN = 110;

int T, N;
string S[MAXN];

int sz;

map<string, int> mall, mapp;

int bfs(string S, int it) {
	queue<string> q;
	q.push(S);

	map<string, int> mt;
	set<string> buff;
	int ans = INF;

	mt.clear();
	buff.clear();

	for ( ; !q.empty(); ) {
		string p = q.front();
		q.pop();		

		cout << p << "\n";

		if (!buff.count(p)) {
			buff.insert(p);
			mapp[p] += 1;
		}

		if (mapp[p] == N) {
			ans = min(ans, mall[p]);
		}

		for (int i = 0; i < (int) p.size(); i++) {
			string pa = p.substr(0, i) + p[i] + p.substr(i, p.size() - i);

			if ((mt[pa] == 0 && pa != S) && pa.size() < sz) {
				q.push(pa);
				mt[pa] = mt[p] + 1;
				mall[pa] += mt[pa];
			}
			if (i != p.size() - 1 && p[i] == p[i + 1]) {
				string pb = p;
				pb.erase(i, 1);

				if ((mt[pb] == 0 && pb != S) && pb.size() < sz) {
					q.push(pb);
 					mt[pb] = mt[p] + 1;
					mall[pb] += mt[pb];
				}
			}
		}
	}
	return ans;
}

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;		
		int ans = INF;
		mall.clear();
		mapp.clear();
		for (int i = 0; i < N; i++) {
			cin >> S[i];
			sz = max(sz, (int) S[i].size());
			int p = bfs(S[i], i);
			if (i == N - 1) ans = min(ans, p);
		}

		cout << "Case #" << t << ": ";

		if (ans == INF) {
			cout << "Fegla Won\n";
		} else {
			cout << ans << "\n";
		}
	}
    return 0;
}
