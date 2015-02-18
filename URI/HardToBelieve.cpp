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

char A[10], B[10], C[10];

int main(void) {
	for ( ; scanf("%[^+]%*c%[^=]%*c%s", A, B, C); ) {
		//		printf("%s %s %s\n", A, B, C);
		int LA = strlen(A);
		int LB = strlen(B);
		int LC = strlen(C);
		
		reverse(A, A + LA);
		reverse(B, B + LB);
		reverse(C, C + LC);

		int as = atoi(A);
		int bs = atoi(B);
		int cs = atoi(C);
		
		if (as + bs == cs) {
			puts("True");
		} else {
			puts("False");
		}
		
		if (as == 0 && bs == 0 && cs == 0) {
			break;
		}
	}
	
    return 0;
}
