#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

typedef vector<int> vi;
vector<vi> AdjList;

class UnionFind{
    private:
        vi p, rank, setSize;
        int numSets;
    public:
        UnionFind(int n){
            setSize.assign(n, 1);
            rank.assign(n, 0);
            p.assign(n, 0);
            numSets = n;
            for(int i = 0; i < n; i++)
                p[i] = i;
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

        int numDisjointSets(){
            return numSets;
        }
};

int main(){
    int n, m;
    string s;

    while(cin >> n >> m){
        map<char, int> mp;
        UnionFind UF(n);
        AdjList.assign(n, vi());
        int year = 0;

        cin>>s;
        for(int i = 0; i < 3; i++){
            mp.insert(pair<char, int>(s[i], i));
            UF.unionSet(0, i);
        }

        while(m--){
            cin>>s;
            if(mp.find(s[0]) == mp.end())
                mp.insert(pair<char, int>(s[0], mp.size()));
            if(mp.find(s[1]) == mp.end())
                mp.insert(pair<char, int>(s[1], mp.size()));

            AdjList[mp[s[0]]].push_back(mp[s[1]]);
            AdjList[mp[s[1]]].push_back(mp[s[0]]);
        }

        while(UF.numDisjointSets() != 1){
            vector<int> temp;
            for(map<char, int>::iterator it = mp.begin(); it != mp.end(); ++it){
                int idx = it->second;
                if(!UF.isSameSet(0, idx)){
                    int awk = 0;
                    for(int i = 0; i < AdjList[idx].size(); i++){
                        if(UF.isSameSet(0, AdjList[idx][i]))
                            awk++;
                    }
                    if(awk >= 3)
                        temp.push_back(idx);
                }
            }

            if(temp.empty() && UF.numDisjointSets() != 1)
                break;
            while(!temp.empty()){
                UF.unionSet(0, *temp.begin());
                temp.erase(temp.begin());
            }
            year++;
        }

        if(UF.numDisjointSets() != 1)
            cout<<"THIS BRAIN NEVER WAKES UP"<<endl;
        else
            cout<<"WAKE UP IN, "<<year<<", YEARS"<<endl;
    }
    return 0;
}
