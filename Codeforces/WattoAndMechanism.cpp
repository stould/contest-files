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

int N, M;
//found, last
struct Trie {
	map<int, Trie> next;
	bool init;
	bool last;

	Trie() {
		init = false;
		last = false;
	}	
};

void insert(Trie& trie, string& s, int pos, int L) {
	if (pos == L) {
		return;
	} else {
		if (pos == L - 1) {
			trie.last = true;
		}		
		if (!trie.next[s[pos]-'a'].init) {
			trie.next[s[pos]-'a'].init = true;
		}
		insert(trie.next[s[pos]-'a'], s, pos + 1, L);
	}
}	


bool found(Trie& trie, string& s, int pos, int err, int L, bool last) {
	//cout << pos << " " << err << " " << last << "\n";
	if (err > 1) {
		return false;
	} else if (pos == L) {
		return err == 1 && last;
	} else {
		bool ans = false;
		
		for (int i = 0; i < 3; i++) {
			if (trie.next[i].init) {
				if (s[pos]-'a' == i) {
					ans |= found(trie.next[i], s, pos + 1, err, L, trie.last);
				} else {
					ans |= found(trie.next[i], s, pos + 1, err + 1, L, trie.last);
				}
			}
		}
		
		return ans;
	}
}

int main(void) {
	cin >> N >> M;

	string S;
	Trie root;
	
	for (int i = 0; i < N; i++) {
		cin >> S;
		insert(root, S, 0, S.size());
	}

	for (int i = 0; i < M; i++) {
		cin >> S;

		if (found(root, S, 0, 0, S.size(), false)) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	
    return 0;
}
