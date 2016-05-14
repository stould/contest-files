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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

int N;

int main(void) {
	cin >> N;
		
	int L = 1;

	for  (int i = 0; i < N; i++) {
		L *= 2;
	}

	vector<int> vf;
	vf.push_back(0);

	for (int i = 0; i < (1 << L); i++) {
		cout << i << endl;
	}
	cout << vf.size() << "\n";
	for (int i = 0; i < (int) vf.size(); i++) {
		for (int j = 0; j < L; j++) {
			if (vf[i] & (1 << j)) {
				cout << "+";
			} else {
				cout << "*";
			}
		}
		cout << "\n";
	}
	
	return 0;
}
