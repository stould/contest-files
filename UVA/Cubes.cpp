#include <iostream>

using namespace std;

typedef long long ll;

ll cubes[61];
int n;

int main(void) {
    for(int i = 0; i <= 60; i++) cubes[i] = (ll) i * i * i;
    for(; cin >> n && n > 0;) {
        bool found = false;
        int a, b;
        for(int i = 0; i <= 60; i++) {
            for(int j = i + 1; j <= 60 && cubes[j] - cubes[i] <= 10000; j++) {
                if(cubes[j] - cubes[i] == n) {
                    b = i;
                    a = j;
                    found = true;
                    goto end;
                }
            }
        }
        end:;if(!found) {
            cout << "No solution" << endl;
        } else {
            cout << a << " " << b << endl;
        }
    }
    return 0;
}
