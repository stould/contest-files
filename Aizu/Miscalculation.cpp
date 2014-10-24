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

string S;
int res;

int toInt(string s) {
	int ans = 0;
	
	for (int i = 0; i < (int) s.size(); i++) {
		ans = ans * 10 + (s[i] - '0');
	}

	return ans;
}

string toString(int s) {
	string ans = "";

	while (s > 0) {
		ans = char('0' + s % 10) + ans;
		s /= 10;
	}

	return ans;
}

bool evalR(string s) {
	vector<string> vs;

	for (int i = 0; i < s.size(); i++) {
		vs.push_back(string(1, s[i]));
	}

	for (int i = 0; i < vs.size(); i++) {
		if (vs[i] == "*") {
			int l = 0, r = 0;

			for (int j = 0; j < vs[i - 1].size(); j++) {
				l = l * 10 + (vs[i - 1][j] - '0');
			}

			for (int j = 0; j < vs[i + 1].size(); j++) {
				r = r * 10 + (vs[i + 1][j] - '0');
			}


			int ins = l * r;

			vs.erase(vs.begin() + i - 1, vs.begin() + i + 2);
			vs.insert(vs.begin() + i - 1, toString(ins));
			i--;
		}
	}
	
	for (int i = 0; i < vs.size(); i++) {
		if (vs[i] == "+") {
			int l = 0, r = 0;

			for (int j = 0; j < vs[i - 1].size(); j++) {
				l = l * 10 + (vs[i - 1][j] - '0');
			}

			for (int j = 0; j < vs[i + 1].size(); j++) {
				r = r * 10 + (vs[i + 1][j] - '0');
			}

			int ins = l + r;

			vs.erase(vs.begin() + i - 1, vs.begin() + i + 2);
			vs.insert(vs.begin() + i - 1, toString(ins));
			i--;
		}
	}	
	
	return toInt(vs[0]) == res;
}

bool evalF(string s) {
	vector<string> vs;

	for (int i = 0; i < s.size(); i++) {
		vs.push_back(string(1, s[i]));
	}
	
	for (int i = 0; i < vs.size(); i++) {
		if (vs[i] == "*" || vs[i] == "+") {
			int l = 0, r = 0;

			for (int j = 0; j < vs[i - 1].size(); j++) {
				l = l * 10 + (vs[i - 1][j] - '0');
			}

			for (int j = 0; j < vs[i + 1].size(); j++) {
				r = r * 10 + (vs[i + 1][j] - '0');
			}


			int ins = -1;

			if (vs[i] == "+") {
				ins = l + r;
			} else {
				ins = l * r;
			}

			vs.erase(vs.begin() + i - 1, vs.begin() + i + 2);
			vs.insert(vs.begin() + i - 1, toString(ins));
			i--;
		}
	}

	return toInt(vs[0]) == res;
}

int main(void) {
	cin >> S >> res;

	bool R = evalR(S);
	bool F = evalF(S);

	if (R && F) {
		cout << "U\n";
	} else if (R) {
		cout << "M\n";
	} else if (F) {
		cout << "L\n";
	} else {
		cout << "I\n";
	}

    return 0;
}
