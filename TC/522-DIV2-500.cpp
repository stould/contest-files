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

class RowAndManyCoins {
public:

	string getWinner(string);
};

string RowAndManyCoins::getWinner(string cells) {
	if (cells[0] == 'A' || cells[cells.size() - 1] == 'A') {
		return "Alice";
	} else {
		return "Bob";
	}
}

//Powered by [KawigiEdit] 2.0!
