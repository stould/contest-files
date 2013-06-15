#include <iostream>
#include <utility>

using namespace std;

int main() {
    int n, moves = 0;

    cin >> n;

    pair<int, int> root = make_pair(1, 1);

    while(root.first != n || root.second != n) {
        if(root.first > root.second) {
            root.second += root.first;
        } else {
            root.first += root.second;
        }
        moves++;
    }

    cout << moves << endl;

    return 0;
}
