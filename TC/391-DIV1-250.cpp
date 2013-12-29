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

class IsomorphicWords {
public:
	int countPairs(vector <string>);
};

bool func(string a, string b) {
	int i;
	int j;
	int N = a.size();
	
	map<char, set<char> > mapp;
	map<char, set<char> >::iterator it;
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) if (i != j) {
			if (a[i] == a[j] && b[j] != b[i]) {
				return false;
			}
			if (b[i] == b[j] && a[j] != a[i]) {
				return false;
			}
		}
	}
	
	return true;
}

int IsomorphicWords::countPairs(vector <string> words) {
	int i;
	int j;
	
	int N = (int) words.size();
	
	int ans = 0;
	
	for (i = 0; i < N; i++) {
		for (j = i + 1; j < N; j++) {
			if (func(words[i], words[j])) {
				ans += 1;
			}	
		}
	}	
	
	return ans;
}

//Powered by [KawigiEdit] 2.0!
