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

string S, Q;

int main(void) {
	for ( ; cin >> S >> Q; ) {
		int ps = 0, pq = 0;

		while (ps < S.size() && S[ps] != '.') {
			ps += 1;
		}
		while (pq < Q.size() && Q[pq] != '.') {
			pq += 1;
		}
		
		string decS = "0";
		string decQ = "0";

		if (ps + 1 < S.size()) {
			decS = S.substr(ps + 1, S.size() - ps);
		}
		if (pq + 1 < Q.size()) {
			decQ = Q.substr(pq + 1, Q.size() - pq);
		}



		while (decS.size() < decQ.size()) {
			decS += "0";
		}
		while (decQ.size() < decS.size()) {
			decQ += "0";
		}

		//		cout << "Dec " << decS << " " << decQ << "\n";

		bool hi = false;

		for (int i = 0; i < decQ.size(); i++) {
			if (decQ[i] < decS[i]) {
				hi = true;
			} else if (decQ[i] > decS[i]) {
				break;
			}
		}

		int value = atoi(S.c_str());

		if (hi) value += 1;

		printf("%d\n", value);
	}
    return 0;
}
