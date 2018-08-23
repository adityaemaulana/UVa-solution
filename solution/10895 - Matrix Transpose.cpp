#include <vector>
#include <cstdio>
using namespace std;

typedef vector<pair<int,int>> vii;
vector<vii> AdjList;
int row[10001];

int main(){
    int m, n, r, val;
    while(scanf("%d %d", &m, &n) == 2){
        AdjList.assign(n, vii());
        for(int i = 0; i < m; i++){
            scanf("%d", &r);
            if(r != 0){
                for(int j = 0; j < r; j++){
                    scanf("%d", &val);
                    row[j] = val-1;
                }
                for(int j = 0; j < r; j++){
                    scanf("%d", &val);
                    AdjList[row[j]].push_back(pair<int, int>(val, i+1));
                }
            }
        }

        printf("%d %d\n", n, m);
        for(int i = 0; i < n; i++){
            if(AdjList[i].empty())
                printf("0\n\n");
            else{
                printf("%d", AdjList[i].size());

                for(int j = 0; j < AdjList[i].size(); j++)
                    printf(" %d", AdjList[i][j].second);
                printf("\n");

                printf("%d", AdjList[i][0].first);
                for(int j = 1; j < AdjList[i].size(); j++)
                    printf(" %d", AdjList[i][j].first);
                printf("\n");
            }
        }
    }


    return 0;
}
