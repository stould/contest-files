#include <iostream>
#include <math.h>

using namespace std;

typedef long long ll;

ll T, N;

int main(void) {
    cin >> T;
    for(; T > 0; T -= 1L) {
        cin >> N;
        N = (((((((N * 567) / 9) + 7492) * 235) / 47) - 498) / 10);
        cout << fabs(N % 10) << endl;
    }
    return 0;
}
