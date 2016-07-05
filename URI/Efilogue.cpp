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
 
string S;
string sub = "psjxvb";
 
int main(void) {
    while (getline(cin, S)) {
        for (int i = 0; i < (int) S.size(); i++) {
            if (sub.find(S[i]) != string::npos) {
                if (S[i] >= 'A' && S[i] <= 'Z') {
                    S[i] = 'F';
                } else {
                    S[i] = 'f';
                }                   
            }
        }
        char last = '$';
        for (int i = 0; i < (int) S.size(); i++) {
            if (!((S[i] == 'F' or S[i] == 'f') && (last == 'F' or last == 'f'))) {
                cout << S[i];
            }
            last = S[i];
        }
        cout << endl;
    }
    return 0;
}
