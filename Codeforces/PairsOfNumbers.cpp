#include <iostream>
#include <utility>

using namespace std;

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int lcd(int a, int b) {
    return b * a / gcd(a, b);
}

int main() {
    int n, moves = 1 >> 20;

    cin >> n;

    for(int i = 1; i < n; i++) {
        int temp = lcd(n, i);
        if(temp < moves) {
            moves = temp;
        }
    }

    cout << moves << endl;

    return 0;
}
