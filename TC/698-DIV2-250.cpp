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

class Initials {
public:
	string getInitials(string);
};

string Initials::getInitials(string name) {
	string ans = "";
	
	for (int i = 0; i < name.size(); i++) {
		if (i == 0 || name[i - 1] == ' ') {
			ans += name[i];
		}
	}
	
	return ans;
}
//Powered by [KawigiEdit] 2.0!
