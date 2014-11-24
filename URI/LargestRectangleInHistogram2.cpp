#include <stack>
#include <cstdio>
 
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
 
const int MAXN = 100005;
 
int N;
int P[MAXN], L[MAXN], R[MAXN];
 
void build(void) {
    stack<int> sL, sR;
 
    for (int i = 0; i < N; i++) {
        if (sL.empty()) {
            L[i] = i;
        } else {
            while (!sL.empty() && P[sL.top()] >= P[i]) {
                R[i] = sL.top();
                sL.pop();
            }
            if (sL.empty()) {
                L[i] = 0;
            } else {
                L[i] = sL.top() + 1;
            }
        }
        sL.push(i);
    }
    for (int i = N - 1; i >= 0; i--) {
        if (sR.empty()) {
            R[i] = i;
        } else {
            while (!sR.empty() && P[sR.top()] >= P[i]) {
                R[i] = sR.top();
                sR.pop();
            }
            if (sR.empty()) {
                R[i] = N - 1;
            } else {
                R[i] = sR.top() - 1;
            }
        }
        sR.push(i);    
    }
}
 
int main(void) {
    for ( ; scanf("%d", &N) == 1 && N != 0; ) {
        stack<int> s;
 
        Int ans = 0LL;
 
        for (int i = 0; i < N; i++) {
            scanf("%d", &P[i]);
        }
         
        build();
 
        for (int i = 0; i < N; i++) {
            chmax(ans, (R[i] - L[i] + 1) * (Int) P[i]);
        }
 
        printf("%lld\n", ans);
    }
    return 0;
}
