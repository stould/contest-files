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
Int val;

Int fact(int x) {
	if (x == 0) return 1LL;
	return x * fact(x - 1);
}

Int fat(vector<int>& s) {
	Int ans = 1LL;

	for (int i = 0; i < (int) s.size(); i++) {
		ans *= fact(s[i]);
	}
	
	return ans;
}


int main(void) {
	cin >> N;
	
	vector<int> digit;

	cin >> val;

	for (int i = 0; i < N; i++) {
		digit.push_back(val % 10);
		val /= 10;
	}

	int M = (int) digit.size();
	
	vector<int> buff;
	
	for (int i = 0; i < M; i++) {
		if (digit[i] <= 1) continue;
		if (digit[i] == 4) {
			buff.push_back(2);
			buff.push_back(2);
			buff.push_back(3);
		} else if (digit[i] == 6) {
			buff.push_back(3);
			buff.push_back(5);
		} else if (digit[i] == 8) {
			buff.push_back(2);
			buff.push_back(2);
			buff.push_back(2);
			buff.push_back(7);
		} else if (digit[i] == 9) {
			buff.push_back(2);
			buff.push_back(3);
			buff.push_back(3);
			buff.push_back(7);
		} else {
			buff.push_back(digit[i]);
		}
	}

	sort(buff.rbegin(), buff.rend());

	for (int i = 0; i < (int) buff.size(); i++) {
		cout << buff[i];
	}
	cout << "\n";

    return 0;
}
