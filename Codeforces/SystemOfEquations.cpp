#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

using namespace std;

int n, m, ways = 0;

int main(void) {
    scanf("%d%d", &n, &m);
    for(int i = 0; i <= sqrt(n) + 1; i++) for(int j = 0; j <= sqrt(m) + 1; j++) if(i*i+j == n && i+j*j == m) ways++;
    printf("%d\n", ways);
    return 0;
}
