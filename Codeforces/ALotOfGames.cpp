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

const int MAXN = 200005;

int N, K;
string S[MAXN];
int sig[MAXN][26];
int term[MAXN];
int cnt;

void add(string& arg) {
    int x = 0, n = (int) arg.size();

    for (int i = 0; i < n; i++){
        int c = (int) arg[i] - 'a';
        
        if (sig[x][c] == 0) {
            term[cnt] = 0;
            sig[x][c] = cnt++;
        }
        x = sig[x][c];
    }
    
    term[x] = 1;
}

bool canWin(int node) {
    for (int i = 0; i < 26; i++) {
        if (sig[node][i] != 0) {
            if (!canWin(sig[node][i])) {
                return true;
            }
        }
    }
    return false;    
}
bool canLose(int node) {
    bool ans = true;
    
    for (int i = 0; i < 26; i++) {
        if (sig[node][i] != 0) {
            if (!canLose(sig[node][i])) {
                return true;
            }
            ans = false;
        }
    }
    return ans;    
}

int main(void) {
    cin >> N >> K;

    cnt = 1;
    
    for (int i = 0; i < N; i++) {
        cin >> S[i];
        add(S[i]);
    }

    //cout << canWin[0] << " " << canLose[0] << endl;

    int cw = canWin(0);
    int cl = canLose(0);
    
    if (cw && cl) { //1-1
        cout << "First\n";
    } else if (cw) { //1-0
        if (K % 2 == 1) {
            cout << "First\n";
        } else {
            cout << "Second\n";
        }
    } else {
        cout << "Second\n";
    }
    
    return 0;
}
