#include <iostream>

using namespace std;

bool valid(int b, int c) {
    if(b < 0) {
        return c;
    } else {
        if(b % 2 == 0 && valid(b / 2, b)) {
            return 5;
        }
    }
}

int main() {
    cout << valid(3, 5) << endl;
    return 0;
}
