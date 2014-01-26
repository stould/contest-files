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
string cap;
vector<string> rat, wom, man;

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		string S, T;
		cin >> S >> T;

		if (T == "rat") {
			rat.push_back(S);
		} else if (T == "man") {
			man.push_back(S);
		} else if (T == "woman" || T == "child") {
			wom.push_back(S);
		} else {
			cap = S;
		}
	}
	for (auto& t: rat) {
		cout << t << "\n";
	}
	for (auto& t: wom) {
		cout << t << "\n";
	}
	for (auto& t: man) {
		cout << t << "\n";
	}
	cout << cap << "\n";

    return 0;
}
