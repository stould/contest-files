#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

int bin[9];

long long fb, fg, fc, sb, sg, sc, tb, tg, tc, move;

struct Bin {
    string name;
    long long value;

    Bin() { }

    Bin(string _name, int _value) {
        name = _name;
        value = _value;
    }

    bool operator<(const Bin& b) const {
        if(value == b.value) {
            return name < b.name;
        } else {
            return value < b.value;
        }
    }
    bool operator==(const Bin& b) const {
        return name == b.name && value == b.value;
    }
};

vector<Bin> vec;

int main(void) {
    while(cin >> bin[0] >> bin[1] >> bin[2] >> bin[3] >> bin[4] >> bin[5] >> bin[6] >> bin[7] >> bin[8]) {
        vec.clear();

        fb = bin[3] + bin[6];
        sb = bin[0] + bin[6];
        tb = bin[0] + bin[3];

        fc = bin[5] + bin[8];
        sc = bin[2] + bin[8];
        tc = bin[2] + bin[5];

        fg = bin[4] + bin[7];
        sg = bin[1] + bin[7];
        tg = bin[1] + bin[4];

        vec.push_back(Bin("BCG", fb + sc + tg));
        vec.push_back(Bin("BGC", fb + sg + tc));
        vec.push_back(Bin("CGB", fc + sg + tb));
        vec.push_back(Bin("CBG", fc + sb + tg));
        vec.push_back(Bin("GBC", fg + sb + tc));
        vec.push_back(Bin("GCB", fg + sc + tb));

        sort(vec.begin(), vec.end());

        cout << vec[0].name << " " << vec[0].value << endl;
    }
    return 0;
}
