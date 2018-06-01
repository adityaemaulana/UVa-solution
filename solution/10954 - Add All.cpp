#include <cstdio>
#include <queue>
#define ll long long
using namespace std;

int main(){
    ll n, val, res, a, b, temp;
    while(scanf("%lld", &n)){
        if(n == 0)
            break;

        priority_queue<ll, vector<ll>, greater<ll>> pq;
        while(n--){
            scanf("%lld", &val);
            pq.push(val);
        }

        res = 0;
        if(pq.size() > 1){
            while(!pq.empty()){
                a = pq.top();pq.pop();
                b = pq.top();pq.pop();
                temp = a + b;
                res += temp;

                if(!pq.empty())
                    pq.push(temp);
            }
        }

        printf("%lld\n", res);
    }
    return 0;
}
