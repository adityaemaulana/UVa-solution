#include <algorithm>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <cstdio>

using namespace std;

struct team{
    int cnt, score, num;
    int problem[10];
    bool participate, prob_solved[10];;
};

bool comp(team a, team b){
    return (a.cnt > b.cnt) || ((a.cnt == b.cnt) && (a.score < b.score)) || ((a.score == b.score) && (a.num < b.num));
}

team v[101];


using namespace std;

int main(){
    char line[100], l;// l = judge result
    int t, e, p, s; // test case, entry, problem, time score

    scanf("%d", &t);
    getchar();

    gets(line);
    while(t--){

        for(int i = 0; i < 101; i++){
            v[i].cnt = v[i].score = v[i].num = v[i].participate = 0;
            memset(v[i].problem, 0, sizeof(v[i].problem));
            memset(v[i].prob_solved, 0, sizeof(v[i].prob_solved));
        }

        while(gets(line) && strlen(line)){

            sscanf(line, "%d %d %d %c", &e, &p, &s, &l);

            v[e].participate = true;
            v[e].num = e;

            if(l == 'C' && !(v[e].prob_solved[p])){
                v[e].cnt++;
                v[e].score += s + v[e].problem[p];
                v[e].prob_solved[p] = true;
            }else if(l == 'I'){
                v[e].problem[p] += 20;
            }
        }

        sort(v, v+101, comp);

        for(int j = 0; j < 101; j++){
            if(v[j].participate)
                printf("%d %d %d\n",v[j].num, v[j].cnt, v[j].score);
        }
        if(t != 0)
            printf("\n");
    }

    return 0;
}
