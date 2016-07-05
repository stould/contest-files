//Trie
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
