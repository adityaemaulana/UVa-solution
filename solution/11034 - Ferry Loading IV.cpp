#include <iostream>
#include <queue>
#include <string>

using namespace std;

int c, l, m, lc, cross, ltot, i;
string s;
queue<int> q[2];

int main(){
    cin>>c;
    while(c--){
        while(!q[0].empty()) q[0].pop();
        while(!q[1].empty()) q[1].pop();

        cin>>l>>m;
        l*=100;
        while(m--){
            cin>>lc>>s;
            if(s == "left") q[0].push(lc);
            else q[1].push(lc);
        }

        cross = 0;
        i = 0;
        while(!q[0].empty() || !q[1].empty()){
            ltot = 0;
            while(!q[i].empty() && ltot <= l){
                if(ltot + q[i].front() <= l){
                    ltot += q[i].front();
                    q[i].pop();
                }else break;
            }
            cross++;
            i = (i+1) % 2;
        }
        cout<<cross<<endl;
    }
    return 0;
}
