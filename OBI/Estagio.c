#include <stdio.h>
#include <stdlib.h>

#define MAX_ALUNOS 1000

int main() {
    int i, maior_media, n;

    int turma=1;
    struct {
        int codigo, media;
    } alunos[MAX_ALUNOS];

    do {
        scanf("%d%*c", &n);
        if(n == 0) break;
        for (i = 0; i < n; i++) {
            scanf("%d%*c%d%*c", &alunos[i].codigo, &alunos[i].media);
        }
        maior_media = 0;
        for (i = 1; i < n; i++) {
            if (alunos[i].media > maior_media) {
                maior_media = alunos[i].media;
            }
        }

        printf("Turma %d\n", turma++);
        for(i = 0; i < n; i++) {
            if(alunos[i].media == maior_media) {
                printf("%d ", alunos[i].codigo);
            }
        }
        printf("\n\n");
    } while(1);
    return 0;
}
