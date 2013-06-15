#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main() {
  int n, count = 1;

  while(1) {
    scanf("%d", &n);

    if(n == 0) { break; }
    
    int c = 0, d = 0, cc = 0, u = 0;

    c = n / 50;
    n -= c * 50;
    d = n / 10;
    n -= d * 10;
    cc = n / 5;
    n -= cc * 5;
    u = n / 1;
    
	 printf("Teste %d\n", count);
    printf("%d %d %d %d\n", c, d, cc, u);    
	 count++;
  }
  return 0;
}
