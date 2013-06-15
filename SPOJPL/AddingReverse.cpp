#include <stdio.h>
#include <algorithm>
#include <sstream>

using namespace std;

int n, a, b;

int pow(int n, int x) {
    int ans = n;
    for(int i = 1; i <= x; i++) ans *= n;
    return ans;
}

int reverse(int x) {
    string a = "";
    int ans = 0;
    while(x > 0) {
        a += (x % 10) + '0';
        x /= 10;
    }
    istringstream ss(a);
    ss >> ans;
    return ans;
}

int main(void) {
    scanf("%d", &n);

    while(n--) {
        scanf("%d%d", &a, &b);
        int aa = reverse(a);
        int bb = reverse(b);

        printf("%d\n", reverse(aa+bb));
    }

    return 0;
}
