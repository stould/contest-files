#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int N, M, Q, K;
int trie[MAXN][26];
int id = 1;
string S;

void add(string& arg) {
    int x = 0;

    for (int i = 0; i < (int) arg.size(); i++) {
        int now = arg[i] - 'a';

        if (trie[x][now] == 0) {
            trie[x][now] = id++;
        }
        x = trie[x][now];
    }
}

int query(string& arg, int pos, int trie_pos, int miss) {
    if (miss > K) return 0;
    if (pos == (int) arg.size()) return 1;

    int ans = 0;
    
    for (int i = 0; i < 26; i++) {
        if (ans) break;
        if (trie[trie_pos][i] == 0) continue;
        
        ans |= query(arg, pos + 1, trie[trie_pos][i], miss + (i == arg[pos] - 'a' ? 0 : 1));
    }

    return ans;
}

int main() {
    cin >> N >> M >> Q >> K;

    for (int i = 0; i < N; i++) {
        cin >> S;
        add(S);
    }

    for (int i = 0; i < Q; i++) {
        cin >> S;
        int ans = query(S, 0, 0, 0);
        if (ans == 1) {
            cout << "S\n";
        } else {
            cout << "N\n";
        }
    }
    return 0;
}
