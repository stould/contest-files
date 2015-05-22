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


int N;
string M[100];
string L[100];

int main(void) {
	M[0] = "zero";
	M[1] = "one";
	M[2] = "two";	
	M[3] = "three";
	M[4] = "four";
	M[5] = "five";
	M[6] = "six";	
	M[7] = "seven";
	M[8] = "eight";
	M[9] = "nine";
	M[10] = "ten";	
	M[11] = "eleven";
	M[12] = "twelve";	
	M[13] = "thirteen";
	M[14] = "fourteen";
	M[15] = "fifteen";
	M[16] = "sixteen";	
	M[17] = "seventeen";
	M[18] = "eighteen";
	M[19] = "nineteen";

	L[2] = "twenty";
	L[3] = "thirty";
	L[4] = "forty";
	L[5] = "fifty";
	L[6] = "sixty";
	L[7] = "seventy";
	L[8] = "eighty";
	L[9] = "ninety";


	while (cin >> N) {
		if (N < 20) {
			cout << M[N] << endl;
		} else {
			int d1 = N % 10;
			int d2 = (N / 10) % 10;
			
			cout << L[d2];
			
			if (d1 != 0) {
				cout << "-" << M[d1] << endl;
			}
		}
	}
	return 0;
}
