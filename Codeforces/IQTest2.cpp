#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string S[5];

pair<int, int> func(int pi, int pj) {
    pair<int, int> ans = make_pair(0, 0);
    
    if (S[pi][pj] == '.') {
        ans.first += 1;
    } else {
        ans.second += 1;
    }
    
    if (S[pi+1][pj] == '.') {
        ans.first += 1;
    } else {
        ans.second += 1;
    }
    
    if (S[pi][pj+1] == '.') {
        ans.first += 1;
    } else {
        ans.second += 1;
    }

    if (S[pi+1][pj+1] == '.') {
        ans.first += 1;
    } else {
        ans.second += 1;
    }


    return ans;    
}

int main(void) {
    for (int i = 0; i < 4; i++) {
        cin >> S[i];
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            pair<int, int> pt = func(i, j);
            
            if (pt.first != 2) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}
