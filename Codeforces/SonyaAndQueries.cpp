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

using namespace std;

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAX_TRIE = 2000005;

int T;
int trie[MAX_TRIE][2];
int sum[MAX_TRIE];
int cnt = 1;
string str;

void add(string arg) {
    int x = 0;

    for (int i = 0; i < (int) arg.size(); i++) {
        int now = (arg[i] - '0') % 2;

        if (trie[x][now] == 0) {
            trie[x][now] = cnt++;
        }
        x = trie[x][now];

        sum[x] += 1;
    }
}

void remove(string arg) {
    int x = 0;

    for (int i = 0; i < (int) arg.size(); i++) {
        int now = (arg[i] - '0') % 2;
        x = trie[x][now];
        sum[x] -= 1;
    }
}

Int query(int pos, int tr) {
    if (pos >= (int) str.size()) {
        return sum[tr];
    } else {
        Int ans = 0;
        
        int cr = str[pos] - '0';
        
        for (int i = 0; i <= 1; i++) {
            if (i == cr && trie[tr][i] != 0) {
                ans += query(pos + 1, trie[tr][i]);
            }
        }

        return ans;
    }
}

int main(void) {
    cin >> T;

    while (T--) {
        string kind, S;
        cin >> kind >> S;

        while (S.size() < 18) {
            S = "0" + S;
        }

        reverse(S.begin(), S.end());
        
        if (kind == "+") {
            add(S);
        } else if (kind == "-") {
            remove(S);
        } else {
            str = S;
            cout << query(0, 0) << "\n";
        }
    }
    return 0;
}
