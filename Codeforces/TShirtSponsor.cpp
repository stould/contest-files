#include <stdio.h>
#include <string.h>

int K;
int N[10];
char buf[10];

char* func1(int x) {
  if (x == 0) {
    return "S";
  } else if (x == 1) {
    return "M";
  } else if (x == 2) {
    return "L";
  } else if (x == 3) {
    return "XL";
  } else if (x == 4) {
    return "XXL";
  }
}

int func2(char* x) {
  if (!strcmp(x, "S")) {
    return 0;
  } else if (!strcmp(x, "M")) {
    return 1;
  } else if (!strcmp(x, "L")) {
    return 2;
  } else if (!strcmp(x, "XL")) {
    return 3;
  } else if (!strcmp(x, "XXL")) {
    return 4;
  }
}

int main(void) {
  int i, j;

  for (i = 0; i < 5; i++) scanf("%d", &N[i]);

  scanf("%d", &K);

  for ( ; K--; ) {
    scanf("%s", buf);

    int id = func2(buf);

    for (i = id, j = id; i < 5 || j >= 0; i++, j--) {
      if (i < 5 && N[i] > 0) {
	N[i] -= 1; 
	printf("%s\n", func1(i));
	break;
      } 
      if (j >= 0 && N[j] > 0) {
	N[j] -= 1; 
	printf("%s\n", func1(j));
	break;
      }
    }
  }
}
