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

int L, N;
map<string, string> map_str;
string A, B;

bool isVowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main(void) {
	for ( ; cin >> L >> N; ) {
		for (int i = 0; i < L; i++) {
			cin >> A >> B;
			map_str[A] = B;
		}
		for (int i = 0; i < N; i++) {
			cin >> A;
			
			if (map_str[A] != "") {
				cout << map_str[A] << "\n";
			} else {
				if (A.size() >= 2 && A[A.size() - 1] == 'y' && !isVowel(A[A.size() - 2])) {
					cout << A.substr(0, A.size() - 1) + "ies\n";
				} else if (A[A.size() - 1] == 'o' || A[A.size() - 1] == 's' || A[A.size() - 1] == 'x' ||
						   (A.size() >= 2 && A[A.size() - 1] == 'h' && A[A.size() - 2] == 'c') ||
						   (A.size() >= 2 && A[A.size() - 1] == 'h' && A[A.size() - 2] == 's')) {
					cout << A + "es\n";
				} else {
					cout << A + "s\n";
				}
			}
		}
	}
    return 0;
}
