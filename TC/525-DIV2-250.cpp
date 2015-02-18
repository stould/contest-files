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

class RainyRoad {
public:
	string isReachable(vector <string>);
};

string RainyRoad::isReachable(vector <string> road) {
	int i;
	int N = (int) road[0].size();
	
	for (i = 0; i < N; i++) {
		if (road[0][i] == 'W' && road[1][i] == 'W') return "NO";
	}
	
	return "YES";
}

//Powered by [KawigiEdit] 2.0!
