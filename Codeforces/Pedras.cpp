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

string S;

int main(void) {
    while (cin >> S) {
        string buff;
        for (int i = 0; i < (int) S.size(); i++) {
            buff += S[i];

            int len = (int) buff.size();

            if (i > 0) {
                if (tolower(buff[len - 1]) == tolower(buff[len - 2]) && buff[len - 1] != buff[len - 2]) {
                    buff.pop_back();
                    buff.pop_back();
                }
            }
        }

        if (buff.empty()) {
            cout << "Vazia\n";
        } else {
            cout << buff << "\n";
        }
    }
    return 0;
}
