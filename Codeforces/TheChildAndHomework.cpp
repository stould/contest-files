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

string S[4];
int len[4];

int main(void) {	
	int ans = 0, cnt = 0;

	for (int i = 0; i < 4; i++) {
		cin >> S[i];
		len[i] = S[i].size() - 2;
	}
	
	for (int i = 0; i < 4; i++) {
		int p1 = 0, p2 = 0;
		for (int j = 0; j < 4; j++) {
			if (i != j) {
				if (len[i] >= 2 * len[j]) {
					p1 += 1;
				}
				if (len[i] * 2 <= len[j]) {
					p2 += 1;
				}
			}
		}
		if (p1 == 3 or p2 == 3) {
			ans = i;
			cnt += 1;
		}
	}
	if (cnt == 1) {
		cout << S[ans][0] << endl;
	} else {
		cout << "C" << endl;
	}

    return 0;
}
