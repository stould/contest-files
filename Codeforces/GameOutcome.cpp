#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long ll;

int maze[30][30];

int main(void) {
    int n, win = 0;
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int sumR = 0, sumC = 0;
            for(int k = 0; k < n; k++) {
                sumR += maze[i][k];
                sumC += maze[k][j];
            }
            if(sumC > sumR) win++;
        }
    }
    cout << win << endl;
    return 0;
}
