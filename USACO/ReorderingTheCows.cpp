#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <map>

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

const int MAXN = 105;

int N;
int A[MAXN], B[MAXN];

map<int, int> mp;
set<int> found;

int func(int id) {
	int ans = 0;

	for ( ; ; ) {
		found.insert(id);
		ans += 1;
		id = A[mp[id]];
		if (found.count(id)) {
			break;
		}
	}
	return ans;
}

int main(void) {
	freopen("reorder.in", "r", stdin);
	freopen("reorder.out", "w", stdout);

	N = in();

	for (int i = 0; i < N; i++) {
		A[i] = in();
	}
	for (int i = 0; i < N; i++) {
		B[i] = in();
		mp[B[i]] = i;
	}

	int cnt = 0, big = 0;

	for (int i = 0; i < N; i++) {
		if (!found.count(A[i])) {
			cnt += 1;
			big = max(big, func(A[i]));
		}
	}

	printf("%d %d\n", cnt, big);

    return 0;
}
