#include <iostream>
#include <string>

using namespace std;

int n, p, c, o;
string curr;

int main(void) {
    cin >> n;

    while(n > 0) {
        p = o = c = 0;
        while(1) {
            cin >> curr;
            if(curr == "HOMERUN") {
                p += c + 1;
                c = 0;
            } else if(curr == "OUT") {
                o += 1;
            } else {
                c += 1;
                if(c == 4) {
                    p += 1;
                    c -= 1;
                }
            }
            if(o == 3) break;
        }
        cout << p << endl;
        n--;
    }
    return 0;
}
