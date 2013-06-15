#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>

using namespace std;

int sa, sb, d;

vector<string> &split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while(getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


vector<string> split(const string &s, char delim) {
    vector<string> elems;
    return split(s, delim, elems);
}

int toint(string s) {
    istringstream ss(s);
    int ans;
    ss >> ans;
    return ans;
}

int main(void) {
    string s;
    int rec = 0, loz = 0;
    while(getline(cin, s)) {
        vector<string> v = split(s, ',');
        sa = toint(v[0]);
        sb = toint(v[1]);
        d = toint(v[2]);

        if(sa == sb) loz++;
        if(sa * sa + sb * sb == d * d) rec++;
    }
    cout << rec << endl << loz << endl;
    return 0;
}
