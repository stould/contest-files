#include <iostream>

using namespace std;

int n, years[10000];

int main(void) {
    cin >> n;
    years[0] = 1986;
    for(int i = 1; i < 10000; i++) {
        years[i] = years[i - 1] + 76;
    }
    for(int i = 0; i < 10000; i++) {
        if(years[i] > n) {
            cout << years[i] << endl; break;
        }
    }
    return 0;
}
