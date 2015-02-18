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

class WhichDay {
public:

	string getDay(vector <string>);
};

string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

string WhichDay::getDay(vector <string> notOnThisDay) {
	int i;
	
	vector<string> vs(days, days + 7);
	
	for (i = 0; i < 7; i++) {
		if (find(notOnThisDay.begin(), notOnThisDay.end(), vs[i]) == notOnThisDay.end()) {
			return vs[i];
		}
	}
	return "";
}

//Powered by [KawigiEdit] 2.0!



