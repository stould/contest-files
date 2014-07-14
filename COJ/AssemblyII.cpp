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


using namespace std;

typedef long long Int;
typedef unsigned uint;

const int MAXN = 60005;
const int INF = INT_MAX / 3;

int N;
int P[MAXN], Q[MAXN], stk[MAXN], in[MAXN];

int CeilIndex(int A[], int l, int r, int key) {
    int m;
 
    while( r - l > 1 ) {
        m = l + (r - l)/2;
        (A[m] >= key ? r : l) = m; 

    }
 
    return r;
}
int ep(int A[], int size) {
    int *tailTable   = new int[size];
    int len;
 
    memset(tailTable, 0, sizeof(tailTable[0])*size);
 
    tailTable[0] = A[0];
    len = 1;
    for( int i = 1; i < size; i++ ) {
        if (A[i] < tailTable[0]) {
            tailTable[0] = A[i];
		} else if( A[i] > tailTable[len-1]) {
            tailTable[len++] = A[i];
		} else {
            tailTable[CeilIndex(tailTable, -1, len-1, A[i])] = A[i];
		}
    }
 
    delete[] tailTable;
 
    return len;
}

int main(void) {
	for ( ; scanf("%d", &N) == 1; ) {
		for (int i = 0; i < N; i++) {
			scanf("%d", &P[i]);
			Q[i] = P[i];
		}
		reverse(Q, Q + N);
		int a = ep(P, N), b = ep(Q, N);

		if (a == b) {
			puts("Caution. I will not intervene.");
		} else {
			puts("Don't worry. I must intervene.");
		}
	}
    return 0;
}
