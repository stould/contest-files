#include <iostream>
#include <set>
#include <map>
#include <stdio.h>

using namespace std;

int n, v;

set<int> vert[9];
set<int> horz[9];
set<int> spot[9];

int main(void) {
    cin >> n;
    for(int x = 1; x <= n; x++) {
        for(int i = 0; i < 9; i++) {
            vert[i].clear();
            horz[i].clear();
            spot[i].clear();
        }
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cin >> v;
                horz[i].insert(v);
                vert[j].insert(v);
                if(i <= 2 && j <= 2) {
                    spot[0].insert(v);
                }
                if(i >= 3 && i <= 5 && j <= 2) {
                    spot[1].insert(v);
                }
                if(i >= 6 && i <= 8 && j <= 2) {
                    spot[2].insert(v);
                }
                if(i <= 2 && j >= 3 && j <= 5) {
                    spot[3].insert(v);
                }
                if(i >= 3 && i <= 5 && j >= 3 && j <= 5) {
                    spot[4].insert(v);
                }
                if(i >= 6 && i <= 8 && j >= 6 && j <= 8) {
                    spot[5].insert(v);
                }
                if(i <= 2 && j >= 6) {
                    spot[6].insert(v);
                }
                if(i >= 3 && i <= 5 && j >= 6) {
                    spot[7].insert(v);
                }
                if(i >= 6 && j >= 6) {
                    spot[8].insert(v);
                }
            }
        }
        bool ok = true;
        for(int i = 0; i < 9; i++) {
            if(spot[i].size() != 9 || horz[i].size() != 9 || vert[i].size() != 9) {
                ok = false;
            }
        }
        cout << "Instancia " << x << endl;
        if(ok) {
            cout << "SIM" << endl;
        } else {
            cout << "NAO" << endl;
        }
        cout << endl;
    }
    return 0;
}
