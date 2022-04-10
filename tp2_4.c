#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct PC
{
    int velocidad;
    int anio;
    int cantidad;
    char *tipos;

};

void presentar(struct PC);
void masVieja(struct PC, int *pAux, int i, int *pN);
void masVeloz(struct PC, int *pAux, int i, int *pN);


int main(){

srand(time(NULL));
struct PC computadora[5];
char cpus[6][10]= {"Intel", "AMD", "Celeron","Athlon", "Core", "Pentium"};
int *pAux, aux=2017, n = 0, *pN;
pAux = &aux;
pN = &n;


//Para cargar los datos
for (int i = 0; i < 5; i++)
{

    computadora[i].velocidad = rand()%(3) + 1;
    computadora[i].anio = rand()%(18) + 2000;
    computadora[i].cantidad = rand()%(5) + 1;
    computadora[i].tipos = &cpus[rand()%5][10];

}
printf("\nDatos cargados correctamente.");

printf("\nLista de computadoras: ");

for (int i = 0; i < 5; i++)
{
    presentar(computadora[i]);
}

for (int i = 0; i < 5; i++)
{
    masVieja(computadora[i], pAux, i, pN);
}

printf("\nLa computadora mas vieja es la numero %i y sus datos son:", n+1);
presentar(computadora[n]);

aux=0;
n=0;
for (int i = 0; i < 5; i++)
{
    masVeloz(computadora[i], pAux, i, pN);
}

printf("\nLa computadora mas veloz es la numero %i y sus datos son:", n+1);
presentar(computadora[n]);


return 0;
}

void presentar(struct PC computadora){

    printf("\nDatos del PC:");
    printf("\nVelocidad en Gherz: %i", computadora.velocidad);
    printf("\nAnio: %i", computadora.anio);
    printf("\nCantidad: %i", computadora.cantidad);
    printf("\nTipo de CPU: %s", computadora.tipos);
    printf("\n----------------------\n");
}

void masVieja(struct PC computadora, int *pAux, int i, int *pN){
    
    if (*pAux > computadora.anio)
    {
        *pAux = computadora.anio;
        *pN = i;
    }
    
}

void masVeloz(struct PC computadora, int *pAux, int i, int *pN){
    
    if (*pAux < computadora.velocidad)
    {
        *pAux = computadora.velocidad;
        *pN = i;
    }
    
}
