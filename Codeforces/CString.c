#include <string.h>
#include <stdlib.h>
#include <math.h>

char* muda(char s[]) {
    int i;
    for(i = 0; i < (int) strlen(s); i++) {
        if(s[i] == ' ') { continue; }
        if(s[i] == 'z') {
            s[i] = 'a';
        } else if(s[i] == 'Z') {
            s[i] = 'A';
        } else {
            s[i] = s[i] + 1;
        }
    }
    return s;
}

int main() {
    char c[] = "qjas mxma zzsa";
    char* a = muda(c);

    puts(a);

    free(a);

    return 0;
}
