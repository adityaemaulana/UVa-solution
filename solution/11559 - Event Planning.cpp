#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int N, B, H, W, p, a;

    while(scanf("%d %d %d %d", &N, &B, &H, &W) != EOF){
        int bmin = 9999999;
        while(H--){
            scanf("%d", &p);
            for(int i=0; i<W; i++){
                scanf("%d", &a);
                if(N <= a && (N*p) <= B){
                    if(N*p < bmin) bmin = N*p;
                }
            }
        }

        if(bmin == 9999999) printf("stay home\n");
        else printf("%d\n", bmin);
    }

    return 0;
}
