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

const int MAXN = 4000005;
const int MAX_ALPHA = 2;

int Q;
int sig[MAXN][MAX_ALPHA];
int conta[MAXN];
int id = 1;

string toBin(int arg) {
    string ans = "";
    
    if (arg == 0) {
        ans = "0";
    } else {
        while (arg > 0) {
            ans = char('0' + (arg % 2)) + ans;
            arg /= 2;
        }
    }

    while (ans.size() < 31) {
        ans = "0" + ans; 
    }

    return ans;
}

void add(string arg) {
    int x = 0;

    for (int i = 0; i < (int) arg.size(); i++) {
        int now = arg[i] - '0';

        if (sig[x][now] == 0) {
            sig[x][now] = id++;
        }
        x = sig[x][now];        
        conta[x] += 1;
    }
}

void remove(string arg) {
    int x = 0;

    for (int i = 0; i < (int) arg.size(); i++) {
        int now = arg[i] - '0';
        x = sig[x][now];
        conta[x] -= 1;
    }
}

int query(int arg, int pos, int sig_pos, int ans) {
    if (pos >= 31) {
        return ans;
    } else {
        int fim = 0;

        int ba = 0;
        int bb = 0;
        
        if (sig[sig_pos][0] != 0) {
            if (conta[sig[sig_pos][0]] > 0) {
                int bit = (arg & (1 << (30 - pos))) >> (30 - pos);
                if (bit != 0) {
                    ba = 1;
                }
            }
        }
        
        if (sig[sig_pos][1] != 0) {
            if (conta[sig[sig_pos][1]] > 0) {
                int bit = (arg & (1 << (30 - pos))) >> (30 - pos);
                if (bit != 1) {
                    bb = 1;
                }
            }
        }
        if (ba || bb) {
            if (ba) {
                chmax(fim, query(arg, pos + 1, sig[sig_pos][0], ans | (1 << (30 - pos))));
            } else {
                chmax(fim, query(arg, pos + 1, sig[sig_pos][1], ans | (1 << (30 - pos))));
            }
        } else {
            if (sig[sig_pos][0] != 0) {
                chmax(fim, query(arg, pos + 1, sig[sig_pos][0], ans));
            } else {
                if (sig[sig_pos][1] != 0) {
                    chmax(fim, query(arg, pos + 1, sig[sig_pos][1], ans));
                }
            }
        }
            
        return fim;
    }
}

void gen() {
    cout << "200000\n";
    srand(time(NULL));
    
    for (int i = 1; i < 200000; i++) {
        cout << "+ " << (rand() % 1000000001) << endl;
    }
    cout << "? " << 1000000000 << endl;
}

int main(void) {
    //gen(); return 0;
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> Q;

    add(toBin(0));

    for (int i = 0; i < Q; i++) {
        string type;
        int value;

        cin >> type >> value;

        if (type == "+") {
            add(toBin(value));
        } else if (type == "-") {
            remove(toBin(value));
        } else {
            cout << query(value, 0, 0, 0) << "\n";
        }
    }
    return 0;
}
