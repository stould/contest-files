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

const int MAX_L = 20;

int N, M;
string A[30], B[30];
set<string> sA, sB;
bool seen;

void dfsA(string arg) {
	if (arg.size() > MAX_L or sA.count(arg)) return;
	
	if (!arg.empty()) {
		sA.insert(arg);
	}
	for (int i = 0; i < N; i++) {
		dfsA(A[i] + arg);
		dfsA(arg + A[i]);
	}	
}

void dfsB(string arg) {
	if (seen) return;

	if (sA.count(arg)) {
		seen = true;
		return;
	}
	
	if (arg.size() > MAX_L or sB.count(arg)) return;
	
	if (!arg.empty()) {
		sB.insert(arg);
	}
	
	for (int i = 0; i < M; i++) {
		dfsB(B[i] + arg);
		dfsB(arg + B[i]);				
	}
}

int main(void) {
	while (cin >> N >> M) {
		sA.clear();
		sB.clear();
		
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		for (int i = 0; i < M; i++) {
			cin >> B[i];
		}
		
		dfsA("");

		seen = false;

		dfsB("");

		if (seen) {
			cout << "S" << endl;
		} else {
			cout << "N" << endl;
		}
	}
	return 0;
}
