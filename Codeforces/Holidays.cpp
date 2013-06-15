#include <iostream>

using namespace std;

typedef long long ll;

int n, m, a, b, number = -1, times = 0, mem[101];

int main(void) {
    for(int i = 0; i < 101; i++) mem[i] = 0;
    cin >> n >> m;
    bool all = false;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        for(int j = a; j <= b; j++) {
            mem[j] += 1;
        }
    }
    for(int i = 1; i <= n; i++) {
        if(mem[i] != 1) {
            number = i; times = mem[i]; all = true; break;
        }
    }
    if(all) {
        cout << number << " " << times << endl;
    } else {
        cout << "OK" << endl;
    }
    return 0;
}
