#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define M 26

using namespace std;

int idx[M];
vector <int> v[M], temp;

void print(vector <int> v[], int n){
    for(int i=0; i<n; i++){
        printf("%d:", i);
        for(vector<int>::iterator it = v[i].begin(); it != v[i].end(); ++it)
            printf(" %d", *it);
        printf("\n");
    }
}

void move_onto(vector<int> v[], int idx[], int a, int b){
    while(v[idx[a]].back() != a){
        v[v[idx[a]].back()].push_back(v[idx[a]].back());
        idx[v[idx[a]].back()] = v[idx[a]].back();
        v[idx[a]].pop_back();
    }
    while(v[idx[b]].back() != b){
        v[v[idx[b]].back()].push_back(v[idx[b]].back());
        idx[v[idx[b]].back()] = v[idx[b]].back();
        v[idx[b]].pop_back();
    }

    v[idx[b]].push_back(v[idx[a]].back());
    v[idx[a]].pop_back();
    idx[a] = idx[b];
}

void move_over(vector<int> v[], int idx[], int a, int b){
    while(v[idx[a]].back() != a){
        v[v[idx[a]].back()].push_back(v[idx[a]].back());
        idx[v[idx[a]].back()] = v[idx[a]].back();
        v[idx[a]].pop_back();
    }

    v[idx[b]].push_back(v[idx[a]].back());
    v[idx[a]].pop_back();
    idx[a] = idx[b];
}

void pile_onto(vector<int> v[], int idx[], int a, int b){
    while(v[idx[b]].back() != b){
        v[v[idx[b]].back()].push_back(v[idx[b]].back());
        idx[v[idx[b]].back()] = v[idx[b]].back();
        v[idx[b]].pop_back();
    }

    while(v[idx[a]].back() != a){
        temp.push_back(v[idx[a]].back());
        v[idx[a]].pop_back();
        idx[temp.back()] = idx[b];
    }
    temp.push_back(a);
    v[idx[a]].pop_back();
    idx[a] = idx[b];

    while(!temp.empty()){
        v[idx[b]].push_back(temp.back());
        temp.pop_back();
    }
}

void pile_over(vector<int> v[], int idx[], int a, int b){
     while(v[idx[a]].back() != a){
        temp.push_back(v[idx[a]].back());
        idx[v[idx[a]].back()] = idx[b];
        v[idx[a]].pop_back();

    }
    temp.push_back(v[idx[a]].back());
    v[idx[a]].pop_back();
    idx[a] = idx[b];

    while(!temp.empty()){
        v[idx[b]].push_back(temp.back());
        temp.pop_back();
    }

}

int main(){
    int n, a, b;
    char s1[30], s2[30];

    scanf("%d",&n);
    for(int i = 0; i<n; i++){
       idx[i] = i;
       v[i].push_back(i);
    }

    while(cin>>s1){
        if(s1[0] == 'q')
            break;

        scanf("%d %29s %d", &a, s2, &b);
        if(idx[a] == idx[b])
            continue;


        if(s1[0] == 'm'){
            if(s2[1] == 'n'){
                move_onto(v, idx, a, b);
            }else{
                move_over(v, idx, a, b);
            }
        }else{
            if(s2[1] == 'n'){

                pile_onto(v, idx, a, b);
            }else{
                pile_over(v, idx, a, b);
            }
        }
    }
    print(v,n);

    return 0;
}
