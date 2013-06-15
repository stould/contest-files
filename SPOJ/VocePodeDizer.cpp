#include <iostream>

using namespace std;

string tmp;
int i;

int main(void) {
    while(cin >> tmp) {
        if(tmp == "0") break;
        int r = 0, l = 0;
        for(i = 0; i < (int) tmp.size(); i++) {
            if(i % 2 == 0) {
                r += (tmp[i] - '0');
            } else {
                l += (tmp[i] - '0');
            }
        }
        if((r - l) % 11 == 0) {
            cout << tmp << " is a multiple of 11." << endl;
        } else {
            cout << tmp << " is not a multiple of 11." << endl;
        }
    }
    return 0;
}
