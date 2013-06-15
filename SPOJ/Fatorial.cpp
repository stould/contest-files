#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

long long fatorial(long long n) {
    for(long long i = n - 1; i > 0; i--) {
        n *= i;
    }

    return n;
}

int main() {
   long long n, fat;

   cin >> n;

   if(n == 0) {
    cout << 1;
   } else {
    fat = fatorial(n);
    cout << fat;
   }
   return 0;
}
