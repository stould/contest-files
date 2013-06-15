#include <iostream>

using namespace std;

int n, matrix[1010][1010];

int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    return 0;
}
