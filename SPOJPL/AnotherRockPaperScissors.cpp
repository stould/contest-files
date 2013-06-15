#include <iostream>

using namespace std;

typedef long long ll;

ll n;
string app = "RPSPSRSRP";

int main(void) {
    while(cin >> n && n != 0) {
        char c = app[(n % 9)];
        if(c == 'R') {
            cout << 'P' << endl;
        } else if(c == 'P') {
            cout << 'S' << endl;
        } else {
            cout << 'R' << endl;
        }
    }
    return 0;
}
