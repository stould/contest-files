#include <iostream>
#include <vector>

using namespace std;

#define MAXN 10000

int n, a[MAXN];

void quicksort(int low, int high) {
    int i = low, j = high, h;

    int x = a[(low+high)/2];

    do {
        while(a[i] < x) i++;
        while(a[j] > x) j--;
        if(i <= j) {
            h = a[i];
            a[i] = a[j];
            a[j] = h;
            i++;
            j--;
        }
    } while(i <= j);

    if(low < j) quicksort(low, j);
	if(i < high) quicksort(i, high);
}

int main(void) {
	
	return 0;
}
