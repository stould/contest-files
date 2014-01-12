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

using namespace std;

typedef long long Int;
typedef unsigned uint;

class FoxAndIntegers {
public:

	vector <int> get(int, int, int, int);
};

vector <int> FoxAndIntegers::get(int AminusB, int BminusC, int AplusB, int BplusC) {
	bool ok = false;
	vector<int> ans(3);
	
	for (int a = -60; a <= 60; a++) {
		for (int b = -60; b <= 60; b++) {
			for (int c = -60; c <= 60; c++) {
				int apb = a + b;
				int bmc = b - c;
				int amb = a - b;
				int bpc = b + c;
				
				if (apb == AplusB && amb == AminusB && bmc == BminusC && bpc == BplusC) {
					ans[0] = a;
					ans[1] = b;
					ans[2] = c;
					ok = true;
				}
			}
		}
	}
	
	if (!ok) {
		ans = vector<int>();
	}	
	
	return ans;	
}

//Powered by [KawigiEdit] 2.0!
