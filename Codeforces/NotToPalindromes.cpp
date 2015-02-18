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

int N, P;
string S;

void add(string& s, int pos) {
	int tr = 1;
	for (int i = pos; i >= 0; i--) {
		int d = (s[i] - 'a') + tr;

		if (d < P) {
			s[i] = 'a' + d;
			break;
		} else {
			s[i] = 'a' + (d % P);
			tr = 1;
		}
	}
}


bool check(string& s) {	
	for (int i = N - 1; i >= 0; i--) {
		cout << s << "\n";
		if (i == N - 1) {
			while (i - 1 >= 0 && s[i] == s[i - 1]) {
				add(s, i);
			}
		} else if (i == 0) {
			while (i + 1 < N && s[i] == s[i + 1]) {
				add(s, i + 1);			
			}
			i += 1;
		} else {
			bool f = false;
			while (i + i < N && s[i] == s[i + 1]) {
				add(s, i + 1);	
				f = true;
			}

			while (s[i + 1] == s[i - 1]) {
				add(s, i + 1);		
				f = true;
			}
			if (f) i += 1;
		}
	}

	return true;

}


int main(void) {
	cin >> N >> P >> S;
	
	bool done = false;

	string def = S;

	add(S, N - 1);
	check(S);

	if (S < def) {
		cout << "NO\n";
	} else {
		cout << S << "\n";
	}
    return 0;
}
