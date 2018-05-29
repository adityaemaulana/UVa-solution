#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector<int> v;
    int x;

    while(scanf("%d", &x) != EOF){
        v.push_back(x);
        nth_element(v.begin(), v.begin() + v.size()/2, v.end());

        if(v.size() == 1)
            printf("%d\n", v[0]);
        else if(v.size() % 2 != 0)
            printf("%d\n", v[v.size()/2]);
        else{
            int a = v[v.size()/2];
            nth_element(v.begin(), v.begin() + (v.size()/2 - 1), v.end());
            int b = v[v.size()/2 - 1];
            printf("%d\n", (a+b)/2);
        }

    }
}
