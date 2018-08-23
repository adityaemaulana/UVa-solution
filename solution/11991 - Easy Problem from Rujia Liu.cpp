#include <vector>
#include <cstdio>
#include <map>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pl;
typedef vector<pl> vl;

int main(){
    ll m, n, val, v, cnt;
    vector<vl> AdjList;
    while(scanf("%lld %lld", &n, &m) == 2){
        AdjList.assign(n, vl());
        map<ll, ll> ml;

        for(int i = 1; i <= n; i++){
            scanf("%lld", &val);
            if(ml.count(val) == 0){
                AdjList[0].push_back(pl(val, i));
                ml.insert(pl(val, 0));
            }else{
                ml[val]++;
                AdjList[ml[val]].push_back(pl(val, i));
            }

        }

        while(m--){
            scanf("%lld %lld", &cnt, &v);
            cnt--;
            if(ml[v] < cnt)
                printf("0\n");
            else{
                vector<pl>::iterator it;
                for(it = AdjList[cnt].begin(); it != AdjList[cnt].end(); ++it)
                    if(it->first == v)
                        break;
                printf("%lld\n", it->second);
            }
        }
    }

    return 0;
}
