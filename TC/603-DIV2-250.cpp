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

class MiddleCode {
public:

	string encode(string);
};

string MiddleCode::encode(string s) {
	string t = "";
	
	for ( ; !s.empty(); ) {
		int N = (int) s.size();
		
		if (N % 2 == 0) {
			int a = N / 2;
			int b = N / 2 - 1;
			
			if (s[a] < s[b]) {
				t += s[a];
				s.erase(s.begin() + a);
			} else {
				t += s[b];
				s.erase(s.begin() + b);			
			}
		} else {
			int pos = N / 2;
			t += s[pos];
			s.erase(s.begin() + pos);
		}
	}
	
	return t;	
}

//Powered by [KawigiEdit] 2.0!
