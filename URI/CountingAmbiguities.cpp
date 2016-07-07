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
typedef unsigned uint;

const int MAX_S = 30;
const Int MOD = 1000000007LL;

int N, M, L, IL;
string S;
vector<int> inter[110];
Int dp[110];

struct Trie {
    char type;
    int end;	
    map<char, Trie> child;
	
    Trie() {
        this->type = '$';
        this->end = 0;
    }

    void insert(string s, int pos) {
        if (pos >= s.size()) return;

        child[s[pos]].type = s[pos];

        if (pos == s.size() - 1) {
            child[s[pos]].end += 1;
        }
        child[s[pos]].insert(s, pos + 1);				
    }

    void seek(string s, int start, int pos) {
        if (end) {
            inter[start].push_back(start + pos - 1);
        } 

        if (pos >= s.size()) return;
		
        child[s[pos]].seek(s, start, pos + 1);					
    }	
};

Int func(int len) {
    if (len >= L - 1) {
        return 1LL;
    } else {
        Int& ans = dp[len];

        if (ans == -1LL) {
            ans = 0LL;

            for (int i = 0; i < (int) inter[len].size(); i++) {
                ans = ((ans % MOD) + (func(inter[len][i] + 1) % MOD)) % MOD;
            }
        }

        return ans % MOD;
    }
}

void run(void) {
    for ( ; cin >> N; ) {
        Trie root;

        for (int i = 0; i < N; i++) {
            cin >> S;
            root.insert(S, 0);
        }

        cin >> M;

        for ( ; M--; ) {
            cin >> S;

            L = (int) S.size();

            for (int i = 0; i < 110; i++) {
                inter[i].clear();
            }

            for (int i = 0; i < L; i++) {
                root.seek(S.substr(i, L - i), i, 0);
            }

            memset(dp, -1LL, sizeof(dp));

            cout << func(0) << "\n";
        }
    }	
}

int main(void) {
    run();

    return 0;
}
