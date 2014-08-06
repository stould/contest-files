#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <functional>
#include <valarray>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <climits>

using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REV(i, a, n) for(int i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;

const int MAXN = 1000010;

int N;
int P[MAXN];
struct tr {
	int f, p, id;

	tr(){}

	tr(int f, int p, int id): f(f), p(p), id(id) {}

	bool operator<(const tr& t) const {
		return f + p > t.f + t.p;
	}
};

int main(void) {
    scanf("%d", &N);

	int sum = 0;
	vector<int> ans(N);
	vector<tr> vt(N);
	

    REP(i, N) {
        scanf("%d%d", &vt[i].p, &vt[i].f);
		P[i] = vt[i].p;
		vt[i].id = i + 1;
		sum += vt[i].p;
    }
	
	sort(vt.begin(), vt.end());

	set<int> id;
	int pos = 0;

	for (int i = 0; i < N; i++) {
		while (pos < N && vt[pos].f >= sum - vt[pos].p) {
			id.insert(vt[pos].id);
			pos++;
		}
		if (id.empty()) {
			puts("IMPOSSIVEL");
			return 0;
		} 
		int k = *id.begin();

		ans[i] = k;
		id.erase(k);
		sum -= P[k - 1];
	}
	
	for (int i = 0; i < N; i++) {
		printf("%d\n", ans[i]);
	}

    return 0;
}

