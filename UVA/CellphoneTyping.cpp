#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <numeric>
#include <iomanip>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

#define REP(i, n) for(int (i) = 0; i < n; i++)
#define FOR(i, a, n) for(int (i) = a; i < n; i++)
#define FORR(i, a, n) for(int (i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 30;
const int MAXS = 1000009;
int N, ans;
string str[MAXS];

struct Trie {
    Trie *child[MAXN];
    int prefixes;
    int words;

    Trie() {
        int i;
        prefixes = words = 0;
        for(i = 0; i < MAXN; i++) {
            child[i] = NULL;
        }
    }

    void addWord(string s, int pos = 0) {
        if(pos == s.size()) {
            words++;
            return;
        }

        int letter_pos = s[pos] - 'a';

        Trie *t = child[letter_pos];

        if(child[letter_pos] == NULL) {
            t = child[letter_pos] = new Trie();
            t->prefixes = 1;
        } else {
            t->prefixes = t->prefixes + 1;
        }
        t->addWord(s, pos + 1);
    }

    int count(string s, int pos = 0, int k = 0) {
        if(pos == s.size()) return k;
        Trie *t = child[s[pos] - 'a'];
        if(t == NULL) return 0;
        return t->count(s, pos + 1, (prefixes == t->prefixes) ? k: k + 1);
    }
};


int main(void) {
    while(cin >> N) {
        ans = 0;
        Trie trie;
        REP(i, N) {
            cin >> str[i];
            trie.addWord(str[i]);
        }
        REP(i, N) {
            int now = trie.count(str[i]);
            ans += now;
        }
        printf("%.2lf\n", (double) ans/N);
    }
    return 0;
}
