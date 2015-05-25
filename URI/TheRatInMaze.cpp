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

const int MAXN = 4040;

int N, M, id = 1;
vector<int> graph[MAXN];
map<string, int> msi;
int dst[MAXN];

int getId(string s) {
	if (msi[s] == 0) {
		msi[s] = id++;
	}
	return msi[s];
}

int func(int st, int ed) {
	queue<int> q;
	q.push(st);

	memset(dst, 63, sizeof(dst));
	
	dst[st] = 0;

	for ( ; !q.empty(); ) {
		int now_id = q.front();
		q.pop();
		
		for (int i = 0; i < (int) graph[now_id].size(); i++) {
			int u = graph[now_id][i];

			if (dst[u] > dst[now_id] + 1) {
				dst[u] = dst[now_id] + 1;
				q.push(u);
			}
		}
	}
	
	return dst[ed];
}

int main(void) {
	cin >> N >> M;

	string A, B;
	
	for (int i = 0; i < M; i++) {
		cin >> A >> B;

		int ida = getId(A);
		int idb = getId(B);

		graph[ida].push_back(idb);
		graph[idb].push_back(ida);
	}

	int id_in = getId("Entrada");
	int id_st = getId("*");
	int id_ot = getId("Saida");

	int ans = func(id_in, id_st) + func(id_st, id_ot);

	cout << ans << endl;
	
	return 0;
}
