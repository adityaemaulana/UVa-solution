#include <stdio.h>
#include <vector>

int col[500], row[500];

int minimum(int k){
    int res=0;
    bool cf[k]={false}, rf[k]={false};

    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            if(col[i] == row[j] && !cf[i] && !rf[j]){
                res += row[j];
                cf[i] = rf[j] = 1;
            }
        }
    }

    for(int i = 0; i < k; i++){
        if(!cf[i])
            res+=col[i];
        if(!rf[i])
            res+=row[i];
    }

    return res;
}

int maximum(int k){
    int res = 0;
    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++)
            res = (col[i] <= row[j]) ? res+col[i] : res+row[j];
    }

    return res;
}

int main(){
    int t, k, n, m;
    scanf("%d", &t);
    while(t--){

        n = m = 0;
        scanf("%d", &k);

        for(int i = 0; i < k; i++)
            scanf("%d", &col[i]);

        for(int j = 0; j < k; j++)
            scanf("%d", &row[j]);

        n = minimum(k);
        m = maximum(k);

        printf("Matty needs at least %d blocks, ", n);
        printf("and can add at most %d extra blocks.\n", m-n);

    }

    return 0;
}
