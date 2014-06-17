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

int N;
string S;

vector<string> split(string s) {
	istringstream ss(s);
	vector<string> ans;
	string buff;

	for ( ; ss >> buff; ) {
		ans.push_back(buff);
	}

	return ans;
}

int toNum(string s) {
	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		ans = (ans * 10) + (s[i] - '0');
	}
	return ans;
}

int main(void) {
	int t = 1;
	bool ok = false;
	for ( ; cin >> N; ) {
		if (ok) cout << "\n";
		ok = true;
		cin.ignore();
		getline(cin, S);
		
		vector<string> vs = split(S);

		int masc = 0, fem = 0, ans = 0;

		for (int i = 0; i < (int) vs.size(); i += 2) {
			int num = toNum(vs[i]);

			if (num == N) {
				ans += 1;
				if (vs[i + 1] == "M") {
					masc += 1;
				} else {
					fem += 1;
				}
			}
		}

		cout << "Caso " << t++ << ":\n" << "Pares Iguais: " << ans << "\n" << "F: " << fem << "\n" << "M: " << masc << "\n";
	}
    return 0;
}
