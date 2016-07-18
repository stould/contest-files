#include <iostream>
#include <stdio.h>
 
using namespace std;
 
int powmod(int a, int n, int mod) {
    int res(1);
    while (n) {
        if (n&1)
            res=(res*a)%mod;
        a=(a*1ll*a)%mod;
        n>>=1;
    }
    return res;
}
 
int mod5(int n) {
    if (n==0)
        return 1;
    int res(mod5(n/5));
    if ((n/5)&1)
        res=(res*4)%5;
    for (int i=1; i<=n%5; i++)
        if (i%5!=0)
            res=(res*i)%5;
    return res;
}
 
int deg(int n, int p) {
    int res(0);
    while (n>=p)
        res+=n/p,n/=p;
    return res;
}
 
int main() {
    int n, inst = 1;
    for( ; ~scanf("%d",&n); ) {
        int pw2(deg(n,2)),pw5(deg(n,5));
        int m2(powmod(5,pw5,2)%2);
        int m5((mod5(n)*powmod(3,pw2,5))%5);
        int m10(0);
        while ((m10%2!=m2) || (m10%5!=m5))
            ++m10;
        int res((m10*powmod(2,pw2-pw5,10))%10);
        printf("Instancia %d\n%d\n\n", inst++, res);
    }
    return 0;
}
