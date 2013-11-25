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

bool ok(int id) {
    int i;

    string b = S.substr(0, id);

    for (i = id; i < (int) S.size(); i += id) {
        string cs = S.substr(i, id);
        if (cs != b) return false;
    }

    return true;
}

int main(void) {
    T = in();

    int i;
    int x;

    getline(cin, S);

    for (x = 1; x <= T; x++) {
        getline(cin, S);
        getline(cin, S);

        for (i = 1; i <= (int) S.size(); i++) {
            if (ok(i)) {
                printf("%d\n", i);
                break;
            }
        }
        if (x != T) puts("");
    }

    return 0;
}
