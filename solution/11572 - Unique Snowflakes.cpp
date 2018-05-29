#include <cstdio>
#include <map>
#include <vector>

using namespace std;

vector<int> pack;
map<int, bool> sf;
int t, n, sz, maks, temp, deleted;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        pack.clear();
        sf.clear();

        maks = temp = deleted = 0;

        while(n--){
            scanf("%d", &sz);
            pack.push_back(sz);

            if(sf.count(sz) == 0){
                sf.insert(pair<int,bool>(sz, true));
                temp++;
            }else{
                if(temp > maks) maks = temp;
                while(pack[deleted] != sz){
                    sf.erase(pack[deleted]);
                    temp--;
                    deleted++;
                }
                deleted++;
            }
        }

        if(temp > maks) maks = temp;
        printf("%d\n", maks);
    }
    return 0;
}
