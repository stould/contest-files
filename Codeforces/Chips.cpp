#include <iostream>

using namespace std;

int n, m;

int main(void) {
    cin >> n >> m;

    while(1) {
        for(int i = 1; i <= n; i++) {
            if(m - i < 0) {
                goto end;
            }
            m -= i;
        }
    }
    end:;
    cout << m << endl;
    return 0;
}
