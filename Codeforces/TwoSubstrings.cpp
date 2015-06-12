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

int main(void) {
	cin >> S;
	vector<int> s1, s2;

	for (int i = 0; i < (int) S.size() - 1; i++) {
		if (S[i] == 'A' && S[i + 1] == 'B') {
			s1.push_back(i);
		}
		if (S[i] == 'B' && S[i + 1] == 'A') {
			s2.push_back(i);
		}
	}
	
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	if (s1.empty() or s2.empty()) {
		cout << "NO" << endl;
	} else {
		if ((s1[0] + 1 < s2[s2.size() - 1]) or (s2[0] + 1 < s1[s1.size() - 1])) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
