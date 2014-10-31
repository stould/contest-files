#include <stdio.h>
#include <string.h>
char str[50010];
 
unsigned long long x, y, P[50010], B = 1947698881ULL;
 
int F(int i, int j){
if(i >= j) return (i == j);
 
x = y = 0;
int r = 1, l = 0;
while (i < j){
x = x * B + str[i];
y = P[l] * str[j] + y;
if (x == y){
r = 2 + F(i + 1, j - 1);
break;
}
i++, l++, j--;
}
return r;
}
int main(){
int T = 0, t, i;
P[0] = 1ULL;
for(i = 1; i < 50010; i++) P[i] = (P[i - 1] * B);
 
scanf("%d", &t);
while (t--){
scanf("%s", str);
printf("Case #%d: %d\n", ++T, F(0, strlen(str) - 1));
}
return 0;
}
