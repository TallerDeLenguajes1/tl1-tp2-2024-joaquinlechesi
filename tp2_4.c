#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct compu
{
    int velocidad;
    int anio;
    int cantidad;
    char *tipo_cpu;
};
void cargar(struct compu *p_lista, char *p_tipos);
void mostrar(struct compu *p_lista);
void masAntigua(struct compu *p_lista);
void mayorVelocidad(struct compu *p_lista);

int main()
{
    char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    char *p_tipos;
    p_tipos = tipos[0];
    //p_tipos = tipos[6];
    struct compu lista[5], *p_lista;
    p_lista = lista;
    //puts(p_tipos);
    cargar(p_lista, p_tipos);
    mostrar(p_lista);
    masAntigua(p_lista);
    mayorVelocidad(p_lista);
    return 0;
}

void cargar(struct compu *p_lista, char *p_tipos){
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("Computadora n° %d\n", i+1);
        puts("Ingrese la velocidad de procesador:");
        scanf("%d", &p_lista[i].velocidad);
        puts("Ingrese el año de salida:");
        scanf("%d", &p_lista[i].anio);
        puts("Ingrese la cantidad de nucleos que posee el procesador:");
        scanf("%d", &p_lista[i].cantidad);
        puts("Para indicar la cantidad seleccione un numero de la siguiente lista:");
        int j;
        char *p_puntero_original = p_tipos;
        for (j = 0; j < 6; j++)
        {
            printf("%d para ", j+1);
            puts(p_tipos);
            p_tipos+=10;
        }
        //p_tipos-=10*j;
        p_tipos = p_puntero_original;
        int tipo;
        scanf("%d", &tipo);
        p_tipos+=10*(tipo-1);
        p_lista[i].tipo_cpu = p_tipos;
        //p_tipos+=tipo;
        p_tipos = p_puntero_original;
    }
}

void mostrar(struct compu *p_lista){
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("Computadora n° %d\n", i+1);
        printf("El procesador es: ");
        puts(p_lista[i].tipo_cpu);
        printf("La velocidad del procesador es: %d\n", p_lista[i].velocidad);
        printf("El año de salida es: %d\n", p_lista[i].anio);
        printf("La cantidad de nucleos del procesador es: %d\n", p_lista[i].cantidad);
    }    
}

void masAntigua(struct compu *p_lista){
    int anio = 0, i, numero;
    for (i = 0; i < 5; i++)
    {
        if (anio == 0)
        {
            anio = p_lista[i].anio;
            numero = i;
        }
        else
        {
            if (p_lista[i].anio < anio)
            {
                anio = p_lista[i].anio;
                numero = i;
            }
        }
    }
    printf("La pc mas antigua es la n° %d", numero+1);
    
}

void mayorVelocidad(struct compu *p_lista){
    int velocidad = 0, i, numero;
    for (i = 0; i < 5; i++)
    {
        if (p_lista[i].velocidad > velocidad)
        {
            velocidad = p_lista[i].velocidad;
            numero = i;
        }
    }
    printf("\nLa PC mas rapida es la n° %d", numero+1);
}