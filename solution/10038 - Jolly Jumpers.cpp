#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>   /* abs */

#define MAX 3000

using namespace std;

int main(){
    int N,n;
    bool b=true;
    vector<int> v;

    while(scanf("%d", &N) != EOF){
        vector<int> a(MAX, 0);
        v.clear();
        b=true;

        while(N--){
            scanf("%d", &n);
            v.push_back(n);
        }

        for(int i=0; i < v.size()-1; i++){
            a[abs(v[i]-v[i+1])] = 1;
        }

        for(int i=1; i < v.size(); i++){
            if(!a[i]){
              b=false;
              break;
            }
        }

        if(b) printf("Jolly\n");
        else printf("Not jolly\n");
    }
    return 0;
}
