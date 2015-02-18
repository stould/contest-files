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

class ColorfulRabbits {
public:

	int getMinimum(vector <int>);
};

int ColorfulRabbits::getMinimum(vector <int> replies) {
	int ans = 0;
	map<int, int> rep;
	
	for (auto& r : replies) rep[r] += 1;
	
	for (auto it = rep.begin(); it != rep.end(); it++) {
		int cnt = it->first + 1, bf = 0;
		
		for ( ; bf < it->second; ) {
			bf += cnt;
		}		
		
		ans += bf;
	}
	
	return ans;
}

//Powered by [KawigiEdit] 2.0!


