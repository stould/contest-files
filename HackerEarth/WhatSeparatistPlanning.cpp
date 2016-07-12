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

const int MAXN = 90050;

int L, D, N;
string S[MAXN], P;
int id = 1;
int trie[MAXN][26];
int term[MAXN];

void add(string& arg) {
    int x = 0;

    for (int i = 0; i < (int) arg.size(); i++) {
        int pos = arg[i] - 'a';

        if (trie[x][pos] == 0) {
            trie[x][pos] = id++;
        }

        x = trie[x][pos];
    }

    term[x] = 1;
}

int func(int pos, int trie_pos) {
    if (pos >= (int) P.size()) {
        return term[trie_pos];
    } else {
        int ans = 0;

        if (P[pos] == '(') {
            vector<char> can;
            int fim = pos + 1;
            
            for (int i = pos + 1; i < P.size(); i++) {
                if (P[i] == ')') {
                    fim = i + 1;
                    break;
                }
                can.push_back(P[i]);
            }
            
            for (int i = 0; i < (int) can.size(); i++) {
                int now = can[i] - 'a';
                if (trie[trie_pos][now] != 0) {
                    ans += func(fim, trie[trie_pos][now]);
                }
            }
        } else {
            if (trie[trie_pos][P[pos] - 'a'] != 0) {
                ans += func(pos + 1, trie[trie_pos][P[pos] - 'a']);
            }
        }

        return ans;
    }
}

int main(void) {
    cin >> L >> D >> N;
    
    memset(trie, 0, sizeof(trie));

    for (int i = 0; i < D; i++) {
        cin >> S[i];
        add(S[i]);
    }

    for (int i = 0; i < N; i++) {
        cin >> P;
        cout << func(0, 0) << endl;
    }
    return 0;
}
