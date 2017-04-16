#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long Int;

#ifdef LOCAL
#define getchar_unlocked() getchar()
#endif

int n, sa, sb, sc, x;
vector<pair<Int, char> > ans;

inline void rd(int &x) {
	register int c = getchar_unlocked();
	x = 0;
	int neg = 0;

	if (c == EOF) {
		x = EOF;
		return;
	}

	for (; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

	if (c == '-') {
		neg = 1;
		c = getchar_unlocked();
	}

	for (; c>47 && c<58; c = getchar_unlocked()) {
		x = (x << 1) + (x << 3) + c - 48;
	}

	if (neg) {
		x = -x;
	}
}

int main(void) {

#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif
	
	cin >> n;
	for (int k = 0; k < n; k++) {
		rd(sa); rd(sb); rd(sc);

		Int aux = 0;
		for (int i = 0; i < sa; i++) {
			rd(x);
			if (x > 1)
				aux += ((Int)x * x * x);
		}
		ans.push_back(make_pair(aux, 'A'));
		aux = 0;
		for (int i = 0; i < sb; i++) {
			rd(x);
			if (x > 1)
				aux += ((Int)x * x * x);
		}
		ans.push_back(make_pair(aux, 'B'));
		aux = 0;
		for (int i = 0; i < sc; i++) {
			rd(x);
			if (x > 1)
				aux += ((Int)x * x * x);
		}
		ans.push_back(make_pair(aux, 'C'));

		sort(ans.begin(), ans.end());
		
		printf("Case #%d: ", k + 1);
		if (ans[2].first == ans[1].first)
			puts("TIE");
		else
			printf("%c\n", ans[2].second);
		ans.clear();
	}
	
	return 0;
}
