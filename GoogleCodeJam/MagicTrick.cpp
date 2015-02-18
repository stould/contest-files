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

int T, P;
map<int, int> mp;

void rd(void) {
	cin >> P;		

	int tmp;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d", &tmp);
			
			if (i + 1 == P) {
				mp[tmp] += 1;
			}
		}
	}	
}

int main(void) {
	cin >> T;
	freopen("o.ot", "w", stdout);
	int P;

	for (int t = 1; t <= T; t++) {
		mp.clear();

		rd();
		rd();

		auto it = mp.begin();

		int ans = 0, cnt = 0;

		for ( ; it != mp.end(); it++) {
			if (it->second == 2) {
				ans = it->first;
				cnt += 1;
			}
		}
		printf("Case #%d: ", t);

		if (cnt == 1) {
			printf("%d\n", ans);
		} else if (cnt > 1) {
			printf("Bad magician!\n");
		} else {
			printf("Volunteer cheated!\n");
		}
	}
    return 0;
}
