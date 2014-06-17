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

const int MAXN = 1010;

int N, M;
int P[MAXN];

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second != b.second ? a.second > b.second : a.first > b.first;
	}
};

int main(void) {
	scanf("%d%d", &N, &M);
	priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;

	for (int i = 0; i < N; i++) {
		pq.push(make_pair(i, 0));
	}
	for (int i = 0; i < M; i++) {
		int b;
		scanf("%d", &b);
		
		pair<int, int> current = pq.top();
		pq.pop();

		P[current.first] += 1;
		current.second += b;
		pq.push(current);
	}
	for (int i = 0; i < N; i++) {
		printf("%d %d\n", i + 1, P[i]);
	}
    return 0;
}
