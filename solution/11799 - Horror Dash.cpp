#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int T, N, s;
    scanf("%d", &T);
    for(int i=1; i <= T;i++){
        int smax = 0;
        scanf("%d", &N);
        while(N--){
            scanf("%d", &s);
            if(s > smax) smax = s;
        }
        printf("Case %d: %d\n", i, smax);
    }
    return 0;
}
