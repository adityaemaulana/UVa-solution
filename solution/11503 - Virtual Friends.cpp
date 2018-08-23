#include <vector>
#include <string>
#include <cstdio>
#include <map>
using namespace std;

typedef vector<int> vi;

class UnionFind{
private:
    vi p, rank, setSize;
    int numSets;
public:
    UnionFind(int n){
        rank.assign(n, 0);
        setSize.assign(n, 1);
        p.assign(n, 0);
        for(int i = 0; i < n; i++)
            p[i] = i;
        numSets = n;
    }

    int findSet(int i){
        return (p[i] == i) ? i : findSet(p[i]);
    }

    bool isSameSet(int i, int j){
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j){
        if(!isSameSet(i, j)){
            numSets--;
            int x = findSet(i);
            int y = findSet(j);

            if(rank[x] > rank[y]){
                p[y] = x;
                setSize[x] += setSize[y];
            }else{
                p[x] = y;
                setSize[y] += setSize[x];
                if(rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }

    int sizeOfSet(int i){
        return setSize[findSet(i)];
    }
};

int main(){
    int t, f;
    char p1[30], p2[30];
    scanf("%d", &t);
    while(t--){
        scanf("%d", &f);
        map<string, int> mp;
        UnionFind UF(100000);

        while(f--){
            scanf("%s %s", &p1, &p2);

            if(mp.find(p1) == mp.end())
                mp.insert(pair<string, int>(p1, mp.size()));
            if(mp.find(p2) == mp.end())
                mp.insert(pair<string, int>(p2, mp.size()));

            UF.unionSet(mp[p1], mp[p2]);
            printf("%d\n", UF.sizeOfSet(mp[p1]));
        }
    }
    return 0;
}
