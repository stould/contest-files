//Worst Case O(n^2) but usually O(n log(n))
void quicksort(int lo, int hi) {
    int i=lo, j=hi, h;
	
    int x=a[(lo+hi)/2];

    do {
        while (a[i]<x) i++;
        while (a[j]>x) j--;
        if (i<=j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i<=j);

    if (lo<j) quicksort(lo, j);
    if (i<hi) quicksort(i, hi);
}
