#include <cstdio>
#include <bitset>
#include <algorithm>
#include <fstream>

using namespace std;

bitset<1000001> bs;

bool setOneTime(int p, int q){
    for(int i = p; i < q; i++){
        if(bs.test(i))
            return false;
        bs.set(i);
    }

    return true;
}

bool setRepeat(int p, int q, int r){
    while(p < 1000000){
        for(int i = p; i < q; i++){
            if(bs.test(i))
                return false;
            bs.set(i);
        }

        p += r;
        q = min(q+r, 1000000);
    }

    return true;
}

int main(){

    int a, b, r, n, m;
    bool status;

    while(scanf("%d %d", &n, &m), (n || m)){
        status = true;
        bs.reset();

        while(n--){
            scanf("%d %d", &a, &b);
            if(!setOneTime(a, b))
                status = false;
        }

        while(m--){
            scanf("%d %d %d", &a, &b, &r);
            if(!setRepeat(a, b, r))
                status = false;
        }

        if(status)
            printf("NO CONFLICT\n");


        else
            printf("CONFLICT\n");

    }
    return 0;
}
