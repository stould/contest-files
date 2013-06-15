#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stdio.h>

using namespace std;

typedef long long ll;

int n, id, p, q;

const ll MAX = 1000000;

struct Mem {
    int id;
    ll c;
};

Mem array[40010];

int main(void) {
    while(cin >> n && n) {
        bool hap = false;
        for(int i = 0; i < n; i++) {
            cin >> array[i].id >> p >> q;
            array[i].c = p * q;
        }
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                if(array[i].id == array[j].id && array[j].id) {
                    array[i].c += array[j].c;
                    array[j].id = 0;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(array[i].id && array[i].c >= MAX) {
                cout << array[i].id << endl;
                hap = false;
            }
        }
        if(hap) {
            cout << "NA" << endl;
        }
    }
    return 0;
}
