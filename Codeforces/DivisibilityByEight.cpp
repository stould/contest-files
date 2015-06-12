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

int str_to_int(string arg) {
	int ans = 0;

	for (int i = 0; i < (int) arg.size(); i++) {
		ans = ans * 10 + (arg[i] - '0');
	}
	return ans;
}

bool found(int value) {
	int seen = 0;
	int vlen = 0, t = value;

	while (t > 0) {
		vlen += 1;
		t /= 10;
	}
	
	for (int i = N - 1; i >= 0; i--) {
		if (S[i] - '0' == value % 10) {
			value /= 10;
			seen += 1;
			if (seen == vlen) break;
		}
	}
	return seen == vlen;
}
int main(void) {
	cin >> S;
	N = (int) S.size();

	bool has_zero = false;
	
	for (int i = 0; i < N; i++) {
		if (S[i] == '0') {
			has_zero = true;
		}
	}

	if (has_zero) {
		cout << "YES" << endl << "0" << endl;
	} else {
		vector<int> div;
		
		for (int i = 1; i < 10000; i++) {
			if (i % 8 == 0) {
				div.push_back(i);
			}
		}
		
		bool ok = false;
		
		for (int i = 0; i < (int) div.size(); i++) {
			if (found(div[i])) {
				cout << "YES" << endl;
				cout << div[i] << endl;
				ok = true;
				break;
			}
		}
		if (!ok) {
			cout << "NO" << endl;
		}
	}								 
	return 0;
}
