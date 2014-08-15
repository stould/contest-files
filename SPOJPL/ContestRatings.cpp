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

const int MAXN = 300005;

struct data {
	int id, a, b;

	data(){}
	data(int id, int a, int b): id(id), a(a), b(b) {}

	bool operator<(const data& other) const {
		if (a != other.a) {
			return a < other.a;
		} else {
			return b < other.b;
		}
	}
};

int N;
data P[MAXN];

int tree[MAXN];

int read(int id) {
	int ans = 0;

	for (int i = id; i > 0; i -= (i & -i)) {
		ans += tree[i];
	}

	return ans;
}

void update(int id, int v) {
	for (int i = id; i < MAXN; i += (i & -i)) {
		tree[i] += v;
	}
}

int main(void) {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		P[i].id = i;
		scanf("%d%d", &P[i].a, &P[i].b);
	}

	sort(P, P + N);

	vector<int> ans(N);

	for (int i = 0; i < N; ) {
		int j = i;
		
		//make sure everyone is less than you
		for ( ; j < N && P[i].a == P[j].a && P[i].b == P[j].b; ) {
			j += 1;
		}

		for (int k = i; k < j; k++) {
			ans[P[k].id] = read(P[k].b);
		}

		for (int k = i; k < j; k++) {
			update(P[k].b, 1);
		}
		i = j;
	}

	for (int i = 0; i < N; i++) {
		printf("%d\n", ans[i]);
	}

    return 0;
}
