#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <vector>

using namespace std;

vector<stack<char>> containers;

int main(){
    string s;
    int cases = 1;

    while(cin>>s){
        if(s == "end")
            break;

        int res = 0;
        containers.clear();

        for(int i = 0; i < s.length(); i++){
            int j;
            for(j = 0;j < containers.size();j++){
                if(s[i] <= containers[j].top()){
                    containers[j].push(s[i]);
                    break;
                }
            }

            if(j == containers.size()){
                containers.resize(containers.size()+1);
                containers[j].push(s[i]);
                res++;
            }
        }

        cout<<"Case "<<cases<<": "<<res<<endl;
        cases++;
    }
}
