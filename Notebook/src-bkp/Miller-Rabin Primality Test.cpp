bool miillerTest(Int d, Int n) {
    // Pick a random number in [2..n-2]
    // Corner cases make sure that n > 4
    Int a = 2 + rand() % (n - 4);
    
    // Compute a^d % n
    Int x = modPow(a, d, n);
 
    if (x == 1  || x == n-1) {
       return true;
    }
 
    // Keep squaring x while one of the following doesn't
    // happen
    // (i)   d does not reach n-1
    // (ii)  (x^2) % n is not 1
    // (iii) (x^2) % n is not n-1
    while (d != n-1) {
        x = (x * x) % n;
        d *= 2;
 
        if (x == 1) {
            return false;
        }
        if (x == n-1) {
            return true;
        }
    }
 
    // Return composite
    return false;
}
 
// It returns false if n is composite and returns true if n
// is probably prime.  k is an input parameter that determines
// accuracy level. Higher value of k indicates more accuracy.
bool isPrime(Int n, int k) {
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;
 
    Int d = n - 1;
    while (d % 2 == 0) {
        d /= 2;
    }
 
    for (int i = 0; i < k; i++) {
        if (miillerTest(d, n) == false) {
              return false;
        }
    }
 
    return true;
}
