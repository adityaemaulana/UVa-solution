#include <cstdio>
#include <set>
#define ll long long int

using namespace std;

set<int, greater<int>> a, b;

int main(){
    ll t, n, m, val, res;

    while(scanf("%lld %lld", &n, &m)){
        if(n == 0 && m == 0)
            break;

        a.clear();
        b.clear();
        res = 0;

        while(n--){
            scanf("%lld", &val);
            a.insert(val);
        }
        while(m--){
            scanf("%lld", &val);
            b.insert(val);
        }

        set<int, greater<int>>::iterator it = a.begin();
        for(it = a.begin(); it != a.end(); ++it)
            res = (b.find(*it) != b.end()) ? res+1 : res;

        printf("%lld\n", res);
    }

    return 0;
}
