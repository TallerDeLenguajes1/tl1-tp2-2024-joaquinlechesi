#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
#define M 7
int main()
{
    int i,j;
    // contador = 0;
    int mt[N][M];
    //…
    int *p_mt;
    p_mt = &mt[N][M];
    srand(time(NULL));
    for(i = 0;i<N; i++)
    {
        //printf("Fila: %d ", i+1);
        for(j = 0;j<M; j++){
            mt[i][j]=1+rand()%100;
            printf("%d ", mt[i][j]);
            //printf("%p ", p_mt);
            p_mt++;
            //printf("%d ", contador);
            //contador++;
        }
        printf("\n");
    }
    
    return 0;
}

