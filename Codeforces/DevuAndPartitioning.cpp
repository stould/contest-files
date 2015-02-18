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

const int MAXN = 100005;

int N, K, P;
int eL, oL;
int E[MAXN], O[MAXN];
char buff[MAXN];

int main(void) {
	cin >> N >> K >> P;

	eL = oL = 0;

	for (int i = 0; i < N; i++) {
		int T;
		cin >> T;

		if (T % 2 == 0) {
			E[eL++] = T;
		} else {
			O[oL++] = T;
		}
	}

	int od = K - P;

	if (oL < od || (max(0, (oL - od)) % 2 == 1)) {
		cout << "NO\n";
	} else {
		bool ok = true;
		
		vector<string> vs;
		vs.push_back("YES\n");
		
		//All odds - 1
		for (int i = 0; i < od - 1; i++) {
			sprintf(buff, "%d %d\n", 1, O[--oL]);
			vs.push_back(string(buff));
		}
		//All even - 1
		for (int i = 0; i < P - 1; i++) {
			sprintf(buff, "%d %d\n", 1, E[--eL]);
			vs.push_back(string(buff));
		}
		if (oL > 0) {
			if (oL % 2 == 1) {
				sprintf(buff, "%d ", oL);
				vs.push_back(string(buff));
				
				for (int i = 0; i < oL; i++) {
					sprintf(buff, "%d ", O[i]);
					vs.push_back(string(buff));
				}
				sprintf(buff, "\n");
				vs.push_back(string(buff));
			} else {
				ok = false;
			}
		}

		if (eL > 0) {
			sprintf(buff, "%d ", eL);
			vs.push_back(string(buff));

			for (int i = 0; i < eL; i++) {
				sprintf(buff, "%d ", E[i]);
				vs.push_back(string(buff));
			}
			sprintf(buff, "\n");
			vs.push_back(string(buff));
		}
		if (ok) {
			for (int i = 0; i < (int) vs.size(); i++) {
				cout << vs[i];
			}
		} else {
			cout << "NO\n";
		}
	}

    return 0;
}
