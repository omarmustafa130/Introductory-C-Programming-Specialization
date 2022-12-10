#include <stdlib.h>
#include <stdio.h>


typedef struct _retire_info
{
    int months;
    double contribution;
    double rate_of_return;
}retire_info;

void retirement (int startAge,  //in months
                 double initial, //initial savings in dollars
                 retire_info working, //info about working
                 retire_info retired  //info about being retired
                 );


void retirement(int startAge, double initial, retire_info working, retire_info retired)
{
    double total = initial;
    printf("Age %3d month %2d you have $%.2lf\n", (startAge)/12, (startAge)%12, total);
    for (int i=1; i<=working.months; i++)
    {
        total+=(total*(working.rate_of_return/100)/12.0)+working.contribution;
        printf("Age %3d month %2d you have $%.2lf\n", (startAge+i)/12, (startAge+i)%12, total);

    }
    for (int k=working.months+1; k<retired.months+working.months; k++)
    {
        total+=(total*(retired.rate_of_return/100)/12.0)+retired.contribution;
        printf("Age %3d month %2d you have $%.2lf\n", (startAge+k)/12, (startAge+k)%12, total);

    }
}

int main()
{
    retire_info w = {489, 1000, 4.5};
    retire_info r = {384, -4000, 1.0};
    retirement(327,21345, w,r);
    return 0;
}
