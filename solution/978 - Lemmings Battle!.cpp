#include <cstdio>
#include <set>
#include <vector>

using namespace std;

multiset<int, greater<int>> blue, green;
multiset<int, greater<int>>::iterator it;

int main(){
    int n, b, sg, sb, val, cnt;
    scanf("%d", &n);
    while(n--){
        blue.clear();
        green.clear();

        scanf("%d %d %d", &b, &sg, &sb);
        while(sg--){
            scanf("%d", &val);
            green.insert(val);
        }
        while(sb--){
            scanf("%d", &val);
            blue.insert(val);
        }

        while(!green.empty() && !blue.empty()){
            cnt = 0;
            vector<int> gw, bw;

            while(cnt < b && !green.empty() && !blue.empty()){
                if(*blue.begin() > *green.begin())
                    bw.push_back(*blue.begin() - *green.begin());
                else if(*blue.begin() < *green.begin())
                    gw.push_back(*green.begin() - *blue.begin());

                blue.erase(blue.begin());
                green.erase(green.begin());
                cnt++;
            }

            for(int i = 0; i < gw.size(); i++) green.insert(gw[i]);
            for(int i = 0; i < bw.size(); i++) blue.insert(bw[i]);
        }


        if(blue.empty() && green.empty())
            printf("green and blue died\n");
        else if(blue.empty()){
            printf("green wins\n");
            for(it = green.begin(); it != green.end(); ++it)
                printf("%d\n", *it);
        }else{
           printf("blue wins\n");
           for(it = blue.begin(); it != blue.end(); ++it)
                printf("%d\n", *it);
        }

        if(n > 0)
            printf("\n");
    }
    return 0;
}
