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

int main(void) {
    cin >> S;

    set<string> ss;

    for (int i = 0; i <= (int) S.size(); i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            string b = "";
            for (int k = 0; k < (int) S.size(); k++) {
                if (k == i) b += c;
                b += S[k];
            }
            if (i == (int) S.size()) b += c;
            ss.insert(b);
        }
    }
    
    cout << ss.size() << "\n";
    return 0;
}
