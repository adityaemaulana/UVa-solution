#include <cstdio>
#include <queue>
#include <stack>

using namespace std;

int main(){
    int n, cmd, val;
    bool a, b, c;

    while(scanf("%d", &n) != EOF){
        priority_queue<int> pq;
        queue<int> q;
        stack<int> s;
        a = b = c = true;

        while(n--){
            scanf("%d %d", &cmd, &val);
            if(cmd == 1){
                if(a)
                    pq.push(val);
                if(b)
                    q.push(val);
                if(c)
                    s.push(val);
            }else if(cmd == 2){
                if(pq.empty() && q.empty() && s.empty())
                    a = b = c = false;

                if(a && !pq.empty()){
                    if(pq.top() == val)
                        pq.pop();
                    else
                        a = false;
                }
                if(b && !q.empty()){
                    if(q.front() == val)
                        q.pop();
                    else
                        b = false;
                }
                if(c && !s.empty()){
                    if(s.top() == val)
                        s.pop();
                    else
                        c = false;
                }
            }
        }

        if(a && !b && !c)
            printf("priority queue\n");
        else if(!a && b && !c)
            printf("queue\n");
        else if(!a && !b && c)
            printf("stack\n");
        else if(a || b || c)
            printf("not sure\n");
        else
            printf("impossible\n");
    }
}
