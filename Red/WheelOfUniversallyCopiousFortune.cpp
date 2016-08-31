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

const int MAXN = 10005;

int N, M;
string S;
vector<string> match;
int sig[MAXN][30];
int term[MAXN];
int cnt = 1;
map<string, int> mpos;


bool comp(string a, string b) {
    return mpos[a] < mpos[b];
}

void add(string& arg) {
    int x = 0, n = (int) arg.size();

    for (int i = 0; i < n; i++){
        int c = (int) arg[i] - 'a';

        if (c < 0) c = 27;
        
        if (sig[x][c] == 0) {
            term[cnt] = 0;
            sig[x][c] = cnt++;
        }
        x = sig[x][c];
    }
    term[x] = 1;
}

void query(string& arg, int pos, int trie_pos, string buff) {    
    if (pos == (int) arg.size()) {
        if (term[trie_pos]) {
            match.push_back(buff);
        }
    } else {
        if (arg[pos] == '-') {
            for (int i = 0; i < 26; i++) {                
                if (sig[trie_pos][i] != 0) {
                    query(arg, pos + 1, sig[trie_pos][i], buff + char('a' + i));
                }
            }
        } else {
            if (sig[trie_pos][(int) arg[pos] - 'a'] != 0) {
                query(arg, pos + 1, sig[trie_pos][arg[pos] - 'a'], buff + arg[pos]);
            }
        }
    }
}

int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> S;
        mpos[S] = i;
        add(S);
    }

    cin >> M;

    for (int i = 0; i < M; i++) {
        cin >> S;

        match.clear();

        query(S, 0, 0, "");

        sort(match.begin(), match.end(), comp);

        cout << "Word #" << i + 1 << ": " << S << "\n";

        for (int j = 0; j < (int) match.size(); j++) {
            cout << match[j] << "\n";
        }

        cout << "Total number of candidate words = " << (int) match.size() << "\n";
    }
    
    return 0;
}
