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

class SplitIntoPairs {
public:

	int makepairs(vector <int>, int);
};

int SplitIntoPairs::makepairs(vector <int> A, int X) {
	int N = (int) A.size();
	vector<int> P, Q;
	
	int ans = 0;
	
	for (int i = 0; i < N; i++) {
		if (A[i] >= 0) {
			P.push_back(A[i]);
		} else {
			Q.push_back(A[i]);
		}
	}
	
	int NP = (int) P.size();
	int NQ = (int) Q.size();
	
	sort(P.begin(), P.end());
	sort(Q.rbegin(), Q.rend());
	
	vector<int> rem;

	ans += max(0, NP / 2);
	ans += max(0, NQ / 2);
	
	if (NP % 2 != 0) {
		rem.push_back(P[0]);
	}	
	if (NQ % 2 != 0) {
		rem.push_back(Q[0]);
	}
	
	if (rem.size() == 2) {
		Int r = (Int) rem[0] * (Int) rem[1];
		
		if (r >= X) ans += 1;
	}
	
	return ans;
}

//Powered by [KawigiEdit] 2.0!
