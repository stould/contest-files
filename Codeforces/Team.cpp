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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

int Z, U;

int main(void) {
	cin >> Z >> U;

	//string ans = "";
	list<int> ans;
	for (int i = 0; i < U; i++) {
		//ans += "1";
		ans.push_back(1);
	}

	U = 0;
	list<int>::iterator b2, b1, n1;
	
	for (list<int>::iterator it = ans.begin(); it != ans.end(); it++) {
		n1 = it + 1;
	for (int i = 1; i < (int) ans.size() && Z > 0; i++) {
		if (i - 2 >= 0 && i + 1 < (int) ans.size() && ans[i - 2] == '1' && ans[i - 1] == '1' && ans[i] == '1' && ans[i + 1] == '1') {
			ans = ans.substr(0, i) + "0" + ans.substr(i, ans.size() - i);
			i -= 2;
			Z -= 1;
		}
	}

	for (int i = (int) ans.size(); i >= 0 && Z > 0; i--) {
		if (i  - 1 >= 0 && ans[i - 1] == '1' && ans[i] == '1') {
			ans = ans.substr(0, i) + "0" + ans.substr(i, ans.size() - i);
			Z -= 1;
		}
	}

	if (Z > 0 && ans.back() == '1') {
		ans += "0";
		Z -= 1;
	}
	if (Z > 0 && ans.front() == '1') {
		ans = "0" + ans;
		Z -= 1;
	}

	if (U + Z != 0) ans = "-1";
	//cout << ans << endl;
	for (int i = 0; i < (int) ans.size(); i++) {
		if (i + 1 < (int) ans.size() && ans[i] == '0' && ans[i + 1] == '0') {
			ans = "-1";
			break;
		}
		if (i + 2 < (int) ans.size() && ans[i] == '1' && ans[i + 1] == '1' && ans[i + 2] == '1') {
			ans = "-1";
			break;
		}
	}
	
	cout << ans << endl;

	return 0;
}
