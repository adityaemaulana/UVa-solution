#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <string>

using namespace std;

typedef vector<char> vc;
vector<vc> AdjList;
map<char, int> m;
bool visited[27];
int tree, acorn, totalNode;

void dfs(char c){
    visited[m[c]] = true;
    totalNode++;

    for(vector<char>::iterator it = AdjList[m[c]].begin(); it != AdjList[m[c]].end(); ++it)
        if(!visited[m[*it]])
            dfs(*it);
}

void input(){
        m.clear();
        int i, j;
        char c[61];
        AdjList.assign(27, vc());
        memset(visited, 0, sizeof(visited));
        acorn = tree = i = j = 0;

        while(scanf("%60s", &c)){
            if(c[0] == 42){
                break;
            }

            if(m.count(c[1]) == 0){
                m.insert(pair<char, int>(c[1], i));
                AdjList[i].push_back(c[3]);
                i++;
            }else
                AdjList[m[c[1]]].push_back(c[3]);

            if(m.count(c[3]) == 0){
                m.insert(pair<char, int>(c[3], i));
                AdjList[i].push_back(c[1]);
                i++;
            }else
                AdjList[m[c[3]]].push_back(c[1]);
        }

        scanf("%60s", &c);
        while(c[j] != 0 && j < 61){
            if(c[j] > 64 && c[j] < 91)
                if(m.count(c[j]) == 0)
                    acorn++;

            j++;
        }
}

int main(){
    int t;

    scanf("%d", &t);
    while(t--){
        input();

        for(map<char, int>::iterator it = m.begin(); it != m.end(); ++it){
            if(!visited[it->second]){
                totalNode = 0;
                dfs(it->first);
                tree++;
            }

        }

        printf("There are %d tree(s) and %d acorn(s).\n", tree, acorn);
    }
    return 0;
}
