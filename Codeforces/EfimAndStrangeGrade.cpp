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
typedef unsigned long long uInt;
typedef unsigned uint;

int N, T;
string S;
set<int> fine;
int last;

void inc(int pos) {
    if (pos < 0) {
        S = "1" + S;
        last += 1;
    } else {
        if (S[pos] == '9') {
            S[pos] = '0';

            fine.erase(pos);
            
            inc(pos - 1);
        } else {            
            S[pos] += 1;

            if (S[pos] >= '5') {
                fine.insert(pos);
            }
        }
    }
}

int main(void) {
    cin >> N >> T >> S;

    last = N;
    bool pass = false;
 
    for (int i = 0; i < N; i++) {
        if (S[i] == '.') {
            pass = true;
            continue;
        }
        if (pass && S[i] >= '5') {
            fine.insert(i);
        }
    }

    while (T > 0 && !fine.empty()) {
        int now = *fine.begin();

        fine.erase(fine.begin());
        
        if (S[now - 1] == '.') {
            inc(now - 2);
            last = now - 1;
            break;
        } else {
            inc(now - 1);
            last = now;
            T -= 1;
        }
    }

    for (int i = 0; i < last; i++) {
        cout << S[i];
    }
    cout << "\n";
    return 0;
}
