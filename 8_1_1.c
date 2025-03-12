#include <stdio.h>

int main(){
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    float * ptrf, * ptrcelsius;
    int * ptrstep, * ptrupper;

    ptrf = &fahr;
    ptrcelsius = &celsius;
    ptrstep = &step;
    ptrupper = &upper;

    while(1){
        *ptrcelsius = (5.0/9.0) * (*ptrf - 32);
        printf("%3.0f %6.1f \n", *ptrf, *ptrcelsius);
        *ptrf += *ptrstep;
        if(*ptrf > *ptrupper) break;
    }
    return 0;
}