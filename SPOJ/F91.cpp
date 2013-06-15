#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstdio>

typedef long long ll;

using namespace std;

int f91(int n) {
  if(n >= 101) {
    return n - 10;
  } else {
    return f91(f91(n + 11));
  }
}

int main() {
  int n;
  while(1) {
    scanf("%d", &n);
    if(n == 0) { break; }
    printf("f91(%d) = %d\n", n, f91(n));
  }
  return 0;
}
