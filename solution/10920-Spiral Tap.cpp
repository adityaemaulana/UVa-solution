#include <stdio.h>
#define ll long long int
int main(){
    ll sz, p, i, x, y;
    while(scanf("%lld %lld", &sz, &p), sz || p){
        i = 1;
        while(p > i*i)
            i+=2;

        int layerdiff = (sz-i) / 2;
        if(p <= (i*i)- 6*(i/2)){             // p is in north region
            y = sz - layerdiff;
            x = (1 + layerdiff) + (((i*i)- 6*(i/2)) - p);
        }else if(p <= (i*i)- 4*(i/2)){       // p is in west region
            x = 1 + layerdiff;
            y = x + ((i*i)- 4*(i/2) - p);
        }else if(p <= (i*i)- 2*(i/2)){       // p is in south region
            y = 1 + layerdiff;
            x = (sz - layerdiff) - (((i*i)- 2*(i/2)) - p);
        }else{                              // p is in east region
            x = sz - layerdiff;
            y = x - ((i*i) - p);
        }

        printf("Line = %lld, column = %lld.\n", y, x);
    }

    return 0;
}
