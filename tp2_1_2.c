// tl1-tp2-2024-joaquinlechesi
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 20
int main()
{
    int i;
    double vt[N], *p_vt;
    p_vt = vt;
    for(i = 0;i<N; i++)
    {
        vt[i]=1+rand()%100;
        printf("%f ", *(p_vt + i)); //i se igual a p_vt (promocion)
    }
    return 0;
}
