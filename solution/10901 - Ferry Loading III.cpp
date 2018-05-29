#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int c, n, t, m, arv, res, cnt;
string op;
bool load;
queue<int> a, b;
vector<int> posl(10050), posr(10050), ans(10050);

int main(){
    cin>>c;
    while(c--){
        cin>>n>>t>>m;
        ans.clear();

        for(int i = 0; i < m; i++){
            cin>>arv>>op;
            if(op == "left"){
                a.push(arv);
                posl[arv] = i;
            }
            else{
                b.push(arv);
                posr[arv] = i;
            }
        }

        if(!a.empty() && !b.empty())
            res = min(a.front(), b.front());
        else if(!a.empty())
            res = a.front();
        else
            res = b.front();

        while(!a.empty() || !b.empty()){
            cnt = 0;
            load = false;
            while(!a.empty() && a.front() <= res && cnt < n){
                ans[posl[a.front()]] = res+t;
                a.pop();
                cnt++;
                load = true;
            }

            if(load)
                res+=t;
            else{
                if(!a.empty()){
                    res = a.front();
                }else{
                    res+=t;
                }
            }

            cnt = 0;
            load = false;
            while(!b.empty() && b.front() <= res && cnt < n){
                ans[posr[b.front()]] = res+t;
                b.pop();
                cnt++;
                load = true;
            }

            if(load)
                res+=t;
            else{
                if(!b.empty()){
                    res=b.front();
                }else{
                    res+=t;
                }
            }
        }

        for(int i = 0; i < m; i++)
            cout<<ans[i]<<endl;
    }

    return 0;
}
