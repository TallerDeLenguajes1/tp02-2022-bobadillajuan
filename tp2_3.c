#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 5
#define M 7



int main(){

int i,j;
int mt[N][M];

int **pmt;
*pmt = &mt[5][7];

for(i = 0;i<N; i++)
{
for(j = 0;j<M; j++)
{
*(*(mt+i)+j) = 1+rand()%100;
printf("%i ", *(*(mt+i)+j));
}
printf("\n");

}

return 0;
}