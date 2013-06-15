#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

string nw, ch, pile;

void solve() {
    if(nw.size() + ch.size() != pile.size()) {
        cout << "NO" << endl;
        return;
    } else {
        for(int i = 0; i < nw.size(); i++) {
            for(int j = 0; j < pile.size(); j++) {
                if(pile[j] == nw[i] && pile[j] != '#') {
                    pile[j] = '#';
                    break;
                }
            }
        }
        for(int i = 0; i < ch.size(); i++) {
            for(int j = 0; j < pile.size(); j++) {
                if(pile[j] == ch[i] && pile[j] != '#') {
                    pile[j] = '#';
                    break;
                }
            }
        }

        int c = 0;
        for(int i = 0; i < pile.size(); i++) { if(pile[i] != '#') { c++; } }
        if(c != 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}

int main() {
    cin >> nw >> ch >> pile;

    solve();

    return 0;
}
