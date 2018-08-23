#include <vector>
#include <iostream>
#include <string>

using namespace std;

typedef vector<int> vi;

class UnionFind{
   private:
       vi p, rank, setSize;
       int numSet;
   public:
    UnionFind(int N){
        setSize.assign(N, 1);
        numSet = N;
        rank.assign(N, 0);
        p.assign(N, 0);
        for(int i = 0; i < N; i++)
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
            numSet--;
            int x = findSet(i);
            int y = findSet(j);
            if(rank[x] > rank[j]){
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
        return numSet;
    }

    int sizeOfSet(int i){
        return setSize[findSet(i)];
    }
};

int main(){
   int t, n, c1, c2;
   string line;
   char type;

   scanf("%d", &t);
   while(t--){
    int usc = 0, sc = 0;
    scanf("\n%d\n", &n);
    UnionFind UF(n);
    while(true){
        if(!getline(cin, line) || line.empty())
            break;

        sscanf(line.c_str(), "%c %d %d", &type, &c1, &c2);
        c1--;c2--;
        if(type == 'c')
            UF.unionSet(c1, c2);
        else
            (UF.findSet(c1) == UF.findSet(c2)) ? sc++ : usc++;

    }

    printf("%d,%d\n", sc, usc);
    if(t > 0)
        printf("\n");
   }

   return 0;
}
