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

int N;
string S;

int main(void) {    
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> S;

        if (S.size() == 3) {
            if (S[0] == 'O' && S[1] == 'B') {
                S = "OBI";
            } else if (S[0] == 'U' && S[1] == 'R') {
                S = "URI";
            }
        }
        
        cout << S;
        if (i != N - 1) {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}
