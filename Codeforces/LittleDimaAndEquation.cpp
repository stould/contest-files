#include <iostream>
#include <vector>
#include <cmath>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

int A, B, C;

int func(Int x) {
	int ans = 0;
	
	while (x > 0LL) {
		ans += (x % 10LL);
		x /= 10;
	}
	
	return ans;
}

Int ppow(int x, int p) {
	Int ans = 1LL;
	for (int i = 0; i < p; i++) {
		ans *= x;
	}
	return ans;
}

int main(void) {
	cin >> A >> B >> C;
	vector<Int> ans;

	for (int i = 1; i <= 9 * 9; i++) {
		Int value = ppow(i, A) * (Int) B + C;

		if (value > 0LL && value < 1000000000LL && func(value) == i) {
			ans.push_back(value);
		}
	} 
	if (ans.empty()) {
		cout << "0" << endl;
	} else {
		cout << (int) ans.size() << "\n";
		for (int i = 0; i < (int) ans.size(); i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
	
    return 0;
}
