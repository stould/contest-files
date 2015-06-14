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

const int MAXN = 110;

int N, K, X;

vector<int> simul(vector<int> arg) {	
	while (1) {
		bool ok = false;
		for (int i = 0; i < (int) arg.size(); i++) {
			int j = i;

			while (j < (int) arg.size() && arg[i] == arg[j]) {
				j += 1;
			}

			if (j - i + 1 > 3) {
				vector<int> cpy;
				
				for (int k = 0; k < (int) arg.size(); k++) {
					if (k < i or k >= j) {
						cpy.push_back(arg[k]);
					}
				}
				ok = true;
				arg = cpy;
				break;
			}
		}
		if (!ok) {
			break;
		}
	}
	
	return arg;
}

int main(void) {
	cin >> N >> K >> X;

	vector<int> P(N);
	
	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	int ans = 0;
	
	for (int i = 1; i < N; i++) {
		if (P[i] == P[i - 1]) {
			vector<int> cpy = P;
			
			cpy.insert(cpy.begin() + i, X);
		
			vector<int> after = simul(cpy);
			
			chmax(ans, abs((int) (P.size() - after.size())));
		}
	}

	cout << ans << endl;
	
	return 0;
}
