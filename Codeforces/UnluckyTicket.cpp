#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n, count = 0;
string v;

int main(void) {
    cin >> n >> v;
    vector<bool> memA(2*n, false), memB(2*n, false);

    sort(v.begin(), v.begin() + n);
    sort(v.begin() + n, v.end());

    for(int i = 0; i < n; i++) {
        int act = v[i] - '0';
        for(int j = n; j < n*2; j++) {
            if(!memA[j] && ((v[j] - '0') > act)) {
                memA[j] = true;
                break;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        int act = v[i] - '0';
        for(int j = n; j < n*2; j++) {
            if(!memB[j] && ((v[j] - '0') < act)) {
                memB[j] = true;
                break;
            }
        }
    }
    int countA = 0, countB = 0;

    for(int i = 0; i < 2*n; i++) {
        if(memA[i]) countA++;
        if(memB[i]) countB++;
    }
    if((countA == n || countB == n)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
