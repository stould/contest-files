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

const int MAXN = 500;

string A, B;

int lcs(void) {
    int N = (int) A.size();
    int M = (int) B.size();

    int i, j;
    int ans = 0;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            int l = i;
            int k = j;

            for ( ; l < N && k < M && A[l] == B[k]; ) {
                l += 1;
                k += 1;
            }

            ans = max(ans, k - j);
            j = k;
        }
    }

    return ans;
}

int main(void) {
    for ( ; getline(cin, A) && getline(cin, B); ) {
        cout << lcs() << "\n";
    }

    return 0;
}
