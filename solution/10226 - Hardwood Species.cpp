#include <cstdio>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int t;
string s;
map<string, double> tree;
double cnt;

int main(){
    scanf("%d\n\n", &t);

    while(t--){
        cnt = 0;
        tree.clear();

        while(getline(cin, s) && !s.empty()){
            if(tree.count(s) == 0)
                tree.insert(pair<string, double>(s, 1));
            else
                tree[s] += 1;
            cnt++;
        }

        for(map<string, double>::iterator it = tree.begin(); it != tree.end(); ++it){
            cout<<it->first<<" ";
            printf("%.4f\n", (it->second / cnt)*100);
        }

        if(t > 0)
            printf("\n");
    }

    return 0;
}
