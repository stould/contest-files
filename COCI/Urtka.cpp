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
string S;
map<string, int> map_name, seen;

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> S;		
		map_name[S] += 1;
	}

	for (int i = 1; i < N; i++) {
		cin >> S;
		seen[S] += 1;
	}
	
	for (const auto a: map_name) {
		if (a.second > seen[a.first]) {
			cout << a.first << "\n";
			break;
		}
	}
    return 0;
}
