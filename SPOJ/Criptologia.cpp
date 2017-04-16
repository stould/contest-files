#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <functional>
#include <limits>
#include <list>
#include <iostream>
#include <map>
#include <memory>
#include <new>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <valarray>
#include <vector>
#include <utility>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define REP(i, n) for((i) = 0; (i) < (n); i++)
#define FOR(i, a, n) for((i) = (a); (i) < (n); i++)

using namespace std;

const int INF = 1000000000;
const double PI = acos(-1);

typedef long long ll;

int i, t, f, ind, test = 1, used[100010];
char freq[30];
string text;

void sub(string& s, char from, char to) {
    int i;
    REP(i, s.size()) {
        if(s[i] == from && !used[i]) {
            s[i] = to;
            used[i] = 1;
        }
    }
}

struct letter  {
    char c;
    int r;
    letter(){}
    letter(char c, int r): c(c), r(r){}
    bool operator<(const letter& l) const {
        if(r != l.r) return r > l.r;
        return c < l.c;
    }
};

int main(void) {
    while(cin >> t >> f && !(t == 0 && f == 0)) {
        cin >> freq;
        cin.ignore();
        getline(cin, text);
        map<char, int> mp;
        map<char, int>::iterator it;
        REP(i, t) if(text[i] != ' ') {
            mp[text[i]] += 1;
        }
        vector<letter> vl;
        for(it = mp.begin(); it != mp.end(); it++) {
            vl.push_back(letter(it->first, it->second));
        }
        sort(vl.begin(), vl.end());
        ind = 0;
        memset(used, 0, sizeof(used));
        REP(i, vl.size()) {
            sub(text, vl[i].c, freq[ind]); ind += 1;
        }
        cout << "Teste " << test++ << "\n" << text << "\n\n";
    }
    return 0;
}

