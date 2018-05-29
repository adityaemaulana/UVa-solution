#include <cstdio>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int inp, n, s, q, nc, c, cnt, time;
//number of input stations, capacity of carrier, platform b size, number of cargo, cargo, number of cleared cargo, time occured

vector<queue<int>> que;
stack<int> carrier;

void input(){
    cnt = time = 0;
    que.clear();
    scanf("%d %d %d", &n, &s, &q);
    que.resize(n+1);

    while(!carrier.empty())
        carrier.pop();

    for(int i = 1; i <= n; i++){
        scanf("%d", &nc);
        cnt+=nc;
        while(nc--){
            scanf("%d", &c);
            que[i].push(c);
        }
    }
}

void unload(int i){
    while(!carrier.empty()){
        if(carrier.top() == i){
            carrier.pop();
            time += 1 ;
            cnt--;
        }else{
            if(que[i].size() == q)
                break;

            que[i].push(carrier.top());

            carrier.pop();
            time += 1;
        }
    }
}

void load(int i){
    while(!que[i].empty() && carrier.size() < s){
        carrier.push(que[i].front());
        que[i].pop();
        time+=1;
    }
}

int main(){
    scanf("%d", &inp);
    while(inp--){
       input();

       while(cnt > 0){
          for(int i = 1; i <= n; i++){
            if(cnt == 0)
                break;
            unload(i);
            load(i);
            time+=2;
          }
       }

       printf("%d\n", time-2);
    }

    return 0;
}
