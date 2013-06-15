#include <iostream>

using namespace std;

int n, v[1000000];

int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];
    int p = 1, j = 0;

    for(int i = 1; i < n; i++) {
        if(v[i] - v[i - 1] != v[j + 1] - v[j]) {
            j = i; p++; i++;
        }
    }
    cout << p << endl;
    return 0;
}
