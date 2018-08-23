#include <cstdio>
#include <vector>
#define LSOne(S) (S & (-S))

using namespace std;

typedef vector<int> vi;

class FenwickTree {
private:
    vi ft;

public:
    FenwickTree(){}
    FenwickTree(int n){ ft.assign(n + 1, 0);}

    int rsq(int b){
        int sum = 0;
        for(; b; b -= LSOne(b)) sum += ft[b];
        return sum;
    }

    int rsq(int a, int b){
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }

    void adjust(int k, int v){
        for(; k < (int)ft.size(); k += LSOne(k)) ft[k] += v;
    }

    void print(){
       for(int i = 1; i < (int)ft.size(); i++) printf("%d ", ft[i]);
       printf("\n");
    }
};

int main(){
    int n, k, val, a, b;
    char cmd;
    while(scanf("%d %d", &n, &k) != EOF){
        vi sequence;
        sequence.assign(n+1, 0);

        FenwickTree ftNeg(n), ftZero(n);

        for(int i = 1; i <= n; i++){
            scanf("%d", &val);
            sequence[i] = val;

            if(val < 0)
                ftNeg.adjust(i, 1);
            else if(val == 0)
                ftZero.adjust(i, 1);
        }

        while(k--){
            scanf(" %c %d %d", &cmd, &a, &b);

            if(cmd == 'C'){
                if(sequence[a] < 0 && b >= 0)
                    ftNeg.adjust(a, -1);
                else if(sequence[a] >= 0 && b < 0)
                    ftNeg.adjust(a, 1);

                if(sequence[a] == 0 && b != 0)
                    ftZero.adjust(a, -1);
                else if(sequence[a] != 0 && b == 0)
                    ftZero.adjust(a, 1);

                sequence[a] = b;
            }else{
                if(ftZero.rsq(a, b))
                    printf("0");
                else if(ftNeg.rsq(a, b) % 2 == 0)
                    printf("+");
                else
                    printf("-");
            }
        }

        printf("\n");
    }
    return 0;
}
