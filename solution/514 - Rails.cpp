#include <stack>
#include <cstdio>

using namespace std;

int main(){
    int n, val;
    stack<int> a, b;

    while(scanf("%d", &n)){
        if(n == 0)
            break;

        while(true){
            while(a.size() > 0)
                a.pop();

            while(b.size() > 0)
                b.pop();

            for(int i = n; i > 0; i--)
                a.push(i);

                for(int i = 0; i < n; i++){
                scanf("%d", &val);
                if(val == 0)
                    break;

                if(b.empty()){
                   while(a.size() > 0){
                        b.push(a.top());
                        a.pop();
                        if(b.top() == val) break;

                    }
                }else{
                    if(val != b.top()){
                        while(a.size() > 0){
                            b.push(a.top());
                            a.pop();
                            if(b.top() == val) break;
                        }
                    }
                }

                if(val == b.top())
                    b.pop();
            }

            if(val == 0) break;

            if(b.empty())
                printf("Yes\n");
            else
                printf("No\n");
        }

        printf("\n");
    }

    return 0;
}
