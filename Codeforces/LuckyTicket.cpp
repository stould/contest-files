#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int N;
    string v;
    cin >> N;
    cin >> v;

    bool ok = true;
    int sumr = 0, suml = 0;

    for(int i = 0; i < N / 2; i++) {
        suml += v[i] - '0';
        if(v[i] != '7' && v[i] != '4') ok = false;
    }
    for(int i = N / 2; i < N; i++) {
        sumr += v[i] - '0';
        if(v[i] != '7' && v[i] != '4') ok = false;
    }
    if(sumr == suml && ok) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
