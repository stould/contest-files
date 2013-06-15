#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int m, nrs = 0, prs = 0;
string n, p;

set<char> nset, pset;

bool nwon(char c, char b) {
    if(c == 'R' && b == 'S') return true;
    if(c == 'S' && b == 'P') return true;
    if(c == 'P' && b == 'R') return true;
    return false;
}

int main(void) {
    cin >> m >> n >> p;

    for(int i = 0; i < m; i++) {
        char nc = n[i % n.size()];
        char pc = p[i % p.size()];

        if(nc == pc) continue;

        if(nwon(nc, pc)) {
            prs += 1;
        } else {
            nrs += 1;
        }
    }
    cout << nrs << " " << prs << endl;
}
