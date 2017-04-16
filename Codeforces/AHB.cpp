#include <bits/stdc++.h>

using namespace std;

int A, B;

int main() {
    while (cin >> A >> B) {
        string arg = "";
        
        while (A > 0 && B > 0) {
            int da = A % 10;
            int db = B % 10;
            
            arg = char('0' + abs(da - db)) + arg;
            
            A /= 10;
            B /= 10;
        }
        while (arg.front() == '0') {
            arg = arg.substr(1, arg.size());
        }
        if (arg == "") arg = "0";
        cout << arg << endl;
    }
    return 0;
}
