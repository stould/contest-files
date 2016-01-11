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

const int MAXN = 1000002;

string A, B;
char buffer[MAXN];

int main(void) {
	scanf("%s", buffer);
	A = string(buffer);

	scanf("%s", buffer);
	B = string(buffer);

	while (A.size() < B.size()) {
		A = "0" + A;
	}
	while (B.size() < A.size()) {
		B = "0" + B;
	}

	bool end = false;
	
	for (int i = 0; i < (int) A.size(); i++) {
		if (A[i] != B[i]) {
			end = true;

			if (A[i] < B[i]) {
				cout << "<\n";
			} else {
				cout << ">\n";
			}
			break;
		}
	}

	if (!end) cout << "=\n";

	return 0;
}
