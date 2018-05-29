#include <cstdio>
#include <algorithm>
#include <cmath>
#define f(x, n) for(int x = 0; x < n; x++)

using namespace std;

int edge[33000];
int sum[33000];


int main(){

    int n, num_corner, corner, res = 0;
    while(scanf("%d", &n) == 1){
        res = 0;
        num_corner = pow(2, n);

        f(i, num_corner)
            scanf("%d", &edge[i]);

        f(i, num_corner){
            sum[i] = 0;
            f(j, n){
                corner = i;
                corner ^= (1 << j);
                sum[i] += edge[corner];
            }
        }

        f(i, num_corner){
            f(j, n){
              corner = i;
              corner ^= (1 << j);
              res = max(res, sum[i]+sum[corner]);
            }
        }

        printf("%d\n", res);
    }
    return 0;
}
