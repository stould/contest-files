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

string A, B;
int N1, N2;
int dp[30][30];

int func(int i, int j) {
	if (i > N1 || j > N2) {
		return 1000000;
	} else if (i == N1 && j == N2) {
		return 0;
	} else {
		int& ans = dp[i][j];

		if (ans == -1) {
			ans = 100000;

			if (A[i] == B[j]) {
				ans = func(i + 1, j + 1);
			} else {
				ans = 1 + min(func(i + 1, j), min(func(i, j + 1), func(i + 1, j + 1)));
			}
		}
		
		return ans;
	}
}

void rec(int i, int j) {
	if (i >= N1 && j >= N2) {
		return;
	} else {
		if (A[i] == B[j]) {
			//cout << "C" << B[j] << i + 1 << endl;
			rec(i + 1, j + 1);			   
		} else {
			int a = func(i + 1, j);
			int b = func(i, j + 1);
			int c = func(i + 1, j + 1);
			

			if (c <= min(a, b)) {
				cout << "C" << B[j] << setfill('0') << setw(2) << j + 1;
				rec(i + 1, j + 1);
			} else if (a <= min(b, c)) {
				cout << "D" << A[i] << setfill('0') << setw(2) << j + 1;
				rec(i + 1, j);
			} else if (b <= min(a, c)) {
				cout << "I" << B[j] << setfill('0') << setw(2) << j + 1;
				rec(i, j + 1);
			} 
		}
	}
}

int main(void) {
	while (cin >> A >> B) {
		if (A == "#") break;

		N1 = A.size();
		N2 = B.size();
		
		memset(dp, -1, sizeof(dp));

		rec(0, 0);
		cout << "E\n";
	}
	return 0;
}
