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

const int MAXN = 30;

int T, N;
string S;

struct Trie {
    map<char, Trie> child;
    int prefixes;
    int words;
	bool seen;

    Trie() {
        prefixes = words = 0;
		seen = false;
    }

    void addWord(string s, int pos = 0) {
        if(pos == s.size()) {
            words++;
            return;
        }

        int letter_pos = s[pos] - 'a';
		
        Trie& t = child[letter_pos];

        if (t.seen == false) {
            t.prefixes = 1;
        } else {
            t.prefixes = t.prefixes + 1;
        }

		t.seen = true;
		
        t.addWord(s, pos + 1);
    }

    int count(string s, int pos = 0) {
        if(pos == s.size()) return 1;
        Trie& t = child[s[pos] - 'a'];
        return t.count(s, pos + 1) + (prefixes > 1);
    }
};

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;

		Trie trie;
		Int ans = 0;

		for (int i = 0; i < N; i++) {
			cin >> S;

			trie.addWord(S);

			ans += trie.count(S);
		}

		cout << "Case #" << t << ": " << ans << "\n"; 
	}
	
    return 0;
}
