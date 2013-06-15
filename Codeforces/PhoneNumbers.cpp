#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int n, l;
string tmp;

//1 == Girl | 2 == Taxi | 3 == Pizza
int which(string s) {
    if(s[0] == s[1] && s[1] == s[3] && s[3] == s[4] && s[4] == s[6] && s[6] == s[7]) return 2;
    if(s[0] > s[1] && s[1] > s[3] && s[3] > s[4] && s[4] > s[6] && s[6] > s[7]) return 3;
    return 1;
}

struct Friend {
    string name;
    int taxi, pizza, girl;

    Friend() {
        taxi = 0;
        pizza = 0;
        girl = 0;
    }
};

int main(void) {
    cin >> n;
    vector<Friend> v(n);
    for(int i = 0; i < n; i++) {
        cin >> l >> v[i].name;
        for(int j = 0; j < l; j++) {
            cin >> tmp;
            int t = which(tmp);
            if(t == 1) {
                v[i].girl++;
            } else if(t == 2) {
                v[i].taxi++;
            } else {
                v[i].pizza++;
            }
        }
    }

    string ta, pi, gi;
    vector<string> nta, npi, ngi;
    int tta = -1, tpi = -1, tgi = -1;

    for(int i = 0; i < n; i++) {
        if(v[i].taxi > tta) tta = v[i].taxi;
        if(v[i].pizza > tpi) tpi = v[i].pizza;
        if(v[i].girl > tgi) tgi = v[i].girl;
    }

    for(int i = 0; i < n; i++) {
        if(v[i].taxi == tta) nta.push_back(v[i].name);
        if(v[i].pizza == tpi) npi.push_back(v[i].name);
        if(v[i].girl == tgi) ngi.push_back(v[i].name);
    }

    if(nta.size() == 1) {
        cout << "If you want to call a taxi, you should call: " << nta[0] << "." << endl;
    } else {
        cout << "If you want to call a taxi, you should call: ";
        for(int i = 0; i < nta.size(); i++) {
            if(i == nta.size() - 1) {
                cout << nta[i] << "." << endl;
            } else {
                cout << nta[i] << ", ";
            }
        }
    }
    if(npi.size() == 1) {
        cout << "If you want to order a pizza, you should call: " << npi[0] << "." << endl;
    } else {
        cout << "If you want to order a pizza, you should call: ";
        for(int i = 0; i < npi.size(); i++) {
            if(i == npi.size() - 1) {
                cout << npi[i] << "." << endl;
            } else {
                cout << npi[i] << ", ";
            }
        }
    }
    if(ngi.size() == 1) {
        cout << "If you want to go to a cafe with a wonderful girl, you should call: " << ngi[0] << "." << endl;
    } else {
        cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
        for(int i = 0; i < ngi.size(); i++) {
            if(i == ngi.size() - 1) {
                cout << ngi[i] << "." << endl;
            } else {
                cout << ngi[i] << ", ";
            }
        }
    }
    return 0;
}
