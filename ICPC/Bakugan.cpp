#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
    freopen("in.in", "r", stdin);
    freopen("ot.out", "w", stdout);
    int r, mpoints, lpoints, temp, ct = 1;
    stringstream ss;
    string buff;
    cin >> r;
    vector<int> mmonsters, lmonsters;
    while(r != 0) {
        mpoints = lpoints = 0;
        getline(cin, buff);
        getline(cin, buff);
        ss << buff;
        while(ss >> temp) { mmonsters.push_back(temp); }
        ss.clear();
        getline(cin, buff);
        ss << buff;
        while(ss >> temp) { lmonsters.push_back(temp); }
        bool hap = true;
        for(int i = 0; i < r; i++) {
            mpoints += mmonsters[i];
            lpoints += lmonsters[i];
            int c = 0;
            int lrepeat = 0, mrepeat = 0;
            if(hap) {
                c = 0;
                for(int j = i; c < 3 && j >= 0; j--, c++) {
                    if(mmonsters[i] == mmonsters[j]) {
                        mrepeat++;
                    }
                    if(lmonsters[i] == lmonsters[j]) {
                        lrepeat++;
                    }
                }
                if(c == 3) {
                    if(lrepeat == 3 && mrepeat == 3) {
                        hap = false;
                    } else {
                        hap = false;
                        if(mrepeat == 3) {
                            mpoints += 30;
                        } else if(lrepeat == 3) {
                            lpoints += 30;
                        } else {
                            hap = true;
                        }
                    }
                }
            }
        }
        if(mpoints > lpoints) {
            cout << "M" << endl;
        } else if(lpoints > mpoints) {
            cout << "L" << endl;
        } else {
            cout << "T" << endl;
        }
        mmonsters.clear();
        lmonsters.clear();
        ss.clear();
        buff.clear();
        cin >> r;
    }
    return 0;
}


