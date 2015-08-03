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

const int MAXN = 100010;

int N;
string P[MAXN];

Int toInt(string arg) {
	Int ans = 0LL;

	for (int i = 0; i < (int) arg.size(); i++) {
		ans = ans * 10 + (arg[i] - '0');
	}
	
	return ans;
}

void addRange(vector<string>& arg, int len, int pos) {
	string l = P[pos - len];
	string r = P[pos];

	int id = 0;
	string suffix = "";

	while (id < (int) l.size() && l[id] == r[id]) {
		id += 1;
	}
	while (id < (int) l.size()) {
		suffix += r[id];
		id += 1;
	}
	
	if (!arg.empty() && arg.back() == l) {
		arg.pop_back();
	}

	if (suffix == "") {
		arg.push_back(r);
	} else {
		arg.push_back(l + "-" + suffix);
	}
}

int main(void) {
	int test = 1;
	
	while (cin >> N && N != 0) {
		vector<string> ans;
		Int last = 0, len = 0;
		
		for (int i = 0; i < N; i++) {
			cin >> P[i];

			Int now = toInt(P[i]);

			if (last + 1 == now) {
				len += 1;
			} else {
				if (len > 0) {
					addRange(ans, len, i - 1);
				}
				ans.push_back(P[i]);
				len = 0;
			}
			last = now;
		}	
	
		addRange(ans, len, N - 1);

		cout << "Case " << test++ << ":" << endl;
		
		for (int i = 0; i < (int) ans.size(); i++) {
			cout << ans[i] << endl;
		}

		cout << endl;
	}
	
	return 0;
}
