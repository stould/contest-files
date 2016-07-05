#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int N;
string S, P;
int id = 1;
int trie[MAXN][30];
int cnt[MAXN];

void add(string& arg) {
    int rt = 0;

    for (int i = 0; i < (int) arg.size(); i++) {
        if (trie[rt][arg[i] - 'a'] == 0) {
            trie[rt][arg[i] - 'a'] = id++;            
        }
        rt = trie[rt][arg[i] - 'a'];
    }
    cnt[rt] += 1;
}

int df(string a, string b) {
    int pos = 0;
    int ans = 0;
    
    for (int i = 0; i < (int) a.size(); i++) {
        if (pos >= (int) b.size()) break;    
        if (a[i] == b[pos]) {
            pos += 1;
            ans += 1;
        }
    }
    
    return abs((int) a.size() - ans) <= 3;
}

int main() {
    cin >> N >> S;
    
    int ans = 0;
      
    for (int i = 0; i < N; i++) {
        cin >> P;
        
        add(P + "$");
    }
    
    cout << ans << "\n";
}
