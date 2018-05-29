#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    double H,U,D,F,HS;

    while(H>0){
        int d=0;
        scanf("%lf %lf %lf %lf", &H, &U, &D, &F);
        HS = 0;
        while(HS<H && HS>=0){
            HS += U - D;
            U -= (U*F/100);
            if(HS<H && HS>=0) d++;
            printf("%f %f %d\n", HS, U, d);
        }
        if(HS > 0) printf("success on day %d\n", d);
        else printf("failure on day %d\n", d+1);
    }
}

