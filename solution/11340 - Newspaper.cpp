#include <map>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#define MAX 10000

using namespace std;

int main(){
    int N, K, M;
    char k;
    double v, sum;
    string str;
    map<char, double> m;

    scanf("%d", &N);
    while(N--){
        str="";sum=0;
        m.clear();
        scanf("%d", &K);
        while(K--){
            cin>>k>>v;
            m.insert(pair<char, double>(k,v));
        }
        scanf("%d", &M);

        for(int i=0;i<M+1;i++){
           getline(cin, str);
           for(char& c : str){
            if(m.find(c)!=m.end()){
               sum+=m.find(c)->second;
            }
           }
        }

        printf("%.2f$\n", sum/100);
    }
}
