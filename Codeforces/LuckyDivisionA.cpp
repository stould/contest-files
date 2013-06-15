#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

bool isLucky(int n) {
    while(n > 0) {
        if(n % 10 != 4 && n % 10 != 7) {
            return false;
        }
        n = n / 10;
    }
    return true;
}

int main() {
    int n;
    bool valid = false;

    scanf("%d", &n);

    for(int i = 4; i <= n; i++) {
        if(isLucky(i) == true) {
            if(n % i == 0) {
                valid = true;
                break;
            }
        }
    }

    if(valid) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}
