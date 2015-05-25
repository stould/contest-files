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
Int N, all = 0, len;

Int str_to_int(string arg) {
	Int ans = 0;

	for (int i = 0; i < (int) arg.size(); i++) {
		ans = ans * 10 + (arg[i] - '0');
	}
	
	return ans;
}

bool func(Int x) {
	Int sq = (Int) sqrt(x + 0.5);

	return sq * sq == x;
}

void rec(int id, int mask, Int val) {
	if (id == len) {
		if (func(val + N)) all += 1;
	} else {
		for (int i = 0; i < len; i++) {
			if (id == 0 && S[i] == '0') continue;
			if (!(mask & (1 << i))) {
				rec(id + 1, mask | (1 << i), val * 10 + (S[i] - '0'));
			}
		}
	}
}

int main(void) {
	cin >> S;

	len = (int) S.size();
	N = str_to_int(S);
	rec(0, 0, 0);
	
	/*	sort(S.begin(), S.end());

	do {
		if (S[0] == '0') continue;
		if (func(N + str_to_int(S))) {
			ans += 1;
		}
	} while (next_permutation(S.begin(), S.end()));
	*/
	cout << all << endl;
				 
	return 0;
}
