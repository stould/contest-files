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

const int MAXN = 420;

int N, M;
int G[MAXN][MAXN];
int dist[MAXN];

int bfsA() {
	queue<int> q;
	q.push(1);

	memset(dist, 63, sizeof(dist));

	dist[1] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		
		for (int i = 1; i <= N; i++) {
			if (G[now][i]) {				
				if (dist[i] > dist[now] + 1) {
					dist[i] = dist[now] + 1;
					q.push(i);
				}
			}
		}
	}
	
	return dist[N];
}

int bfsB() {
	queue<int> q;
	q.push(1);

	memset(dist, 63, sizeof(dist));

	dist[1] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (!G[now][i]) {
				if (dist[i] > dist[now] + 1) {
					dist[i] = dist[now] + 1;
					q.push(i);
				}
			}
		}
	}

	return dist[N];
}

int main(void) {
	cin >> N >> M;

	int A, B;
	
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		G[A][B] = 1;
		G[B][A] = 1;
	}

	int ta = bfsA();
	int tb = bfsB();

	int ans = max(ta, tb);

	if (ans >= 1061109567) {
		ans = -1;
	}
	
	cout << max(ta, tb) << "\n";
	
	return 0;
}
