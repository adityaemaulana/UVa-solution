#include <cstdio>
#include <set>
#include <vector>
#define ll long long int

using namespace std;

multiset<ll, greater<ll>> s;

int main(){
    ll n, res, k, val;
    while(true){
        scanf("%lld", &n);
        if(n == 0)
            break;

        s.clear();
        res = 0;
        while(n--){
            scanf("%lld", &k);
            for(int j = 0; j < k; j++){
                scanf("%lld", &val);
                s.insert(val);

            }

            res += *s.begin() - *prev(s.end());
            s.erase(s.begin());
            s.erase(prev(s.end()));
        }

        printf("%lld\n", res);
    }

    return 0;
}
