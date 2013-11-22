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

int T;
string S;

int main(void) {
    cin >> T;

    cin.ignore();

    int i;

    for ( ; T--; ) {
        getline(cin, S);

        int freq[26]; fill(freq, freq + 26, 0);
        int mem = 0;

        for (i = 0; i < (int) S.size(); i++) {
            S[i] = tolower(S[i]);
            if (S[i] >= 'a' && S[i] <= 'z') {
                freq[S[i] - 'a'] += 1;

                chmax(mem, freq[S[i] - 'a']);
            }
        }
        for (i = 0; i < 26; i++) {
            if (freq[i] == mem) {
                cout << char('a' + i);
            }
        }
        cout << "\n";
    }

    return 0;
}
