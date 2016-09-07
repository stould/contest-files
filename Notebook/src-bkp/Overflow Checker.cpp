int highestOneBitPosition(unsigned long long a) {
    int bits=0;
    while (a!=0) {
        ++bits;
        a>>=1;
    }
    return bits;
}

bool ms(unsigned long long a, unsigned long long b) {
    int a_bits=highestOneBitPosition(a), b_bits=highestOneBitPosition(b);
    return (a_bits+b_bits <= 64);
}
