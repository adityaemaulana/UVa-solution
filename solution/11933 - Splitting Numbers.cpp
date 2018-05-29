#include <cstdio>
#define ll long long int

int main(){
    ll n, a, b, i, j;

    while(scanf("%lld", &n) == 1){
        if(n == 0)
            break;
        a = 0; b = 0;
        i = 0; //index of bits
        j = 0; //index of set bit

        while(n > 0){
            if(n & 1){
                if(j % 2 == 0)
                    a |= (1 << i);
                else
                    b |= (1 << i);
                j++;
            }

            i++;
            n = n >> 1;
        }

        printf("%lld %lld\n", a, b);
    }
    return 0;
}
