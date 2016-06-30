#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <functional>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;
 
#define DEBUG(x...) printf(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define _foreach(it, b, e) for(__typeof__(b) it = (b); it != (e); ++it)
#define foreach(x...) _foreach(x)
 
typedef long long int Int;
 
const int inf = 0x3f3f3f3f;
const Int hugeinf = 0x3f3f3f3f3f3f3f3fll;
const double eps = 1e-9;
 
int dp[2101], n, d, m, y, c, vc[1001], days[13], tdays[1001];
bool isLeapYear[2101];
 
bool isLeapYear_r(int Y){
    if ( ( (!(Y % 4)) && (Y % 100) ) || (!(Y % 400)) ) return true;
    return false;
}
 
void fill(){
    for(int i = 1900; i < 2101; i++) isLeapYear[i] = false;
    dp[1900] = 0;
    isLeapYear[1900] = isLeapYear_r(1900);
    for(int i = 1901; i < 2101; i++){
        dp[i] = dp[i-1] + 365;
        isLeapYear[i] = isLeapYear_r(i);
    }
    int meses[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    days[0] = meses[0];
    for(int i = 1; i < 13; i++){
        days[i] = days[i-1] + meses[i];
    }
}
 
int main(void){
    fill();
    while(scanf("%d", &n) && n){
        int leap_tatal = 0, lastYear = 0, daysok = 0, consumo = 0;
        for(int i = 0; i < n; i++){
            scanf("%d%d%d%d", &d, &m, &y, &c);
            vc[i] = c;
            if(isLeapYear[y]){
                if(lastYear != y){
                    leap_tatal++;
                    lastYear = y;
                }
                if(m > 2){
                    tdays[i] = (dp[y]+days[m-1]+d+leap_tatal);
                }else{
                    tdays[i] = (dp[y]+days[m-1]+d+leap_tatal-1);
                }
            }else{
                tdays[i] = (dp[y]+days[m-1]+d+leap_tatal);
            }
            if((tdays[i] - tdays[i-1]) == 1){
                consumo += vc[i] - vc[i-1];
                daysok++;
            }
        }
        printf("%d %d\n", daysok, consumo);
    }
    return 0;
}
 
 
