#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

class SegmentTree{
private:
    vi st, A;
    int n;
    int left(int p){return p << 1;}
    int right(int p){return (p << 1) + 1;}

    void build(int p, int L, int R){
        if(L == R)
            st[p] = L;
        else{
            build(left(p), L, (L + R)/2);
            build(right(p), (L + R)/2 + 1, R);
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1] >= A[p2]) ? p1 : p2;
        }
    }

    int rmq(int p, int L, int R, int i, int j){
        if(i > R || j < L) return -1;
        if(L >= i && R <= j) return st[p];

        int p1 = rmq(left(p), L, (L + R)/2, i, j);
        int p2 = rmq(right(p), (L + R)/2 + 1, R, i, j);

        if(p1 == -1) return p2;
        if(p2 == -1) return p1;
        return (A[p1] >= A[p2]) ? p1 : p2;
    }

public:
    SegmentTree(const vi &_A){
        A = _A;
        n = (int)A.size();
        st.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    int rmq(int i, int j){return rmq(1, 0, n-1, i, j);}
};

int main(){
    int n, q, val, i, j;
    vi arr, fqarr;
    while(scanf("%d", &n)){
        if(n == 0)
            break;
        scanf("%d", &q);
        arr.clear();fqarr.clear();
        map<int, pair<int, int>> fq;

        for(int i = 0; i < n; i++){
            scanf("%d", &val);
            arr.push_back(val);
            if(fq.find(val) == fq.end())
                fq.insert(pair<int,pair<int,int>>(val, pair<int, int>(1, i)));
                //first pair is frequency
                //second pair is index of the first value in set
            else
                fq[val].first += 1;
        }

        for(int i = 0; i < n; i++)
            fqarr.push_back(fq[arr[i]].first);

        vi A(fqarr.begin(), fqarr.end());
        SegmentTree st(A);

        while(q--){
            scanf("%d %d", &i, &j);
            i--;j--;

            if(arr[i] == arr[j])
                printf("%d\n", (j - i) + 1);
            else{
                int left, right, res; left = right = res = 0;
                if(i != 0){
                    if(arr[i-1] == arr[i]){
                        left = fq[arr[i]].first - (i - fq[arr[i]].second);
                        int temp = arr[i];
                        while(temp == arr[i] && i >= 0)
                            i++;
                    }
                }

                if(j != n - 1){
                    if(arr[j] == arr[j+1]){
                        right = (j - fq[arr[j]].second) + 1;
                        int temp = arr[j];
                        while(temp == arr[j] && j < n)
                            j--;
                    }
                }

                if(i <= j)
                    res = fqarr[st.rmq(i, j)];

                if(left != 0 && right != 0){
                    int tres = max(left, right);
                    res = max(res, tres);
                }
                else if(left != 0)
                    res = max(res, left);
                else if(right != 0){
                    res = max(res, right);
                }


                printf("%d\n", res);
            }
        }
    }
}
