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

class RollingDiceDivTwo {
public:

	int minimumFaces(vector <string>);
};

int RollingDiceDivTwo::minimumFaces(vector <string> rolls) {
	int N = (int) rolls.size();
	int M = (int) rolls[0].size();
	
	int ans = 0;
	
	for (int x = 0; x < M; x++) {
		char bst = '0';
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				chmax(bst, rolls[i][j]);
			}
		}
		
		ans += bst - '0';
		
		for (int i = 0; i < N; i++) {
			bst = '0';
			for (int j = 0; j < M; j++) {
				chmax(bst, rolls[i][j]);
			}
			bool ok = false;
			for (int j = 0; j < M; j++) {
				if (rolls[i][j] == bst && !ok) {
					rolls[i][j] = '0';
					ok = true;
				}
			}
		}
	}
	
	return ans;
}

//Powered by [KawigiEdit] 2.0!



