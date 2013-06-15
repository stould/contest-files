#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int i, n, k;
string mem[200];

int main(void) {
    cin >> n >> k;
    for(i = 0; i < n; i++) {
        cin >> mem[i];
    }
    sort(mem, mem + n);
    cout << mem[k - 1] << endl;
    return 0;
}
