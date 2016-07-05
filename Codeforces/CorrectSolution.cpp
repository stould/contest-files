#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

using namespace std;

string nn, mm;
int n, m, sn = 0, sm = 0;

int main(void) {
    cin >> mm >> nn;

    n = atoi(nn.c_str());
    m = atoi(mm.c_str());

    vector<int> help;

    int zeros = 0;

    while(m > 0) {
        help.push_back(m % 10);
        if(m % 10 == 0) zeros++;
        m /= 10;
        sm += 1;
    }
    string is = "";

    sort(help.begin(), help.end());
    bool ok = true;
    for(int i = 0; i < help.size(); i++) {
        if(help[i] != 0) {
            is += '0' + help[i];
            if(ok) {
                ok = false;
                for(int j = 0; j < zeros; j++) {
                    is += '0';
                }
            }
        }
    }
    int cmp = atoi(is.c_str());

    if(cmp == n && mm.size() == nn.size()) {
        cout << "OK" << endl;
    } else {
        cout << "WRONG_ANSWER" << endl;
    }
    return 0;
}
