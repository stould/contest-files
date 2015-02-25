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

string S, T;

void sum(string& arg) {
	int N = (int) arg.size();

	arg[N - 1] += 1;

	for (int i = N - 1; i >= 1; i--) {
		if (arg[i] > 'z') {
			arg[i] = 'a';
			arg[i - 1] += 1;
		} else {
			break;
		}
	}
}

int main(void) {
	cin >> S >> T;

	sum(S);

	if (S >= T) {
		cout << "No such string\n"; 
	} else {
		cout << S << "\n";		
	}
		
    return 0;
}
