#include <bits/stdc++.h>

using namespace std;

int N;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

int len(int x) {
	int ans = 0;

	while (x > 0) {
		ans += 1;
		x /= 10;
	}
  
	return ans;
}

int main(void) {
	cin >> N;
  
	if (N < 3) {
		cout << "-1\n";
	} else if (N == 3) {
		cout << 210 << "\n";
	} else {  
		int G = 2 * 3 * 5 * 7;
		int mod = 1000 % G;

		for (int i = 0; i < N + 2; i++) {
			mod *= 10;
			mod %= G;            
		}
    
		int rlen = len(210 - mod);
		cout << 1;
    
		for (int i = 0; i < N - 1 - rlen; i++) {
			cout << "0";
		}
		cout << 210 - mod << "\n";
	}  
	return 0;
}
