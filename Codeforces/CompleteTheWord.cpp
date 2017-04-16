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

string S;
int N;

bool fine(string arg) {
    map<char, int> cnt;
    
    for (auto& a: arg) {
        if (a != '?') {
            cnt[a] += 1;
            if (cnt[a] > 1) {
                return false;
            }
        }
    }

    return true;;
}

void fix(int ia, int ib) {
    map<char, int> cnt;
    
    for (int i = ia; i <= ib; i++) {
        if (S[i] != '?') {
            cnt[S[i]] += 1;            
        }
    }
    vector<int> other;
    
    for (char c = 'A'; c <= 'Z'; c++) {
        if (cnt[c] == 0) {
            other.push_back(c);
        }
    }
    for (int i = ia; i <= ib; i++) {
        if (S[i] == '?') {
            if (!other.empty()) {
                S[i] = other.back();
                other.pop_back();
            }
        }              
    }
}

int main(void) {
    cin >> S;

    N = (int) S.size();
    
    for (int i = 0; i + 26 <= N; i++) {
        if (fine(S.substr(i, 26))) {
            fix(i, i + 25);
            for (int j = 0; j < i; j++) {
                if (S[j] == '?') S[j] = 'A';
            }
            for (int j = i + 26; j < N; j++) {
                if (S[j] == '?') S[j] = 'A';
            }
            cout << S << "\n";
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}
