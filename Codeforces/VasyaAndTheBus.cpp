#include <iostream>

using namespace std;

int n, m;

int main(void) {
    cin >> n >> m;
    if(n == 0) {
        if(m == 0) {
            cout << "0 0" << endl;
        } else {
            cout << "Impossible" << endl;
        }
        return 0;
    }

    int max = n + (m - 1);
    int min = 0;

    int pay[n];
    for(int i = 0; i < n; i++) pay[i] = 0;

    int i = 0;
    while(m > 0) {
        if(i == n) i = 0;
        pay[i] += 1;
        m -= 1;
        i += 1;
    }
    for(int i = 0; i < n; i++) {
        if(pay[i] == 0) {
            min += 1;
        }
        min += pay[i];
    }
    if(m == 0) {
        min = n; max = n;
    }
    cout << min << " " << max << endl;
    return 0;
}
